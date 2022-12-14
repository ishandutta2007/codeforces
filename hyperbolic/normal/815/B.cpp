#include <stdio.h>
#define MOD 1000000007

long long int fact[200010];
long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k,ans%=MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}
long long int comb(int s, int t)
{
	long long int ans = fact[s];
	ans *= inv(fact[s-t]), ans%=MOD;
	ans *= inv(fact[t]), ans %= MOD;
	return ans;
}

long long int x[200010],y[200010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=200000;i++) fact[i] = fact[i-1]*i, fact[i]%=MOD;
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	
	if(a==1)
	{
		printf("%lld",x[1]);
		return 0;
	}
	
	if(a%2==1)
	{
		int sign = 1;
		for(int i=1;i<a;i++) y[i] = x[i] + sign*x[i+1], sign*=-1;
		for(int i=1;i<a;i++) x[i] = (y[i]+MOD)%MOD;
		a--;
	}
	
	long long int ans = 0;
	if(a%4==2)
	{
		int t = (a-2)/2;
		for(int i=1;i<=a;i+=2)
		{
			ans += (x[i]*comb(t,(i-1)/2))%MOD;
			ans %= MOD;
			ans += (x[i+1]*comb(t,(i-1)/2))%MOD;
			ans %= MOD;
		}
	}
	else
	{
		int t = (a-2)/2;
		for(int i=1;i<=a;i+=2)
		{
			ans += (x[i]*comb(t,(i-1)/2))%MOD;
			ans %= MOD;
			ans -= (x[i+1]*comb(t,(i-1)/2))%MOD;
			ans += MOD;
			ans %= MOD;
		}
	}
	printf("%lld",ans);
}