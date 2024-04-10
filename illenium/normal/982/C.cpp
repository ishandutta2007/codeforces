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
#define maxn 200005
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

vector <int> mp[maxn];
int n,siz[maxn],fa[maxn],dep[maxn],ans;
bool vis[maxn];

void dfs(int u)
{
	vis[u]=1; siz[u]=1;
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(vis[v]) continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs(v);
		siz[u]+=siz[v];
	}
}

void dfs2(int u)
{
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(v==fa[u]) continue;
		if(siz[v]%2==0) ans++;
		dfs2(v);
	}
}

int main()
{
	n=read();
	if(n%2==1) {puts("-1"); return 0;}
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	dfs(1);
	dfs2(1);
	cout<<ans;
	return 0;
}