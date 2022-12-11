#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define sc second

typedef long long LL;
typedef pair <int,int> pii;

const int MAXN=200005;

struct edge
{
	int u,v,w,c,id;
}e[MAXN];

struct edge2
{
	int to,nxt;
	pii w;
}e2[MAXN*2];

int p[MAXN],ec,first[MAXN],maxbit,fa[20][MAXN],deep[MAXN];
bool inmst[MAXN];
pii _max[20][MAXN];

bool cmp(const edge &a,const edge &b)
{
	return a.w<b.w;
}

void addedge(int u,int v,int w,int id)
{
	e2[ec]=(edge2){v,first[u],mp(w,id)};
	first[u]=ec++;
}

int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}

void dfs(int u)
{
	for (int i=first[u];i!=-1;i=e2[i].nxt)
	{
		int v=e2[i].to;
		if (v!=fa[0][u])
		{
			fa[0][v]=u;
			_max[0][v]=e2[i].w;
			deep[v]=deep[u]+1;
			dfs(v);
		}
	}
}

pii query(int u,int v)
{
	if (deep[u]<deep[v]) swap(u,v);
	pii ret(INT_MIN,0);
	for (int j=maxbit;j>=0;j--)
		if (deep[u]-deep[v]>>j&1)
		{
			ret=max(ret,_max[j][u]);
			u=fa[j][u];
		}
	if (u==v) return ret;
	for (int j=maxbit;j>=0;j--)
		if (fa[j][u]!=fa[j][v])
		{
			ret=max(ret,max(_max[j][u],_max[j][v]));
			u=fa[j][u];
			v=fa[j][v];
		}
	ret=max(ret,max(_max[0][u],_max[0][v]));
	return ret;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d",&e[i].w);
	for (int i=1;i<=m;i++)
		scanf("%d",&e[i].c);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&e[i].u,&e[i].v);
		e[i].id=i;
	}
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=n;i++) p[i]=i;
	LL sum=0;
	fill(first+1,first+n+1,-1);
	for (int i=1;i<=m;i++)
	{
		int u=find(e[i].u),v=find(e[i].v);
		if (u!=v)
		{
			p[u]=v;
			addedge(u,v,e[i].w,i);
			addedge(v,u,e[i].w,i);
			inmst[i]=true;
			sum+=e[i].w;
		}
	}
	deep[1]=1;
	dfs(1);
	while ((1<<maxbit)<n) maxbit++;
	for (int j=1;j<=maxbit;j++)
		for (int i=1;i<=n;i++)
		{
			fa[j][i]=fa[j-1][fa[j-1][i]];
			_max[j][i]=max(_max[j-1][i],_max[j-1][fa[j-1][i]]);
		}
	int S,del=-1,sel=-1,d=0;
	scanf("%d",&S);
	for (int i=1;i<=m;i++)
	{
		pii Max=query(e[i].u,e[i].v);
		if (d>e[i].w-S/e[i].c-Max.fi)
		{
			d=e[i].w-S/e[i].c-Max.fi;
			del=Max.sc;
			sel=i;
		}
	}
	printf("%lld\n",sum+d);
	for (int i=1;i<=m;i++)
		if (i==sel)
			printf("%d %d\n",e[i].id,e[i].w-S/e[i].c);
		else if (inmst[i]&&del!=i)
			printf("%d %d\n",e[i].id,e[i].w);
	return 0;
}