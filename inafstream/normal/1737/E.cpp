#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

const int mod=1e9+7;
int pw[1000005],ipw[1000005];
int n,m;
int tag[1000005],ans[1000005];

void solve()
{
	scanf("%d",&n);
	rep(i,n) tag[i]=0;
	int cur=1,sum=0;
	per(i,n)
	{
		if(i==1)
		{
			if(n==1) ans[i]=2; else ans[i]=0;
			break;
		}
		if(i!=n) cur=2ll*cur%mod;
		cur=(cur-tag[i]+mod)%mod;
		int coef=1;
		int pos=i/2;
		if(i==n) coef=2ll*coef%mod;
		coef=1ll*coef*cur%mod;

		tag[pos]=(tag[pos]+coef)%mod;
		coef=1ll*coef*pw[pos]%mod;
		if(pos==0) coef=2ll*coef%mod;
		ans[i]=coef;
	}
	rep(i,n) sum=(sum+ans[i])%mod;
	assert(sum==pw[n]);
	rep(i,n) printf("%lld\n",1ll*ans[i]*ipw[n]%mod);
}

int main()
{
	pw[0]=ipw[0]=1;
	rep(i,1000000)
	{
		pw[i]=2ll*pw[i-1]%mod;
		ipw[i]=1ll*ipw[i-1]*(mod+1)/2%mod;
	}

	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}