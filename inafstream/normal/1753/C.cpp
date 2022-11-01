#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

const int mod=998244353;
int inv(int x)
{
	int z=1,y=mod-2;
	while(y){if(y&1)z=1ll*z*x%mod;x=1ll*x*x%mod;y/=2;}
	return z;
}

int n;
int a[200005];

void solve()
{
	scanf("%d",&n);
	int s=0;
	rep(i,n)
	{
		scanf("%d",&a[i]);
		s+=!a[i];
	}
	int m=1ll*n*(n-1)/2%mod,c=0,ans=0;
	rep(i,s) c+=(a[i]==1);
	per(i,c)
	{
		int t=1ll*i*i%mod;
		ans=(ans+1ll*m*inv(t))%mod;
	}
	printf("%d\n",ans);
}



int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}