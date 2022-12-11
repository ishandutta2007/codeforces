#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef pair <int,int> pii;

const int MAXN=100005;

struct edge
{
	int to,nxt;
}e[MAXN*2];

struct edge2
{
	int u,v;
};

int ec,first[MAXN],vis[MAXN];
vector <int> col[MAXN];
vector <edge2> vc[MAXN];
unordered_map <int,int> p[MAXN];
map <pii,int> ans;
queue <int> q;

inline void addedge(int u,int v)
{
	e[ec]=(edge){v,first[u]};
	first[u]=ec++;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	fill(first+1,first+n+1,-1);
	for (int i=1;i<=m;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		col[u].pb(c);
		col[v].pb(c);
		vc[c].pb((edge2){u,v});
	}
	for (int i=1;i<=m;i++)
	{
		ec=0;
		for (int j=0;j<vc[i].size();j++)
		{
			addedge(vc[i][j].u,vc[i][j].v);
			addedge(vc[i][j].v,vc[i][j].u);
		}
		for (int j=0;j<vc[i].size();j++)
		{
			int s=vc[i][j].u;
			if (vis[s]==i) continue;
			vis[s]=i;
			q.push(s);
			while (!q.empty())
			{
				int u=q.front();q.pop();
				p[i][u]=s;
				for (int j=first[u];j!=-1;j=e[j].nxt)
				{
					int v=e[j].to;
					if (vis[v]!=i)
					{
						vis[v]=i;
						q.push(v);
					}
				}
			}
		}
		for (int j=0;j<vc[i].size();j++)
			first[vc[i][j].u]=first[vc[i][j].v]=-1;
	}
	int Q;
	scanf("%d",&Q);
	fill(vis+1,vis+n+1,0);
	for (int j=1;j<=Q;j++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if (col[u].size()>col[v].size()||(col[u].size()==col[v].size()&&u>v)) swap(u,v);
		pii t(u,v);
		if (ans.find(t)==ans.end())
		{
			int ret=0;
			for (int i=0;i<col[u].size();i++)
			{
				int c=col[u][i];
				if (vis[c]==j) continue;
				vis[c]=j;
				if (p[c].find(v)!=p[c].end()&&p[c][u]==p[c][v])
					ret++;
			}
			ans[t]=ret;
		}
		printf("%d\n",ans[t]);
	}
	return 0;
}