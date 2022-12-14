#include <stdio.h>

long long int gcd(long long int A, long long int B)
{
	return A?gcd(B%A,A):B;
}

int main()
{
	long long int a;
	scanf("%lld",&a);
	long long int ans = 0;
	for(long long int i=1;i*i<=a;i++)
	{
		if(a%i==0)
		{
			long long int A = i;
			long long int B = a/i;
			if(gcd(A,B)==1) ans = ans>A?ans:A;
		}
	}
	printf("%lld %lld",ans,a/ans);
}