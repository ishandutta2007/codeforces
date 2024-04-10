#include <stdio.h>
#include <algorithm>
#define MOD 1000000007

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k;
		b/=2;
		k%=MOD;
	}
	return ans;
}

long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[300010];
long long int comb(int s, int t)
{
	if(s<t) return 0;
	long long int ans = fact[s];
	ans *= inv(fact[s-t]), ans %= MOD;
	ans *= inv(fact[t]) , ans %= MOD;
	return ans;
}

int x[200010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=300000;i++) fact[i] = (fact[i-1]*i)%MOD;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		std::sort(x+1,x+a+1);
		
		int p = 1;
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			while(p<=a && (x[p]-x[i])<=c) p++;
			ans += comb(p-i-1,b-1);
			ans %= MOD;
		}
		printf("%lld\n",ans);
	}
}