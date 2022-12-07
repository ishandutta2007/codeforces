#include<stdio.h>
int main()
{
int n,m;
scanf("%d%d",&n,&m);
int right=n+1,left=0;
char s1[3],s2[4],s3[6],s4[3];
int pos;
for(int i=0;i<m;i++)
{
scanf("%s",s1);
scanf("%s",s2);
scanf("%s",s3);
scanf("%s",s4);
scanf("%d",&pos);
if(s3[0]=='l'&&pos<right)
right=pos;
if(s3[0]=='r'&&pos>left)
left=pos;
}
if(right-left-1<=0)
printf("-1");
else
printf("%d",right-left-1);
}