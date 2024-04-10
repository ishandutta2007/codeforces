#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long LL;

const int MAXN=500005;

struct edge
{
	int to,w;
};

struct query
{
	int l,r,id;
};

vector <edge> G[MAXN];
vector <query> q[MAXN];
int leaf[MAXN],clo,dfn[MAXN],lst[MAXN],yl,yr;
LL ans[MAXN],dep[MAXN],V,mnv[MAXN*4],addv[MAXN*4];

void build(int o,int l,int r)
{
	if (l<r)
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		build(lc,l,m);
		build(rc,m+1,r);
		mnv[o]=min(mnv[lc],mnv[rc]);
	}
	else
		mnv[o]=dep[l];
}

void update(int o,int l,int r)
{
	if (yl<=l&&yr>=r)
	{
		addv[o]+=V;
		mnv[o]+=V;
	}
	else
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		if (yl<=m)
			update(lc,l,m);
		if (yr>m)
			update(rc,m+1,r);
		mnv[o]=min(mnv[lc],mnv[rc])+addv[o];
	}
}

void get_min(int o,int l,int r,LL add)
{
	if (yl<=l&&yr>=r)
		V=min(V,add+mnv[o]);
	else
	{
		int m=l+r>>1;
		add+=addv[o];
		if (yl<=m)
			get_min(o<<1,l,m,add);
		if (yr>m)
			get_min(o<<1|1,m+1,r,add);
	}
}

void dfs1(int u)
{
	dfn[u]=clo;
	for (const auto &e:G[u])
		dfs1(e.to);
	if (G[u].empty())
		dep[clo++]=dep[u];
	lst[u]=clo-1;
}

void dfs2(int u)
{
	for (const auto &qu:q[u])
	{
		yl=qu.l;
		yr=qu.r;
		V=LLONG_MAX;
		get_min(1,0,clo,0);
		ans[qu.id]=V;
	}
	for (const edge &e:G[u])
	{
		yl=dfn[e.to];
		yr=lst[e.to];
		V=-2*e.w;
		update(1,0,clo);
		yl=0;
		yr=clo;
		V=e.w;
		update(1,0,clo);
		dfs2(e.to);
		yl=dfn[e.to];
		yr=lst[e.to];
		V=2*e.w;
		update(1,0,clo);
		yl=0;
		yr=clo;
		V=-e.w;
		update(1,0,clo);
	}
}

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=2;i<=n;i++)
	{
		int p,w;
		scanf("%d%d",&p,&w);
		dep[i]=dep[p]+w;
		G[p].pb({i,w});
	}
	int lc=0;
	for (int i=1;i<=n;i++)
		if (G[i].empty())
			leaf[lc++]=i;
	for (int i=0;i<m;i++)
	{
		int v,l,r;
		scanf("%d%d%d",&v,&l,&r);
		l=lower_bound(leaf,leaf+lc,l)-leaf;
		r=upper_bound(leaf,leaf+lc,r)-leaf-1;
		q[v].pb({l,r,i});
	}
	dfs1(1);
	clo--;
	build(1,0,clo);
	dfs2(1);
	for (int i=0;i<m;i++)
		printf("%lld\n",ans[i]);
	return 0;
}