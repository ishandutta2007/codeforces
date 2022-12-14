#include <stdio.h>

int func(long long int k)
{
	if(k==0) return 0;
	return k%10 + func(k/10);
}
long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		for(long long int i=a;;i++)
		{
			long long int b = func(i);
			long long int g = gcd(i,b);
			if(g>1)
			{
				printf("%lld\n",i);
				break;
			}
		}
	}
}