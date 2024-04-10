#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,m,ind[maxn],dp[maxn],x[maxn];
vector <int> mp[maxn],ans;

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); m=read();
		rep(i,1,n) mp[i].clear(),x[i]=0,dp[i]=0; ans.clear();
		rep(i,1,m)
		{
			int u=read(),v=read();
			ind[u]++; mp[v].pb(u);
		}
		rep(i,1,n)
		{
			for(int j=0;j<mp[i].size();j++)
			{
				int v=mp[i][j];
				if(!x[v]) dp[i]=max(dp[i],dp[v]+1);
			}
			if(dp[i]==2) x[i]=1,ans.pb(i);
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]); puts("");
	}
	return 0;
}