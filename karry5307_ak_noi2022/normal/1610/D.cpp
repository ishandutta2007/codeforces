#include<cstdio>
using namespace std;
const long long mod = 1000000007;

int n;
long long a[200005],fac[200005];
long long qpow(long long x,long long y)
{
	long long res=1;
	while(y)
	{
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
long long Inv(long long x)
{
	return qpow(x,mod-2);
}
long long C(long long x,long long y)
{
	if(y>x) return 0;
	return fac[x]*Inv(fac[y])%mod*Inv(fac[x-y])%mod;
}
long long cnt[50],suf[50],ans;
int main()
{
	scanf("%d",&n);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	for(int i=1;i<=n;i++)
	{
		int tmp=0;
		scanf("%d",&a[i]);
		while(a[i]%2==0)
		{
			a[i]/=2;
			tmp++;
		}
		cnt[tmp]++;
	}
	for(int i=40;i>=1;i--)
	{
		suf[i]=suf[i+1]+cnt[i];
	}
	for(int i=0;i<=40;i++)
	{
		for(int j=0;j<=cnt[i];j++)
		{
			if((j%2==0 || i==0) && j!=0)
			{
				ans+=C(cnt[i],j)*qpow(2,suf[i+1])%mod;
				ans%=mod;
			}
		}
	}
	printf("%lld\n",ans);
}