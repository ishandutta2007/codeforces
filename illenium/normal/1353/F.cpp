#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 105
#define inf 1e18
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,m,a[maxn][maxn],x[maxn][maxn],dp[maxn][maxn];

int main()
{
	int T=read();
	while(T--)
	{
		n=read(),m=read(); rep(i,1,n) rep(j,1,m) a[i][j]=read(); ll ans=inf;
		rep(p,1,n) rep(q,1,m)
		{
			rep(i,0,n) rep(j,0,m) x[i][j]=inf,dp[i][j]=inf; dp[0][1]=0;
			rep(i,1,n) rep(j,1,m)
			{
				int tmp=abs(i-p)+abs(j-q);
				if(i<=p&&j<=q)
				{
					if(a[p][q]-tmp>a[i][j]) x[i][j]=inf;
					else x[i][j]=(a[i][j]-a[p][q]+tmp);
				}
				else if(i>=p&&j>=q)
				{
					if(a[p][q]+tmp>a[i][j]) x[i][j]=inf;
					else x[i][j]=(a[i][j]-a[p][q]-tmp);
				}
			}
			rep(i,1,n) rep(j,1,m)
			{
				if(x[i][j]==inf) continue;
				dp[i][j]=min(dp[i][j-1],dp[i-1][j]);
				if(dp[i][j]!=inf) dp[i][j]+=x[i][j];
			}
			ans=min(ans,dp[n][m]);
		}
		cout<<ans<<endl;
	}
	return 0;
}