#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;

struct Path
{
	int d[2];
}pv[MAXN*4],pt;

int p[MAXN],pos[MAXN],dep[MAXN],maxbit,clo,dfn[MAXN],lst[MAXN],Y,V,eu[20][MAXN*2];
vector <int> G[MAXN];

int Min(int u,int v)
{
	return dep[u]<dep[v]?u:v;
}

void dfs(int u)
{
	dfn[u]=clo;
	eu[0][clo++]=u;
	for (int v:G[u])
	{
		dep[v]=dep[u]+1;
		dfs(v);
		eu[0][clo++]=u;
	}
	lst[u]=clo;
}

int LCA(int u,int v)
{
	int l=dfn[u],r=dfn[v];
	if (l>r)
		swap(l,r);
	int k=31-__builtin_clz(r-l+1);
	return Min(eu[k][l],eu[k][r-(1<<k)+1]);
}

int tmp[4];

bool on_path(int x,int u,int v)
{
	int lca=LCA(u,v);
	return (dfn[lca]<=dfn[x]&&lst[lca]>=dfn[x])&&((dfn[x]<=dfn[u]&&lst[x]>=dfn[u])||(dfn[x]<=dfn[v]&&lst[x]>=dfn[v]));
}

Path merge(const Path &a,const Path &b)
{
	if (b.d[0]==-1)
		return a;
	Path ret;
	ret.d[0]=0;
	if (a.d[0]&&b.d[0])
	{
		int cnt=0;
		for (int i=0;i<2;i++)
		{
			tmp[cnt++]=a.d[i];
			tmp[cnt++]=b.d[i];
		}
		sort(tmp,tmp+cnt);
		cnt=unique(tmp,tmp+cnt)-tmp;
		for (int i=0;i<cnt;i++)
			for (int j=i+1;j<cnt;j++)
			{
				bool flag=true;
				for (int k=0;k<cnt;k++)
					if (!on_path(tmp[k],tmp[i],tmp[j]))
					{
						flag=false;
						break;
					}
				if (flag)
				{
					ret.d[0]=tmp[i];
					ret.d[1]=tmp[j];
					return ret;
				}
			}
	}
	return ret;
}

void build(int o,int l,int r)
{
	if (l<r)
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		build(lc,l,m);
		build(rc,m+1,r);
		pv[o]=merge(pv[lc],pv[rc]);
	}
	else
		pv[o].d[0]=pv[o].d[1]=pos[l];
}

void update(int o,int l,int r)
{
	if (l<r)
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		if (Y<=m)
			update(lc,l,m);
		else
			update(rc,m+1,r);
		pv[o]=merge(pv[lc],pv[rc]);
	}
	else
		pv[o].d[0]=pv[o].d[1]=V;
}

int query(int o,int l,int r)
{
	if (l<r)
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		Path t=merge(pv[lc],pt);
		if (t.d[0]==0)
			return query(lc,l,m);
		pt=t;
		return query(rc,m+1,r);
	}
	if (merge(pv[o],pt).d[0])
		return l+1;
	return l;
}

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		pos[p[i]]=i;
	}
	for (int i=2;i<=n;i++)
	{
		int f;
		scanf("%d",&f);
		G[f].push_back(i);
	}
	dfs(1);
	while ((1<<maxbit)<=clo) maxbit++;
	maxbit--;
	for (int j=1;j<=maxbit;j++)
		for (int i=0;i+(1<<j)<=clo;i++)
			eu[j][i]=Min(eu[j-1][i],eu[j-1][i+(1<<j-1)]);
	build(1,0,n-1);
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int op;
		scanf("%d",&op);
		if (op==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			Y=p[x];
			V=y;
			update(1,0,n-1);
			Y=p[y];
			V=x;
			update(1,0,n-1);
			swap(p[x],p[y]);
		}
		else
		{
			pt.d[0]=-1;
			printf("%d\n",query(1,0,n-1));
		}
	}
	return 0;
}