#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 3005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

vector <int> mp[maxn];
ll dp[maxn][maxn],siz[maxn][maxn],fa[maxn][maxn],n,ans;

inline void dfs1(int rt,int u)
{
	siz[rt][u]=1;
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i]; if(v==fa[rt][u]) continue;
		fa[rt][v]=u; dfs1(rt,v); siz[rt][u]+=siz[rt][v];
	}
}

inline ll dfs2(int u,int v)
{
	if(u==v) return 0;
	if(u>u) swap(u,v); if(dp[u][v]) return dp[u][v];
	return dp[u][v]=max(dfs2(u,fa[u][v]),dfs2(v,fa[v][u]))+siz[u][v]*siz[v][u];
}

int main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v),mp[v].push_back(u);
	}
	for(int i=1;i<=n;i++) dfs1(i,i);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans=max(ans,dfs2(i,j));
	cout<<ans<<endl;
	return 0;
}