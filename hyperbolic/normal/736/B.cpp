#include <stdio.h>

int isPrime(int k)
{
	for(int i=2;i*i<=k;i++) if(k%i==0) return 0;
	return 1;
}

int main()
{
	int a;
	scanf("%d",&a);
	if(a==2)
	{
		printf("1");
		return 0;
	}
	if(a%2==0)
	{
		printf("2");
		return 0;
	}
	if(a==3)
	{
		printf("1");
		return 0;
	}
	if(isPrime(a))
	{
		printf("1");
		return 0;
	}
	if(isPrime(a-2))
	{
		printf("2");
		return 0;
	}
	printf("3");
}