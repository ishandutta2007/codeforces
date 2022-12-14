#include <stdio.h>

int main()
{
	long long int a;
	scanf("%lld",&a);
	if(a%2==0) printf("%lld",a/2);
	else
	{
		for(long long int i=2;i*i<=a;i++)
		{
			if(a%i==0)
			{
				printf("%lld",(a-i)/2+1);
				return 0;
			}
		}
		printf("1");
	}
}