#include <stdio.h>
#define MOD 1000000007

long long int fact[1000010];
long long int power(long long int a, long long int b)
{
	if(b<0) return 0;
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}
long long int comb(int a, int b)
{
	if(a<b) return 0;
	if(b<0) return 0;
	long long int ans = fact[a];
	ans *= inv(fact[b]), ans %= MOD;
	ans *= inv(fact[a-b]), ans %= MOD;
	return ans;
}

int main()
{
	fact[0] = 1;
	for(int i=1;i<=1000000;i++) fact[i] = (i*fact[i-1])%MOD;
	
	int a,b;
	scanf("%d%d",&a,&b);
	if(b==0)
	{
		printf("%lld",power(3,a));
		return 0;
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		long long int val = 1;
		int c = (i+1)/2;
		val *= comb(b-1,b-c), val %= MOD;
		val *= comb(a-b,i-c), val %= MOD;
		val *= power(3,b-c), val %=MOD;
		val *= power(3,a-b-(i-c)), val %= MOD;
		ans += val, ans %= MOD;
	}
	printf("%lld",ans);
}