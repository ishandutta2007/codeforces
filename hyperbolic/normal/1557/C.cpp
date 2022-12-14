#include <stdio.h>
#define MOD 1000000007

long long int power(long long int a, long long int b)
{
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

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a%2==1)
		{
			long long int ans = 1;
			for(int i=1;i<=b;i++)
			{
				ans *= (power(2,a-1)+1);
				ans %= MOD;
			}
			
			printf("%lld\n",ans);
		}
		else
		{
			long long int ans = 0;
			long long int t = 1;
			for(int i=b;i>=1;i--)
			{
				ans += (t*power(2,(long long int)(i-1)*a));
				ans %= MOD;
				t *= (power(2,a-1)-1);
				t %= MOD;
			}
			ans += t, ans %= MOD;
			printf("%lld\n",ans);
		}
	}
}