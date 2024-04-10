#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
#define inf 1e18
#define ins insert
#define pb push_back
#define vi vector <int>
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

ll dp[505][505],d[maxn],a[maxn],n,l,k;

int main()
{
	n=read(); l=read(); k=read();
	rep(i,1,n) d[i]=read(); rep(i,1,n) a[i]=read(); d[++n]=l;
	rep(i,1,n) rep(j,0,n) dp[i][j]=inf; dp[1][0]=0;
	rep(i,2,n)
	{
		rep(j,0,i-1)
		{
			rep(k,1,i-1)
			{
				int tmp=i-k-1; if(j<tmp) continue;
				dp[i][j]=min(dp[i][j],dp[k][j-tmp]+(d[i]-d[k])*a[k]);
			}
		}
	}
	ll ans=inf;
	rep(i,0,k) ans=min(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}