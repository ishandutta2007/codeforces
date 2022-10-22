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
#define maxn 600005
#define re register
#define inf 1e18
#define eps 1e-10
using namespace std;
 
inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}
 
ll n,m,k,q,uu[maxn],vv[maxn],ww[maxn],fr[maxn],cnt,f[maxn];
struct node{ll to,w;};
struct node2{ll v,w;};
struct node3{ll fr,to,w;};
node3 a[maxn];
vector <node> mp[maxn],mp2[maxn];
ll dis[maxn],top;
bool vis[maxn],vis2[maxn];
 
inline bool operator < (node2 a,node2 b){return a.w>b.w;}
inline bool cmp(node3 a,node3 b){return a.w<b.w;}
 
 
priority_queue <node2> que;
ll dep[maxn],fa[maxn][25],fa2[maxn][25];
 
inline void dij()
{
	for(int i=1;i<=k;i++) que.push((node2){i,0});
	while(!que.empty())
	{
		node2 u=que.top(); que.pop();
		if(vis[u.v]) continue;
		for(int i=0;i<mp[u.v].size();i++)
		{
			node v=mp[u.v][i];
			if(dis[v.to]>dis[u.v]+v.w)
			{
				dis[v.to]=dis[u.v]+v.w;
				fr[v.to]=fr[u.v];
				que.push((node2){v.to,dis[v.to]});
			}
		}
	}
}
 
inline ll getf(int x)
{
	if(f[x]==x) return x;
	return f[x]=getf(f[x]);
}
 
inline void dfs(int u)
{
	vis2[u]=1;
	for(int i=0;i<mp2[u].size();i++)
	{
		node v=mp2[u][i];
		if(vis2[v.to]==1) continue;
		fa[v.to][0]=u;
		fa2[v.to][0]=v.w;
		dep[v.to]=dep[u]+1;
		dfs(v.to);
	}
}
 
inline ll sol(int u,int v)
{
	ll tmp=0;
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=top;i>=0;i--)
		if(dep[fa[u][i]]>=dep[v]) tmp=max(tmp,fa2[u][i]),u=fa[u][i];
	if(u==v) return tmp;
	for(int i=top;i>=0;i--)
	{
		if(fa[u][i]!=fa[v][i])
		{
			tmp=max(tmp,fa2[u][i]);
			tmp=max(tmp,fa2[v][i]);
			u=fa[u][i]; v=fa[v][i];
		}
	}
	tmp=max(tmp,fa2[u][0]); tmp=max(tmp,fa2[v][0]);
	return tmp;
}
 
int main()
{
	n=read(); m=read(); k=read(); q=read();
	for(int i=1;i<=m;i++)
	{
		ll u=read(),v=read(),w=read();
		uu[i]=u; vv[i]=v; ww[i]=w;
		mp[u].push_back((node){v,w});
		mp[v].push_back((node){u,w});
	}
	for(int i=1;i<=n;i++) dis[i]=inf;
	for(int i=1;i<=k;i++) fr[i]=i,dis[i]=0;
	dij();
	for(int i=1;i<=m;i++)
	{
		if(fr[uu[i]]==fr[vv[i]]) continue;
		a[++cnt]=(node3){fr[uu[i]],fr[vv[i]],dis[uu[i]]+dis[vv[i]]+ww[i]};
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=cnt;i++)
	{
		node3 tmp=a[i];
		ll fu=getf(tmp.fr),fv=getf(tmp.to);
		if(fu==fv) continue; f[fu]=fv;
		mp2[fu].push_back((node){fv,tmp.w});
		mp2[fv].push_back((node){fu,tmp.w});
	}
	dfs(1);
	for(;(1<<top)<=k;top++);
	for(int i=1;i<=top;i++)
		for(int j=1;j<=k;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1],fa2[j][i]=max(fa2[j][i-1],fa2[fa[j][i-1]][i-1]);
	while(q--)
	{
		int x=read(),y=read();
		printf("%lld\n",sol(fr[x],fr[y]));
	}
	return 0;
}