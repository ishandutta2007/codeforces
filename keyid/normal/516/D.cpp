#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define pb push_back

const int MAXN=100005;

struct edge
{
	int to,w;
};

vector <edge> G[MAXN];
vector <int> dia;
int fa[MAXN],nc,C[MAXN];
LL d[MAXN],dis[MAXN],num[MAXN];
bool on_dia[MAXN];

void dfs1(int u)
{
	for (const auto &e:G[u])
	{
		int v=e.to;
		if (v!=fa[u])
		{
			fa[v]=u;
			d[v]=d[u]+e.w;
			dfs1(v);
		}
	}
}

void add(int x,int d)
{
	for (;x<=nc;x+=x&-x)
		C[x]+=d;
}

int sum(int x)
{
	int ret=0;
	for (;x;x-=x&-x)
		ret+=C[x];
	return ret;
}

int ans;
LL l;

void dfs2(int u,int fa)
{
	int k1=upper_bound(num,num+nc,dis[u]+l)-num;
	int k2=upper_bound(num,num+nc,dis[u])-num;
	int c=sum(k1);
	add(k2,1);
	for (const auto &e:G[u])
	{
		int v=e.to;
		if (v!=fa&&!on_dia[v])
			dfs2(v,u);
	}
	ans=max(ans,sum(k1)-c);
}

void dfs3(int u,int fa)
{
	num[nc++]=dis[u];
	for (const auto &e:G[u])
	{
		int v=e.to;
		if (v!=fa&&!on_dia[v])
		{
			dis[v]=dis[u]+e.w;
			dfs3(v,u);
		}
	}
}

priority_queue <LL> pq;

void dfs4(int u,int fa)
{
	pq.push(dis[u]);
	for (const auto &e:G[u])
	{
		int v=e.to;
		if (v!=fa&&!on_dia[v])
			dfs4(v,u);
	}
}

void solve(int n,int p1,int p2)
{
	scanf("%lld",&l);
	ans=0;
	LL ds=LLONG_MAX;
	for (const int &v:dia)
		ds=min(ds,max(d[p2]-d[v],d[v]));
	for (int i=1;i<=n;i++)
		if (dis[i]<=l+ds)
			ans++;
	for (const int &i:dia)
		dfs2(i,0);
	priority_queue <LL> ().swap(pq);
	for (int i=0;i<dia.size();i++)
	{
		if (d[p2]-d[dia[i]]>d[dia[i]])
		{
			priority_queue <LL> ().swap(pq);
			for (int j=dia.size()-1;j>=i;j--)
			{
				dfs4(dia[j],0);
				while (pq.top()>l+dis[dia[j]])
					pq.pop();
				ans=max(ans,(int)pq.size());
			}
			break;
		}
		dfs4(dia[i],0);
		while (pq.top()>l+dis[dia[i]])
			pq.pop();
		ans=max(ans,(int)pq.size());
	}
	printf("%d\n",ans);
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].pb({v,w});
		G[v].pb({u,w});
	}
	dfs1(1);
	int p1=1;
	for (int i=2;i<=n;i++)
		if (d[i]>d[p1])
			p1=i;
	fa[p1]=0;
	d[p1]=0;
	dfs1(p1);
	int p2=p1;
	for (int i=1;i<=n;i++)
		if (d[i]>d[p2])
			p2=i;
	for (int i=p2;i;i=fa[i])
	{
		on_dia[i]=true;
		dia.pb(i);
	}
	for (const int &i:dia)
	{
		dis[i]=max(d[p2]-d[i],d[i]);
		dfs3(i,0);
	}
	sort(num,num+nc);
	nc=unique(num,num+nc)-num;
	int q;
	scanf("%d",&q);
	while (q--) solve(n,p1,p2);
	return 0;
}