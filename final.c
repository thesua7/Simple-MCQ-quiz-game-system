#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<windows.h>



int n=0,score=0,chose,highest_score;

void help(){
    int ch;
    system("cls");
    printf("(1)You have to choose in which mode you want to go.\n\n(2)If you select ADMIN mode you have to submit your questions along with it's 4 options and a right answer.\n\n(3)If you select PLAYER mode you have to answer the questions and it will count 1 for each questions if your question is correct.\n\n(4)Player will get 50 50 options as a player helpline,If the player corrects the half amount of total questions.\n\n(5)In highest score option it will show the highest score of this quiz.\n\n\n\n\n\n");
    printf("Press '1' to go back to main menu\nOr press '0' to exit \n\n\n\n\n\n\n\n\n\n\n");
    scanf("%d", &ch);
    if(ch==1)
    {
        system("cls");

    }
    else if(ch==0)
    {
        printf("EXIT");
    }
}


void main_menu()
{


    printf("\t\t\t\t\t**************************\n\t\t\t\t\t********* WELCOME ********\n\t\t\t\t\t*********** TO ***********\n\t\t\t\t\t******** Quiz Exam *******\n\t\t\t\t\t**************************\n\n\n\n\n\n");
    printf("\t\t\t\t     ~~ENTER ANY KEY TO GO ON A MODE~~\n\n\n\n\n");
    printf("\t\t\t\t\t(1) ADMIN\n\n");
    printf("\t\t\t\t\t(2) STUDENT\n\n");
    printf("\t\t\t\t\t(3) VIEW HIGHEST SCORE\n\n");
    printf("\t\t\t\t\t(4) HELP\n\n");
    printf("\t\t\t\t\t(5) EXIT\n\n\n\n\n");

    scanf("%d", &chose);

}

void Admin_editor()
{
system("cls");
int i,j;
char r_ans;
char str[50][5000];
char op[4][50];
char filename_derectory[64];
char filename_qus[64];
char filename_op[64];
char filename_r_ans[64];

FILE *out_qus,*out_op,*out_r_ans;


for(i=0;i<n;i++)
{
    fflush(stdin);

    sprintf(filename_derectory, "Question(%d)", i+1);
    CreateDirectory(filename_derectory,NULL);

    sprintf(filename_qus, "%s\\Question%d.txt",filename_derectory, i+1);
    out_qus = fopen( filename_qus, "w");

    printf("Enter Question\n\n%d. ",i+1);
    gets(str[i]);

    fprintf(out_qus,"%d.%s\n",i+1,str[i]);

    printf("Enter options(4)\n\n");
    for(j=0;j<4;j++)
    {
        char a='a';
        a=(char)a+j;

        sprintf(filename_op,"%s\\Question(%d)-Option(%c).txt",filename_derectory,i+1,a);
        out_op=fopen(filename_op,"w");

        printf("%c.", a);
        gets(op[j]);
        fprintf(out_op,"%c.%s\n",a,op[j]);


    }
    printf("Enter Right answer(EX. a):  ");
    scanf("%c", &r_ans);

    sprintf(filename_r_ans,"%s\\question(%d)'s right answer.txt",filename_derectory,i+1);
    out_r_ans=fopen(filename_r_ans,"w");
    fprintf(out_r_ans,"%c",r_ans);


    fclose(out_op);
    fclose(out_qus);
    fclose(out_r_ans);
    printf("\n\n");

}

}

