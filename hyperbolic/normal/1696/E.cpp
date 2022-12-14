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
	if(s<t) return 0;
	long long int ans = fact[s];
	ans *= inv(fact[t]), ans %= MOD;
	ans *= inv(fact[s-t]), ans %= MOD;
	return ans;
}

int main()
{
	fact[0] = 1;
	for(int i=1;i<=1000000;i++) fact[i] = (i*fact[i-1])%MOD;
	int a;
	scanf("%d",&a);
	long long int ans = 0;
	for(int i=1;i<=a+1;i++)
	{
		int b;
		scanf("%d",&b);
		ans += comb(b+(i-1),i), ans %= MOD;
	}
	printf("%lld",ans);
}