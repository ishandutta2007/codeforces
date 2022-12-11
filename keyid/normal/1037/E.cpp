#include <bits/stdc++.h>
using namespace std;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair <int,int> pii;

const int MAXN=200005;

struct edge
{
	int u,v;
}e[MAXN];

set <int> G[MAXN];
int d[MAXN],ans[MAXN];
set <pii> s;

void del_s(int u)
{
	if (s.find(mp(d[u],u))!=s.end())
	{
		s.erase(mp(d[u],u));
		d[u]--;
		s.insert(mp(d[u],u));
	}
}

void del(int u,int v)
{
	if (s.find(mp(d[v],v))!=s.end())
	{
		G[u].erase(v);
		del_s(u);
	}
	if (s.find(mp(d[u],u))!=s.end())
	{
		G[v].erase(u);
		del_s(v);
	}
}

int main()
{
	//freopen("read.txt","r",stdin);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&e[i].u,&e[i].v);
		G[e[i].u].insert(e[i].v);
		G[e[i].v].insert(e[i].u);
	}
	for (int i=1;i<=n;i++)
	{
		d[i]=G[i].size();
		s.insert(mp(d[i],i));
	}
	for (int i=m-1;i>=0;i--)
	{
		while (!s.empty()&&s.begin()->fi<k)
		{
			int k=s.begin()->sc;
			s.erase(s.begin());
			for (int v:G[k])
				del_s(v);
		}
		ans[i]=s.size();
		del(e[i].u,e[i].v);
	}
	for (int i=0;i<m;i++)
		printf("%d\n",ans[i]);
	return 0;
}