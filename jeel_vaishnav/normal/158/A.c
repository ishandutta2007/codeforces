#include<stdio.h>
int main()
{
int n,k,count=0;
scanf("%d%d",&n,&k);
int a[n];
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
if(a[k-1]>0)
{
int i=k;
	while(a[i]==a[k-1])
	{
	i++;
	count++;
	}
	count+=k;
}
if(a[k-1]<=0)
{
int i=k-2;
	while(a[i]<=0)
	i--;
count=i+1;
}
printf("%d",count);
}