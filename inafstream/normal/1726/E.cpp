#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

const int mod=998244353;
int fpow(int x,int y){int z=1;while(y){if(y&1){z=1ll*z*x%mod;}x=1ll*x*x%mod;y/=2;}return z;}


int f1[300005],f2[300005],fac[300005],ifac[300005];

void init()
{
	int n=300000;
	fac[0]=fac[1]=1;
	f1[0]=1;f1[1]=1;
	f2[0]=1;
	for(int i=2;i<=n;i++)
	{
		fac[i]=1ll*fac[i-1]*i%mod;
		f1[i]=(1ll*(i-1)*f1[i-2]+f1[i-1])%mod;
		f2[i]=1ll*(i-1)*f2[i-2]%mod;
	}
	ifac[n]=fpow(fac[n],mod-2);
	per(i,n) ifac[i-1]=1ll*ifac[i]*i%mod;
}

int binom(int x,int y){return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;}

int calc(int n)
{
	int ans=0,coef=1;
	for(int i=0;i*4<=n;i++)
	{
		ans=(ans+1ll*f2[i*2]*coef%mod*f1[n-i*4]%mod*binom(n-i*2,i*2))%mod;
		coef=2ll*coef%mod;
	}
	return ans;
}

int main()
{
	init();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",calc(n));
	}
	return 0;
}