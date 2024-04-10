#include<bits/stdc++.h>
#define ll long long
#define inf 0x7f7f7f7f
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int n,k;
int vis[200005];
vector<int> g[200005];
int size[200005];
int dep[200005];
int a[200005];
int root,sum;
void dfs(int x,int fa)
{
	if(vis[x]) size[x]=1;
	int mx=0;
	for(int i=0;i<g[x].size();i++)
	{
		int to=g[x][i];
		if(to==fa) continue;
		dfs(to,x);
		size[x]+=size[to];
		mx=max(mx,size[to]);
	}
	if(max(mx,sum-size[x])<=sum/2) 
	root=x;
}
void dfs1(int x,int fa)
{
	for(int i=0;i<g[x].size();i++)
	{
		int to=g[x][i];
		if(to==fa) continue;
		dep[to]=dep[x]+1;
		dfs1(to,x);
	}
}
int main()
{
	n=read();k=read();
	for(int i=1;i<=2*k;i++)
	{ a[i]=read(); vis[a[i]]=1; }
	for(int i=1;i<n;i++)
	{
		int l=read(),r=read();
		g[l].push_back(r);
		g[r].push_back(l);
	}
	sum=2*k;
	dfs(1,0);
	dfs1(root,0);
	ll ans=0;
	for(int i=1;i<=2*k;i++)
	ans+=dep[a[i]];
	cout<<ans;
	return 0;
}