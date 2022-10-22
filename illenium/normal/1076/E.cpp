#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 300005
#define re register
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

int n,dep[maxn],maxdep;
vector <int> mp[maxn];
struct node{int d,w;};
vector <node> p[maxn];
bool vis[maxn];
ll ans[maxn],w[maxn];

inline void dfs(int u,ll val)
{
	val+=w[dep[u]]; vis[u]=1;
	for(int i=0;i<p[u].size();i++)
	{
		node v=p[u][i];
		int p=min(dep[u]+v.d+1,n);
		w[p]-=v.w; val+=v.w;
	}
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(vis[v]) continue;
		dep[v]=dep[u]+1;
		dfs(v,val);
	}
	for(int i=0;i<p[u].size();i++)
	{
		node v=p[u][i];
		int p=min(dep[u]+v.d+1,n);
		w[p]+=v.w;
	}
	ans[u]=val;
}


int main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	int m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),d=read(),w=read();
		p[u].push_back((node){d,w});
	}
	dfs(1,0);
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}