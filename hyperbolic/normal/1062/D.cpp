#include <stdio.h>

long long int func(int k)
{
	long long int sum = 0;
	for(int i=2;i*i<=k;i++)
	{
		if(k%i==0)
		{
			if(i*i==k) sum += i;
			else
			{
				sum += i;
				sum += (k/i);
			}
		}
	}
	return sum;
}
int main()
{
	int a;
	scanf("%d",&a);
	long long int sum = 0;
	for(int i=2;i<=a;i++)
	{
		sum += 4*func(i);
	}
	printf("%lld",sum);
}