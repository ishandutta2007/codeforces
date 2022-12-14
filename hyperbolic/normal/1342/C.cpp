#include <stdio.h>

int x[50010];
int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}
int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}

int a,b;
long long int func(long long int k)
{
	long long int s = k/lcm(a,b);
	long long int t = k%lcm(a,b);
	
	return k - ((s-1)*a + (t>=a?a:t+1));
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int c;
		scanf("%d%d%d",&a,&b,&c);
		if(a<b)
		{
			int t = b;
			b = a;
			a = t;
		}
		int d = b/gcd(a,b);
		
		for(int i=1;i<=c;i++)
		{
			long long int e,f;
			scanf("%lld%lld",&e,&f);
			printf("%lld ",func(f) - func(e-1));
		}
		printf("\n");
	}
}