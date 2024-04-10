#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define sc second

typedef long long LL;
typedef pair <LL,int> pli;

const int MAXN=200005,MAXM=300005;
const LL INF=0x3f3f3f3f3f3f3f3fLL;

struct edge
{
	int to,w,nxt;
}e[MAXM*2];

int ec,first[MAXN],maxbit,fa[20][MAXN],deep[MAXN];
LL d[MAXN];
bool vis[MAXN];
vector <int> G[MAXN],P[MAXN];
priority_queue <pli,vector<pli>,greater<pli> > q;

void addedge(int u,int v,int w)
{
	e[ec]=(edge){v,w,first[u]};
	first[u]=ec++;
}

int LCA(int u,int v)
{
	if (v==0) return u;
	if (deep[u]<deep[v]) swap(u,v);
	for (int i=maxbit;i>=0;i--)
		if (deep[u]-deep[v]>>i&1)
			u=fa[i][u];
	if (u==v) return u;
	for (int i=maxbit;i>=0;i--)
		if (fa[i][u]!=fa[i][v])
		{
			u=fa[i][u];
			v=fa[i][v];
		}
	return fa[0][u];
}

void dfs(int u)
{
	if (vis[u]) return;
	vis[u]=true;
	int &f=fa[0][u];
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		dfs(v);
		f=LCA(v,f);
	}
	P[f].pb(u);
	deep[u]=deep[f]+1;
	for (int j=1;j<=maxbit;j++)
		fa[j][u]=fa[j-1][fa[j-1][u]];
}

int dfs2(int u)
{
	int s=1;
	for (int i=0;i<P[u].size();i++)
		s+=dfs2(P[u][i]);
	return s;
}

int main()
{
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	fill(first+1,first+n+1,-1);
	while (m--)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	fill(d+1,d+n+1,INF);
	d[s]=0;
	q.push(mp(0,s));
	while (!q.empty())
	{
		pli u=q.top();q.pop();
		if (u.fi!=d[u.sc]) continue;
		for (int i=first[u.sc];i!=-1;i=e[i].nxt)
		{
			int v=e[i].to;
			if (d[v]>u.fi+e[i].w)
			{
				d[v]=u.fi+e[i].w;
				q.push(mp(d[v],v));
			}
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=first[i];j!=-1;j=e[j].nxt)
			if (d[i]==d[e[j].to]+e[j].w)
				G[i].pb(e[j].to);
	while ((1<<maxbit)<n) maxbit++;
	maxbit--;
	deep[s]=1;
	for (int i=1;i<=n;i++)
		if (!vis[i])
			dfs(i);
	int ans=0;
	for (int i=0;i<P[s].size();i++)
		ans=max(ans,dfs2(P[s][i]));
	printf("%d",ans);
	return 0;
}