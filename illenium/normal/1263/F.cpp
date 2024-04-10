#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2005
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

int num,n,val[maxn][maxn],l[maxn],r[maxn],siz[maxn],c[maxn],dp[maxn];
vector <int> mp[maxn];
bool vis[maxn];

inline void dfs(int u)
{
	vis[u]=1; siz[u]=1;
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(vis[v]) continue;
		dfs(v); siz[u]+=siz[v];
		l[u]=min(l[u],l[v]); r[u]=max(r[u],r[v]);
	}
}

int main()
{
	int num=read(),n=read();
	for(int i=2;i<=n;i++)
	{
		int x=read();
		mp[x].push_back(i); mp[i].push_back(x);
	}
	for(int i=1;i<=n;i++) l[i]=inf;
	for(int i=1;i<=num;i++)
	{
		int x=read();
		l[x]=i; r[x]=i;
	}
	dfs(1);
	//for(int i=1;i<=n;i++) cout<<l[i]<<" "<<r[i]<<" "<<siz[i]<<endl; cout<<endl<<endl;
	for(int i=2;i<=n;i++) val[l[i]][r[i]]=max(val[l[i]][r[i]],siz[i]);
	
	for(int i=1;i<=n;i++) mp[i].clear(),vis[i]=0,siz[i]=0;
	n=read();
	for(int i=2;i<=n;i++)
	{
		int x=read();
		mp[x].push_back(i); mp[i].push_back(x);
	}
	for(int i=1;i<=n;i++) l[i]=inf,r[i]=0;
	for(int i=1;i<=num;i++)
	{
		int x=read();
		l[x]=i; r[x]=i;
	}
	dfs(1);
	//for(int i=1;i<=n;i++) cout<<l[i]<<" "<<r[i]<<" "<<siz[i]<<endl; cout<<endl<<endl;
	for(int i=2;i<=n;i++) val[l[i]][r[i]]=max(val[l[i]][r[i]],siz[i]);
	for(int i=1;i<=num;i++)
	{
		for(int j=0;j<=i-1;j++)
			dp[i]=max(dp[i],dp[j]+val[j+1][i]);
	}
	
//	for(int i=1;i<=num;i++)
//	{
//		for(int j=i;j<=num;j++)
//			cout<<i<<" "<<j<<" "<<val[i][j]<<endl;
//	}
//	cout<<endl<<endl;
//	
	
	cout<<dp[num]<<endl;
	return 0;
}