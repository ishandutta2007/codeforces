#include <stdio.h>
#include <vector>
#define MOD 998244353

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

long long int lcm(long long int a, long long int b)
{
	return (a/gcd(a,b))*b;
}

std::vector<int> V[300010];
int check[300010],check2[300010];
int main()
{
	for(int i=2;i<=300000;i++)
	{
		if(check[i]==0)
		{
			check2[i] = 1;
			for(int j=i;j<=300000;j+=i) check[j] = 1;
		}
	}
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	
	long long int m = 1;
	long long int ans = 0;
	long long int S = 1;
	for(int i=1;i<=a;i++)
	{
		if(check2[i]) m*=i;
		if(m>b) break;
		S *= (b/m)%MOD, S %= MOD;
		ans += S, ans %= MOD;
	}
	
	b%=MOD;
	long long int ans2 = 0;
	long long int S2 = 1;
	for(int i=1;i<=a;i++)
	{
		S2 *= b, S2 %= MOD;
		ans2 += S2, ans2 %= MOD;
	}
	
	printf("%lld",(ans2-ans+MOD)%MOD);
}