#include <stdio.h>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k =a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k ,k%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[2010];
long long int comb(int a, int b)
{
	long long int ans = fact[a];
	ans *= inv(fact[b]), ans %= MOD;
	ans *= inv(fact[a-b]), ans %= MOD;
	return ans;
}

long long int check[2010];
int x[2010],a;

long long int func(int k)
{
	if(k>a) return 1;
	if(check[k]!=-1) return check[k];
	
	if(x[k]<=0) return check[k] = func(k+1);
	else
	{
		long long int ans = func(k+1);
		for(int j=x[k]+k;j<=a;j++)
		{
			long long int t = comb(j-k-1,x[k]-1) * func(j+1);
			t%=MOD;
			ans += t, ans %= MOD;
		}
		return check[k] = ans;
	}
}

int main()
{
	fact[0] = 1;
	for(int i=1;i<=2000;i++) fact[i] = (i*fact[i-1])%MOD;
	
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) check[i] = -1;
	printf("%lld",(func(1)+MOD-1)%MOD);
}