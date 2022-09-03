#include<stdio.h>

int a[50];

int main()
{
int i,n,k;
scanf("%d%d",&n,&k);
k--;
for(i=0;i<n;i++)scanf("%d",&a[i]);
for(i=0;(i<k)&&(a[i]>0);i++);
if(a[i]>0)
{
for(i=k;(i<n)&&(a[i]==a[k]);i++);
printf("%d",i);
}
else printf("%d",i);
}