void quiz_result()
{

system("cls");
int i,j,high;
char r_ans;
char student_r_ans;
FILE *out_qus,*out_op,*out_r_ans,*highestScore;
FILE *out_op1,*out_op2,*out_op3,*out_op4;

char str[50][5000];
char op[4][50];
char op50[4][50];
char filename_derectory[64];
char filename_qus[64];
char filename_op[64];
char filename_r_ans[64];


for(i=0;i<n;i++)
{

    fflush(stdin);


    sprintf(filename_derectory, "Question(%d)", i+1);


    sprintf(filename_qus, "%s\\Question%d.txt",filename_derectory, i+1);
    out_qus = fopen( filename_qus, "r");


    if(score==n/2)
{

    printf("\nHURRAH!!!!!!\n\nYOU HAVE GOT A 50/50 (As a player helpline)!!!!!!!!\n\n\n");
    if(fgets(str[i],5000,out_qus)!=NULL){
        printf("\n%s\n",str[i]);
    }

    sprintf(filename_r_ans,"%s\\question(%d)'s right answer.txt",filename_derectory,i+1);
    out_r_ans=fopen(filename_r_ans,"r");
    fscanf(out_r_ans,"%c",&r_ans);

    if(r_ans=='a'||r_ans=='b'){

       sprintf(filename_op,"%s\\Question(%d)-Option(a).txt",filename_derectory,i+1);
       out_op1=fopen(filename_op,"r");
       fgets(op50[0],500,out_op1);
       printf("%s\n",op50[0]);
       fclose(out_op1);

       sprintf(filename_op,"%s\\Question(%d)-Option(b).txt",filename_derectory,i+1);
       out_op2=fopen(filename_op,"r");
       fgets(op50[1],500,out_op2);
       printf("%s\n",op50[1]);
       fclose(out_op2);

    }

    if(r_ans=='c'||r_ans=='d'){

       sprintf(filename_op,"%s\\Question(%d)-Option(c).txt",filename_derectory,i+1);
       out_op3=fopen(filename_op,"r");
       fgets(op50[2],500,out_op3);
       printf("%s\n",op50[2]);
       fclose(out_op3);

       sprintf(filename_op,"%s\\Question(%d)-Option(d).txt",filename_derectory,i+1);
       out_op4=fopen(filename_op,"r");
       fgets(op50[3],500,out_op4);
       printf("%s\n",op50[3]);
       fclose(out_op4);

    }


    printf("Enter Your answer(EX. a):  ");
    scanf("%c", &student_r_ans);

    if(student_r_ans==r_ans)
    {
        score++;
        printf("\n\n\ncorrect!!\n\n\n");
    }
    else
    {
        printf("\n\n\nWORNG!!!!\n\n\n");

    }

     fclose(out_r_ans);


}




else{

    if(fgets(str[i],5000,out_qus)!=NULL)
    {
            printf("%s\n",str[i]);
    }
    else
    {
        printf("\n\nError!!!!");
    }


    for(j=0;j<4;j++)
    {
        fflush(stdin);
        char c, a='a';
        a=(char)a+j;

        sprintf(filename_op,"%s\\Question(%d)-Option(%c).txt",filename_derectory,i+1,a);
        out_op=fopen(filename_op,"r");

        fgets(op[j],500,out_op);
        printf("%s\n",op[j]);
    }

    printf("Enter Your answer(EX. a):  ");
    scanf("%c", &student_r_ans);

    sprintf(filename_r_ans,"%s\\question(%d)'s right answer.txt",filename_derectory,i+1);
    out_r_ans=fopen(filename_r_ans,"r");
    fscanf(out_r_ans,"%c",&r_ans);
    if(student_r_ans==r_ans)
    {
        score++;
        printf("\n\n\ncorrect!!\n\n\n");
    }
    else
    {
        printf("\n\n\nWORNG!!!!\n\n\n");
    }

  }
}
    fclose(out_op);
    fclose(out_qus);
    fclose(out_r_ans);
    printf("\n\nTotal Score is:   %d\n\n\n",score);

    highestScore=fopen("HIGHESTSCORE.txt","w");
    fscanf(highestScore,"%d",&highest_score);
    if(score>highest_score)
    {
        printf("YOU HAVE CREAT A NEW RECORD\n\n");
        highest_score=score;
        fprintf(highestScore,"%d",highest_score );
        fclose(highestScore);

    }
    else if(score<highest_score)
    {
        fprintf(highestScore,"%d",highest_score);
        fclose(highestScore);
    }


    score=0;

}




main(){


swic:
    {
        int c;

FILE *amount_qus;
main_menu();


if(chose==1)
{
    amount_qus=fopen("Amount of question.txt","w");
    system("cls");
    printf("Enter the Amount of Question you want: ");
    scanf("%d",&n);
    fprintf(amount_qus,"%d",n);
    Admin_editor();
     printf("\n\n\n\n\n\n THANKS YOUR QUESTIONS ARE SUMBITTED! :)\n\n\n\n\n\n");
    fclose(amount_qus);




}

else if(chose==2)

{

    amount_qus=fopen("Amount of question.txt","r");
    fscanf(amount_qus,"%d", &c);
    n=c;
    fclose(amount_qus);
    quiz_result();

    int k;
    printf("Press '1' to go back to main menu\nOr press '0' to exit \n\n\n\n\n\n\n\n\n\n\n");
    scanf("%d",&k);
     if(k==1)
    {
        system("cls");
        goto swic;

    }
    else if(k==0)
    {
        printf("EXIT");
    }


}
else if(chose==3)
{
    system("cls");
    FILE *high_s;
    high_s=fopen("HIGHESTSCORE.txt","r");
    int h_s;
    fscanf(high_s,"%d",&h_s);
    printf("\n\n\n\n\t\t\t        **************** THE HIGHEST SCORE IS :: %d ****************\n\n\n\n\n\n\n\n\n",h_s);
    fclose(high_s);


    int v;
    printf("Press '1' to go back to main menu\nOr press '0' to exit \n\n\n\n\n\n\n\n\n\n\n");
    scanf("%d",&v);
     if(v==1)
    {
        system("cls");
        goto swic;

    }
    else if(v==0)
    {
        printf("EXIT");
    }



}
else if(chose==4)
{
    help();
    goto swic;
}


else {
    printf("EXIT");
}
return 0;
}
}

