#include <stdio.h>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k =a;
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

int x[1000010];
long long int y[1000010];
long long int DP[1000010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) y[i] = x[i] * inv(power(2,i)), y[i] %= MOD;
	for(int i=1;i<=a;i++) y[i] += y[i-1], y[i] %= MOD;
	
	DP[0] = 0;
	for(int i=1;i<=a;i++) DP[i] = (2*DP[i-1]+ power(2,i)*y[i])%MOD;
	
	printf("%lld",(DP[a]-DP[a-1]+MOD)%MOD);
}