#include <stdio.h>
#define MOD 998244353

long long int power(long long int a,long long int b)
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

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int C = 0;
		for(int i=1;i<=a;i++) if(x[i]==0) C++;
		int r = 0;
		for(int i=1;i<=C;i++) if(x[i]==1) r++;
		
		long long int ans = (long long int)a*(a-1)/2;
		ans %= MOD;
		long long int ans2 = 0;
		for(int i=1;i<=r;i++)
		{
			ans2 += inv(((long long int)i*i)%MOD);
			ans2 %= MOD;
		}
		printf("%lld\n",(ans*ans2)%MOD);
	}
}