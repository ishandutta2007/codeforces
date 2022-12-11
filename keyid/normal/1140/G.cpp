#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <LL,int> pli;

#define pb push_back
#define mp make_pair
#define fi first
#define sc second

const int MAXN=300005,MAXQ=600005;
const LL INF=0x3f3f3f3f3f3f3f3f;

struct edge
{
	int to;
	LL w1,w2;
};

struct edge2
{
	int to;
	LL w;
};

struct query
{
	int u,v,id;
};

vector <edge2> Gt[MAXN];
vector <edge> G[MAXN];
vector <query> qu[MAXN];
LL d[MAXN],dis[20][MAXN][2][2];
int dep[MAXN],maxbit,fa[20][MAXN];

void dfs(int u)
{
	for (const auto &e:G[u])
	{
		int v=e.to;
		if (v!=fa[0][u])
		{
			fa[0][v]=u;
			dep[v]=dep[u]+1;
			dis[0][v][0][0]=e.w1;
			dis[0][v][1][1]=e.w2;
			dis[0][v][0][1]=min(e.w1+d[u],e.w2+d[v]);
			dis[0][v][1][0]=min(e.w2+d[u],e.w1+d[v]);
			dfs(v);
		}
	}
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&d[i]);
	for (int i=1;i<n;i++)
	{
		int u,v;
		LL w1,w2;
		scanf("%d%d%lld%lld",&u,&v,&w1,&w2);
		G[u].pb({v,w1,w2});
		G[v].pb({u,w1,w2});
		Gt[u].pb({v,w1+w2});
		Gt[v].pb({u,w1+w2});
	}
	priority_queue <pli,vector<pli>,greater<pli>> pq;
	for (int i=1;i<=n;i++)
		pq.push(mp(d[i],i));
	while (!pq.empty())
	{
		pli u=pq.top();pq.pop();
		if (d[u.sc]!=u.fi)
			continue;
		for (const auto &e:Gt[u.sc])
		{
			int v=e.to;
			if (d[v]>u.fi+e.w)
			{
				d[v]=u.fi+e.w;
				pq.push(mp(d[v],v));
			}
		}
	}
	dep[1]=1;
	dfs(1);
	while ((1<<maxbit)<n) maxbit++;
	maxbit--;
	for (int j=1;j<=maxbit;j++)
		for (int i=1;i<=n;i++)
		{
			fa[j][i]=fa[j-1][fa[j-1][i]];
			for (int k=0;k<2;k++)
				for (int l=0;l<2;l++)
					dis[j][i][k][l]=min(dis[j-1][i][k][0]+dis[j-1][fa[j-1][i]][0][l],dis[j-1][i][k][1]+dis[j-1][fa[j-1][i]][1][l]);
		}
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int p1=(u%2)^1,p2=(v%2)^1;
		u=(u+1)/2;
		v=(v+1)/2;
		if (dep[u]<dep[v])
		{
			swap(u,v);
			swap(p1,p2);
		}
		LL dt[2][2],tmp[2];
		dt[0][p1]=0;
		dt[0][p1^1]=d[u];
		dt[1][p2]=0;
		dt[1][p2^1]=d[v];
		for (int i=maxbit;i>=0;i--)
			if (dep[fa[i][u]]>=dep[v])
			{
				memcpy(tmp,dt[0],sizeof(tmp));
				for (int j=0;j<2;j++)
					dt[0][j]=min(tmp[j]+dis[i][u][j][j],tmp[j^1]+dis[i][u][j^1][j]);
				u=fa[i][u];
			}
		if (u!=v)
		{
			for (int i=maxbit;i>=0;i--)
				if (fa[i][u]!=fa[i][v])
				{
					memcpy(tmp,dt[0],sizeof(tmp));
					for (int j=0;j<2;j++)
						dt[0][j]=min(tmp[j]+dis[i][u][j][j],tmp[j^1]+dis[i][u][j^1][j]);
					memcpy(tmp,dt[1],sizeof(tmp));
					for (int j=0;j<2;j++)
						dt[1][j]=min(tmp[j]+dis[i][v][j][j],tmp[j^1]+dis[i][v][j^1][j]);
					u=fa[i][u];
					v=fa[i][v];
				}
			memcpy(tmp,dt[0],sizeof(tmp));
			for (int j=0;j<2;j++)
				dt[0][j]=min(tmp[j]+dis[0][u][j][j],tmp[j^1]+dis[0][u][j^1][j]);
			memcpy(tmp,dt[1],sizeof(tmp));
			for (int j=0;j<2;j++)
				dt[1][j]=min(tmp[j]+dis[0][v][j][j],tmp[j^1]+dis[0][v][j^1][j]);
		}
		printf("%lld\n",min(dt[0][0]+dt[1][0],dt[0][1]+dt[1][1]));
	}
	return 0;
}