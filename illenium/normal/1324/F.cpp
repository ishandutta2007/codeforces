#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,col[maxn],dp[maxn];
vector <int> mp[maxn];

inline void dfs(int u,int fa)
{
	int tot=0;
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(v==fa) continue;
		dfs(v,u); if(dp[v]>0) tot+=dp[v];
	}
	dp[u]+=tot;
}

inline void dfs2(int u,int fa)
{
	int tot=0;
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(v==fa) continue;
		if(dp[v]>=0) dp[v]=max(dp[v],dp[u]);
		else dp[v]=max(-1,dp[u]-1);
		dfs2(v,u);
	}
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) col[i]=read();
	for(int i=1;i<=n;i++) if(col[i]==0) dp[i]=-1; else dp[i]=1;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v),mp[v].push_back(u);
	}
	dfs(1,0); dfs2(1,0);
	for(int i=1;i<=n;i++) cout<<dp[i]<<" "; cout<<endl;
	return 0;
}