#include <stdio.h>
#include <vector>
#define MOD 1000000007

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}
long long int lcm(long long int a, long long int b)
{
	return a*b/gcd(a,b);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		long long int b = 1;
		long long int ans = 0;
		
		for(int i=1;i<=100&&a;i++)
		{
			long long int g = lcm(i,b)/b;
			ans += (long long int)i*(a-(a/g));
			a /= g, b *= g;
			ans %= MOD;
		}
		
		printf("%lld\n",ans);
	}
}