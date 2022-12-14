#include <stdio.h>
#include <vector>
#define MOD 1000000007

std::vector<long long int> V;
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
		long long int a,b,c,d,e,f;
		scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f);
		
		if(e%b!=0)
		{
			printf("0\n");
			continue;
		}
		if(d<a)
		{
			printf("0\n");
			continue;
		}
		if((d-a)%b!=0)
		{
			printf("0\n");
			continue;
		}
		
		long long int R = a + b*(c-1);
		long long int r = d + e*(f-1);
		if(r>R)
		{
			printf("0\n");
			continue;
		}
		
		if(d-e < a)
		{
			printf("-1\n");
			continue;
		}
		if(r+e > R)
		{
			printf("-1\n");
			continue;
		}
		
		V.clear();
		for(long long int i=1;i*i<=b;i++)
		{
			if(b%i==0)
			{
				V.push_back(i);
				if(i*i!=b) V.push_back(b/i);
			}
		}
		
		long long int ans = 0;
		for(int i=0;i<V.size();i++)
		{
			long long int g = V[i];
			long long int s = (e/b);
			long long int t = g * s;
			if(gcd(b,t)==g)
			{
				ans += ((b/g)*(b/g))%MOD;
				ans %= MOD;
			}
		}
		printf("%lld\n",ans);
	}
}