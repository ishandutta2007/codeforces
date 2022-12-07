#include<stdio.h>
int main()
{
int n,k,term=0,num=0;
scanf("%d%d",&n,&k);
int time=240-k;
while(n>=0&&time>=0)
{
term+=5;
n--;
time-=term;
num++;
}
printf("%d",num-1);
}