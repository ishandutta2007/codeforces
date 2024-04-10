#include<stdio.h>
int i,sb;
int main()
{
scanf("%d",&sb);
for(i=2;i<=sb;i++)
{
	if(sb%i==0)
	{
		printf("%d",i);
		printf("%d",sb/i);
		return 0;
	}
	else
	{
	}
	
}
printf("1%d",sb);
return 0;
}