#include <stdio.h>

long long int x[200010];
long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}
long long int abs(long long int k)
{
	return k>0?k:-k;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		long long int b;
		scanf("%d%lld",&a,&b);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		long long int g = 0;
		for(int i=1;i<a;i++) g = gcd(g,abs(x[i]-x[a]));
		for(int i=1;i<=a;i++)
		{
			if((b-x[i])%g==0)
			{
				printf("YES\n");
				goto u;
			}
		}
		printf("NO\n");
		u:;
	}
}