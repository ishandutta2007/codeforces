#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=200005;

int n,yl,yr,V,ql,qr,maxbit,fa[20][MAXN],deep[MAXN],clo,dfn[MAXN],lst[MAXN],jmp[20][MAXN];
vector <int> G[MAXN],add[MAXN],d[MAXN*4];

void dfs(int u)
{
	dfn[u]=++clo;
	for (int v:G[u])
	{
		deep[v]=deep[u]+1;
		dfs(v);
	}
	lst[u]=clo;
}

int LCA(int u,int v)
{
	if (deep[u]<deep[v])
		swap(u,v);
	for (int i=maxbit;i>=0;i--)
		if (deep[fa[i][u]]>=deep[v])
			u=fa[i][u];
	if (u==v)
		return u;
	for (int i=maxbit;i>=0;i--)
		if (fa[i][u]!=fa[i][v])
		{
			u=fa[i][u];
			v=fa[i][v];
		}
	return fa[0][u];
}

void dfs2(int u)
{
	int &mx=jmp[0][u];
	mx=u;
	for (int v:add[u])
		if (deep[v]<deep[mx])
			mx=v;
	for (int v:G[u])
	{
		dfs2(v);
		if (deep[jmp[0][v]]<deep[mx])
			mx=jmp[0][v];
	}
}

bool reach(int u,int v)
{
	return deep[jmp[maxbit][u]]<=deep[v];
}

int query(int u,int v)
{
	int ret=1;
	for (int i=maxbit;i>=0;i--)
		if (deep[jmp[i][u]]>deep[v])
		{
			u=jmp[i][u];
			ret+=1<<i;
		}
	return ret;
}

int query(int u,int v,int &p)
{
	int ret=0;
	for (int i=maxbit;i>=0;i--)
		if (deep[jmp[i][u]]>deep[v])
		{
			u=jmp[i][u];
			ret+=1<<i;
		}
	p=u;
	return ret;
}

void update(int o,int l,int r)
{
	d[o].pb(V);
	if (l<r)
	{
		int m=l+r>>1;
		if (yl<=m)
			update(o<<1,l,m);
		else
			update(o<<1|1,m+1,r);
	}
}

void build(int o,int l,int r)
{
	sort(d[o].begin(),d[o].end());
	d[o].resize(unique(d[o].begin(),d[o].end())-d[o].begin());
	if (l<r)
	{
		int m=l+r>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
	}
}

bool query_ok(int o,int l,int r)
{
	if (yl<=l&&yr>=r)
	{
		auto k=lower_bound(d[o].begin(),d[o].end(),ql);
		if (k!=d[o].end()&&*k<=qr)
			return true;
		return false;
	}
	int m=l+r>>1;
	if (yl<=m)
	{
		if (query_ok(o<<1,l,m))
			return true;
	}
	if (yr>m)
	{
		if (query_ok(o<<1|1,m+1,r))
			return true;
	}
	return false;
}

bool check(int p1,int p2)
{
	yl=dfn[p1];
	yr=lst[p1];
	ql=dfn[p2];
	qr=lst[p2];
	if (query_ok(1,1,n))
		return true;
	return false;
}

int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&fa[0][i]);
		G[fa[0][i]].pb(i);
	}
	deep[1]=1;
	dfs(1);
	while ((1<<maxbit)<n) maxbit++;
	maxbit--;
	for (int j=1;j<=maxbit;j++)
		for (int i=1;i<=n;i++)
			fa[j][i]=fa[j-1][fa[j-1][i]];
	int m;
	scanf("%d",&m);
	while (m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int lca=LCA(u,v);
		yl=dfn[u];
		V=dfn[v];
		update(1,1,n);
		yl=dfn[v];
		V=dfn[u];
		update(1,1,n);
		add[u].pb(lca);
		add[v].pb(lca);
	}
	build(1,1,n);
	dfs2(1);
	for (int j=1;j<=maxbit;j++)
		for (int i=1;i<=n;i++)
			jmp[j][i]=jmp[j-1][jmp[j-1][i]];
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int lca=LCA(u,v);
		if (!reach(u,lca)||!reach(v,lca))
			puts("-1");
		else if (u==lca)
			printf("%d\n",query(v,u));
		else if (v==lca)
			printf("%d\n",query(u,v));
		else
		{
			int p1,p2;
			int d1=query(u,lca,p1),d2=query(v,lca,p2);
			int ans=d1+d2+1;
			if (!check(p1,p2))
				ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}