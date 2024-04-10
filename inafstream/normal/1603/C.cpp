#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

const int mod=998244353;

const int S=320;

int n,a[100005];
int f[100005][321],g[100005][321];

int calc(int x,int y)
{
	if(x==0) return 0;
	int t=(a[x]+y-1)/y;
	int s=(a[x]/t<=S?f[x][a[x]/t]:g[x][t]);
	s=(s+1ll*(t-1)*x)%mod;
	return s;
}

void solve()
{
	int i,j;
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	
	rep(i,n)
	{
		memset(f[i],0,sizeof(f[i]));
		memset(g[i],0,sizeof(g[i]));
	}
	
	int ans=0;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=S&&j<=a[i];j++)
		{
			f[i][j]=calc(i-1,j);
		}
		for(j=1;a[i]/j>S;j++)
		{
			g[i][j]=calc(i-1,a[i]/j);
		}
		ans=(ans+(a[i]<=S?f[i][a[i]]:g[i][1]))%mod;
	}
	
	printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}