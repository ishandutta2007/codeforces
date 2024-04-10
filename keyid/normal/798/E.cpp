#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define sc second

typedef pair <int,int> pii;

const int MAXN=500005;

int n,a[MAXN],lst[MAXN],tot,p[MAXN],id[MAXN],v[MAXN];
bool vis[MAXN];
vector <pii> C[MAXN];

bool cmp(const int &x,const int &y)
{
	return a[x]<a[y];
}

void add(int p,int d)
{
	for (int x=p;x<=n;x+=x&-x)
		C[x].pb(mp(p,d));
}

void dfs(int u)
{
	vis[u]=true;
	if (a[u]<=n&&!vis[a[u]])
		dfs(a[u]);
	for (int x=lst[u]-1;x;x-=x&-x)
		while (!C[x].empty()&&C[x].back().sc>u)
		{
			int v=C[x].back().fi;
			C[x].pop_back();
			if (!vis[v])
				dfs(v);
		}
	p[tot--]=u;
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		lst[i]=n+1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]!=-1)
			lst[a[i]]=i;
		else
			a[i]=n+1;
	}
	tot=n;
	for (int i=1;i<=n;i++)
		id[i]=i;
	sort(id+1,id+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		int x=id[i];
		add(x,a[x]);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i])
			dfs(i);
	for (int i=1;i<=n;i++)
		v[p[i]]=i;
	for (int i=1;i<=n;i++)
		printf("%d ",v[i]);
	return 0;
}