#include<stdio.h>
int main()
{
int n,k,sum=0;
scanf("%d%d",&n,&k);
int num[n];
for(int i=0;i<n;i++)
{
scanf("%d",&num[i]);
sum+=num[i]/k;
if(num[i]%k!=0)
sum++;
}
if(sum%2==0)
sum/=2;
else
sum=sum/2+1;
printf("%d",sum);
return 0;
}