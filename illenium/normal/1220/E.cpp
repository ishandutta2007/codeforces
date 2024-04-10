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

int n,m,ind[maxn],s,w[maxn],ind2[maxn];
vector <int> mp[maxn];
queue <int> q;
bool vis[maxn],vis2[maxn];
ll ans,f[maxn],tmp,maxf;

inline ll dfs(int u)
{
	if(f[u]) return f[u];
	f[u]=w[u];
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(vis[v]==0) continue;
		f[u]=max(f[u],dfs(v)+w[u]);
	}
	return f[u];
}

int main()
{
	n=read(); m=read();
	for(int i=1;i<=n;i++) w[i]=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v);
		mp[v].push_back(u);
		ind[u]++; ind[v]++;
		ind2[u]++; ind2[v]++;
	}
	s=read();
	if(n==1)
	{
		cout<<w[1]<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) if(ind[i]==1&&i!=s) q.push(i);
	while(!q.empty())
	{
		int u=q.front(); q.pop(); vis[u]=1;
		for(int i=0;i<mp[u].size();i++)
		{
			int v=mp[u][i];
			if(vis[v]) continue;
			f[v]=max(f[v],f[u]+w[u]);
			if(v==s) continue;
			ind[v]--;
			if(ind[v]==1) q.push(v);
		}
	}
//	for(int i=1;i<=n;i++) cout<<w[i]<<" "; cout<<endl;
//	for(int i=1;i<=n;i++) cout<<f[i]<<" "; cout<<endl;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		ans+=w[i]; maxf=max(maxf,f[i]);
	}
	cout<<ans+maxf<<endl;
	return 0;
}