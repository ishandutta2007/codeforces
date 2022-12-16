#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=998244353,L=1000000000;
const long long inf=100000000000000000ll;
int n,m,k,i,j,fa[N][20],faf[N][20],dep[N],d[N];
int f[N],mx[N],lca[N],ph[N],ans1[N],ans2[N];
struct node{
	int v,w;
};
vector<node> g[N];
struct str{
	int u,v,w,c;
}e[N];
struct que{
	int v,x,id;
}q[N];
void dfs(int i,int f)
{
	fa[i][0]=f;
	for(auto it:g[i])
		if(it.v!=f)
		{
			faf[it.v][0]=it.w;
			dep[it.v]=dep[i]+1;
			dfs(it.v,i);
		}
}
int as;
int LCA(int u,int v)
{
	as=0;
	if(dep[u]<dep[v])
		swap(u,v);
	for(int i=19;i>=0;--i)
		if(dep[fa[u][i]]>=dep[v])
		{
			as=max(faf[u][i],as);
			u=fa[u][i];
		}
	for(int i=19;i>=0;--i)
		if(fa[u][i]!=fa[v][i])
		{
			as=max({as,faf[u][i],faf[v][i]});
			u=fa[u][i];
			v=fa[v][i];
		}
	if(u!=v)
	{
		as=max({as,faf[u][0],faf[v][0]});
		u=fa[u][0];
	}
	return u;
}
int Find(int x)
{
	return f[x]?f[x]=Find(f[x]):x;
}
void uniot(int u,int v)
{
	int x=Find(u),y=Find(v);
	if(x!=y)
	{
		f[y]=x;
		if(mx[x]<mx[y])
		{
			lca[x]=lca[y];
			ph[x]=ph[y];
		}
		if(mx[x]==mx[y])
		{
			lca[x]=LCA(lca[x],lca[y]);
			ph[x]=max({ph[x],ph[y],as});
		}
		mx[x]=max(mx[x],mx[y]);
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d",&d[i]);
	for(i=1;i<n;++i)
	{
		scanf("%d %d %d %d",&e[i].u,&e[i].v,&e[i].c,&e[i].w);
		g[e[i].u].push_back({e[i].v,e[i].w});
		g[e[i].v].push_back({e[i].u,e[i].w});
	}
	sort(e+1,e+1+n,[](str a,str b)->bool{return a.c>b.c;});
	dep[1]=1;
	dfs(1,0);
	for(i=1;i<19;++i)
		for(j=1;j<=n;++j)
		{
			fa[j][i]=fa[fa[j][i-1]][i-1];
			faf[j][i]=max(faf[j][i-1],faf[fa[j][i-1]][i-1]);
		}
	for(i=1;i<=n;++i)
		lca[i]=i,mx[i]=d[i];
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&q[i].v,&q[i].x);
		q[i].id=i;
	}
	sort(q+1,q+1+m,[](que a,que b)->bool{return a.v>b.v;});
	int l=1;
	for(i=1;i<=m;++i)
	{
		while(e[l].c>=q[i].v)
		{
			uniot(e[l].u,e[l].v);
			++l;
		}
		int u=Find(q[i].x);
		LCA(lca[u],q[i].x);
		ans1[q[i].id]=mx[u],ans2[q[i].id]=max(as,ph[u]);
	}
	for(i=1;i<=m;++i)
		printf("%d %d\n",ans1[i],ans2[i]);
}