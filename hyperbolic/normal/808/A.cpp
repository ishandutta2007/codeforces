#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	
	long long int C = 1;
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=9;j++)
		{
			if(j*C<=a);
			else
			{
				printf("%lld",j*C-a);
				return 0;
			}
		}
		C*=10;
	}
}