#include <stdio.h>
#include <algorithm>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k ,k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[300010];
long long int comb(int a, int b)
{
	long long int ans = fact[a];
	ans *= inv(fact[b]), ans%=MOD;
	ans *= inv(fact[a-b]), ans %= MOD;
	return ans;
}

long long int x[300010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=300000;i++) fact[i] = fact[i-1]*i, fact[i]%=MOD;
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=2*a;i++) scanf("%lld",&x[i]);
	std::sort(x+1,x+2*a+1);
	long long int sum = 0;
	for(int i=1;i<=a;i++) sum += (MOD-x[i]), sum %= MOD;
	for(int i=a+1;i<=2*a;i++) sum += x[i], sum %= MOD;
	printf("%lld",(sum*comb(2*a,a))%MOD);
}