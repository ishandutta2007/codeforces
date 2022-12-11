#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
 
#define pb push_back
 
const int MAXN=300005;
 
int a[MAXN],pos[MAXN],fa[MAXN],dep[MAXN],sz[MAXN],chd[MAXN],poc,post_order[MAXN],clo,dfn[MAXN];
vector <int> G[MAXN],G2[MAXN];
bool vis[MAXN],vis2[MAXN];
 
void dfs1(int u)
{
	for (int v:G[u])
	{
		chd[u]++;
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs1(v);
	}
}
 
void dfs2(int u)
{
	if (!vis[u])
		return;
	sz[u]=1;
	for (int v:G[u])
	{
		dfs2(v);
		sz[u]+=sz[v];
	}
}
 
bool check(int l,int r)
{
	if (l>r)
		return false;
	int u=post_order[r];
	if (vis2[u])
		return false;
	vis2[u]=true;
	if (sz[u]!=r-l+1)
		return false;
	for (int i=r-1;i>=l;)
	{
		int v=post_order[i];
		if (fa[v]!=u)
			return false;
		if (i-sz[v]+1<l)
			return false;
		if (!check(i-sz[v]+1,i))
			return false;
		G2[u].pb(v);
		i-=sz[v];
	}
	reverse(G2[u].begin(),G2[u].end());
	return true;
}
 
void dfs3(int u)
{
	dfn[u]=++clo;
	for (int v:G2[u])
		dfs3(v);
}
 
bool dfs4(int u)
{
	sort(G[u].begin(),G[u].end(),[](const int a,const int b) {
		return dfn[a]<dfn[b];
	});
	if (++clo!=dfn[u])
		return false;
	for (int v:G[u])
		if (!dfs4(v))
			return false;
	return true;
}
 
bool solve()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
	}
	dfs1(1);
	LL step=0;
	for (int i=1;i<=n;i++)
	{
		int u=pos[i];
		step+=dep[u];
		if (chd[u])
		{
			bool flag=false;
			for (int j=fa[pos[i-1]];j;j=fa[j])
				if (j==u)
				{
					flag=true;
					break;
				}
			for (int j=u;j!=1;j=fa[j])
				swap(a[j],a[fa[j]]);
			int st=flag?fa[pos[i-1]]:u;
			for (int j=st;j!=1;j=fa[j])
				if (a[fa[j]]!=a[j]-1)
					return false;
			for (int j=st;j;j=fa[j])
			{
				vis[j]=true;
				post_order[poc++]=j;
			}
			break;
		}
		vis[u]=true;
		post_order[poc++]=u;
		chd[fa[u]]--;
	}
	dfs2(1);
	assert(poc>0);
	if (!check(0,poc-1))
		return false;
	dfs3(1);
	for (int i=1;i<=n;i++)
		if (!vis[i])
			dfn[i]=a[i];
	clo=0;
	if (!dfs4(1))
		return false;
	puts("YES");
	printf("%lld\n",step);
	for (int i=1;i<=n;i++)
		printf("%d ",dfn[i]);
	return true;
}
 
int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	if (!solve())
		puts("NO");
	return 0;
}