#include <stdio.h>
#define MOD 1000000007

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[1000010];
long long int comb(int s, int t)
{
	if(s<0) return 0;
	if(t<0) return 0;
	long long int ans = fact[s];
	ans *= inv(fact[t]), ans %= MOD;
	ans *= inv(fact[s-t]), ans %= MOD;
	return ans;
}

int main()
{
	fact[0] = 1;
	for(int i=1;i<=1000000;i++) fact[i] = (i*fact[i-1])%MOD;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		long long int c;
		scanf("%d%d%lld",&a,&b,&c);
		
		long long int ans = 0;
		for(int i=1;i<=b;i++)
		{
			long long int s = comb(a-i,b-i);
			long long int s2 = comb(a-i-1,b-i-1);
			s += (MOD-s2), s %= MOD;
			long long int t = power(2,i);
			t *= c, t %= MOD;
			t *= i, t %= MOD;
			s *= t, s %= MOD;
			ans += s, ans %= MOD;
		}
		ans *= inv(power(2,a)), ans %= MOD;
		printf("%lld\n",ans);
	}
}