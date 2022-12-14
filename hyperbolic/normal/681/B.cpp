#include <stdio.h>

int main()
{
	int s;
	scanf("%d",&s);
	
	for(int i=0;i<=1000;i++)
	{
		for(int j=0;j<=10000;j++)
		{
			if(1234567 * i + 123456 * j > s) break;
			if((s - 1234567 * i - 123456 * j)%1234==0)
			{
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
}