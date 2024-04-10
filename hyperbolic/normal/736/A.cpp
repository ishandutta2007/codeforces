#include <stdio.h>

long long int check[100010];
long long int func(int k)
{
	if(k==0) return 1;
	if(k==1) return 2;
	if(check[k]) return check[k];
	return check[k] = func(k-1)+func(k-2);
}

int main()
{
	long long int a;
	scanf("%lld",&a);
	
	for(int i=1;i<=a;i++)
	{
		if(func(i)>a)
		{
			printf("%d",i-1);
			return 0;
		}
	}
}