#include<stdio.h>
int main()
{
int n,m;
scanf("%d%d",&n,&m);
int bus=m,count=1;
for(int i=0;i<n;i++)
{
	int num;
	scanf("%d",&num);
	if(num<=bus)
	bus-=num;
	else
	{
	bus=m-num;
	count++;
	}
}
printf("%d",count);
return 0;
}