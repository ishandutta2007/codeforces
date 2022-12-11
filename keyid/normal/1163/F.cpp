#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <LL,int> pli;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=200005;
const LL INF=0x3f3f3f3f3f3f3f3f;

struct edge
{
	int to,w,id;
};

struct edge2
{
	int u,v,w;
}e[MAXN];

struct way
{
	int v,e;
}pre[2][MAXN];

struct road
{
	int l,r;
	LL d;
}rd[MAXN*2];

int n,p[MAXN],sl[MAXN],sr[MAXN],id[MAXN];
bool short_v[MAXN],short_edge[MAXN];
LL d[2][MAXN],ret[MAXN];
vector <edge> G[MAXN];

void dijkstra(int s,way pre[],LL d[])
{
	static priority_queue <pli,vector<pli>,greater<pli>> q;
	for (int i=1;i<=n;i++)
		d[i]=INF;
	d[s]=0;
	q.push(mp(0,s));
	while (!q.empty())
	{
		pli u=q.top();q.pop();
		if (d[u.sc]!=u.fi)
			continue;
		for (const auto &e:G[u.sc])
		{
			int v=e.to;
			if (d[v]>e.w+u.fi)
			{
				d[v]=e.w+u.fi;
				pre[v]={u.sc,e.id};
				q.push(mp(d[v],v));
			}
		}
	}
}

void solve(int l,int r,int c,LL d)
{
	for (int i=0;i<c;i++)
		if (rd[i].l<=l&&rd[i].r>=r)
		{
			d=min(d,rd[i].d);
			swap(rd[i--],rd[--c]);
		}
	if (l<r)
	{
		int m=l+r>>1,tc=c;
		for (int i=0;i<tc;i++)
			if (rd[i].l>m)
				swap(rd[i--],rd[--tc]);
		solve(l,m,tc,d);
		tc=c;
		for (int i=0;i<tc;i++)
			if (rd[i].r<=m)
				swap(rd[i--],rd[--tc]);
		solve(m+1,r,tc,d);
	}
	else
		ret[p[l]]=d;
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int m,q;
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].pb({v,w,i});
		G[v].pb({u,w,i});
		e[i]={u,v,w};
	}
	dijkstra(1,pre[0],d[0]);
	dijkstra(n,pre[1],d[1]);
	int cnt=0;
	for (int now=n;now!=1;now=pre[0][now].v)
	{
		p[cnt++]=now;
		short_edge[pre[0][now].e]=true;
	}
	p[cnt++]=1;
	reverse(p,p+cnt);
	for (int i=0;i<cnt;i++)
		short_v[p[i]]=true;
	for (int i=1;i<=n;i++)
		id[i]=i;
	sort(id+1,id+n+1,[](int x,int y){ return d[0][x]<d[0][y]; });
	for (int i=1;i<=n;i++)
		sl[i]=cnt;
	for (int i=0;i<cnt;i++)
		sl[p[i]]=i;
	for (int i=1;i<=n;i++)
	{
		int u=id[i];
		for (const auto &e:G[u])
			if (!short_v[e.to]&&d[0][e.to]==d[0][u]+e.w)
				sl[e.to]=min(sl[e.to],sl[u]);
	}
	sort(id+1,id+n+1,[](int x,int y){ return d[1][x]<d[1][y]; });
	for (int i=0;i<cnt;i++)
		sr[p[i]]=i;
	for (int i=1;i<=n;i++)
	{
		int u=id[i];
		for (const auto &e:G[u])
			if (!short_v[e.to]&&d[1][e.to]==d[1][u]+e.w)
				sr[e.to]=max(sr[e.to],sr[u]);
	}
	int rc=0;
	for (int i=1;i<=m;i++)
	{
		if (d[0][e[i].u]>d[0][e[i].v])
					swap(e[i].u,e[i].v);
		if (!short_edge[i])
		{
			int l=sl[e[i].u],r=sr[e[i].v];
			if (l+1<=r)
				rd[rc++]={l,r-1,d[0][e[i].u]+d[1][e[i].v]+e[i].w};
			l=sl[e[i].v];
			r=sr[e[i].u];
			if (l+1<=r)
				rd[rc++]={l,r-1,d[0][e[i].v]+d[1][e[i].u]+e[i].w};
		}
	}
	solve(0,cnt-1,rc,INF);
	while (q--)
	{
		int t,x;
		scanf("%d%d",&t,&x);
		LL ans1=d[0][e[t].u]+d[1][e[t].v]+x,ans2=short_edge[t]?ret[e[t].u]:d[0][n];
		printf("%lld\n",min(ans1,ans2));
	}
	return 0;
}