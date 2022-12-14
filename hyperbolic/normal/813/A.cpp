#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	
	int sum = 0;
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		sum += b;
	}
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(c<=sum&&sum<=d)
		{
			printf("%d",sum);
			return 0;
		}
		if(sum<c)
		{
			printf("%d",c);
			return 0;
		}
	}
	printf("-1");
}