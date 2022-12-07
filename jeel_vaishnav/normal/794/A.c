#include<stdio.h>
int main()
{
int a,b,c,n;
scanf("%d%d%d%d",&a,&b,&c,&n);
int note,count=0;
for(int i=0;i<n;i++)
{
scanf("%d",&note);
if(note>b&&note<c)
count++;
}
printf("%d",count);
}