#include <stdio.h>
#define MOD 1000000007

long long int inv(long long int k)
{
	long long int ans = 1;
	long long int p = MOD-2;
	long long int s = k;
	while(p)
	{
		if(p%2==1) ans*=s,ans%=MOD;
		s*=s,s%=MOD;
		p/=2;
	}
	return ans;
}
long long int pow(long long int k, long long int t)
{
	long long int ans = 1;
	long long int p = t;
	long long int s = k;
	while(p)
	{
		if(p%2==1) ans*=s,ans%=MOD;
		s*=s,s%=MOD;
		p/=2;
	}
	return ans;
}
long long int func(long long int s, long long int t)
{
	if(s<t) return 0;
	long long int comb = 1;
	long long int sign;
	if(t%2==1) sign = -1;
	else sign = 1;
	
	long long int ans = 0;
	for(long long int i=1;i<=t;i++)
	{
		sign*=(-1);
		comb *= (t-i+1), comb%=MOD;
		comb *= inv(i), comb %= MOD;
		long long int m = (comb*pow(i,s))%MOD;
		ans += sign*m%MOD;
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
	}
	long long int div = 1;
	for(long long int i=1;i<=t;i++) div*=i,div%=MOD;
	return (ans * inv(div)) % MOD;
}

int main()
{
	long long int a,b;
	long long int sum = 0;
	scanf("%lld%lld",&a,&b);
	for(long long int i=1;i<=a;i++)
	{
		long long int c;
		scanf("%lld",&c);
		sum += c;
		sum%=MOD;
	}
	if(b==1) printf("%lld",(a*sum)%MOD);
	else if(a==b) printf("%lld",sum%MOD);
	else printf("%lld",(((func(a-1,b-1)+(a+b-1)*func(a-1,b))%MOD)*sum)%MOD);
}