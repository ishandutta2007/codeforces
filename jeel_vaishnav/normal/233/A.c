#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
if(n%2!=0)
printf("-1");
else
{
for(int i=1;i<=n/2;i++)
printf("%d %d ",2*i,2*i-1);
}
}