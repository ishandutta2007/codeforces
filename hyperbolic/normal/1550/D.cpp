#include <stdio.h>
#define MOD 1000000007

long long int power(long long int a , long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans %= MOD;
		k*=k, k%=MOD;
		b/=2;
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
	ans *= inv(fact[b]), ans %= MOD;
	ans *= inv(fact[a-b]), ans %= MOD;
	return ans;
}

int main()
{
	fact[0] = 1;
	for(int i=1;i<=300000;i++) fact[i] = (i*fact[i-1])%MOD;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		
		int count = 0;
		long long int R = c-a;
		long long int L = b-1;
		long long int limit = R<(-L)?R:(-L);
		
		long long int ans = limit * comb(a,a/2);
		ans %= MOD;
		if(a%2==1) ans*=2, ans %= MOD;
		
		for(int i=1;i<=a;i++)
		{
			long long int l = limit+i;
			if((b+l)-(c-l)>=2) break;
			long long int L = b+l;
			if(L<=0) L = 1;
			long long int R = c-l;
			if(R>a) R = a;
			long long int s1 = R-L+1;
			long long int s2 = a-R;
			long long int s3 = a-s1-s2;
			if(s2<=s3)
			{
				if(s1+s2<s3-1) continue;
				else if(s1+s2==s3-1)
				{
					ans++, ans %= MOD;
					continue;
				}
				long long int t = s1-(s3-s2);
				if(t%2==0) ans += comb(s1,(s3-s2)+t/2), ans %= MOD;
				else
				{
					ans += comb(s1,(s3-s2)+(t/2)), ans %= MOD;
					ans += comb(s1,(s3-s2)+((t+1)/2)), ans %= MOD;
				}
			}
			else
			{
				if(s1+s3<s2-1) continue;
				else if(s1+s3==s2-1)
				{
					ans++, ans %= MOD;
					continue;
				}
				long long int t = s1-(s2-s3);
				if(t%2==0) ans += comb(s1,(s2-s3)+t/2), ans %= MOD;
				else
				{
					ans += comb(s1,(s2-s3)+(t/2)), ans %= MOD;
					ans += comb(s1,(s2-s3)+((t+1)/2)), ans %= MOD;
				}
			}
		}
		printf("%lld\n",ans);
	}
}