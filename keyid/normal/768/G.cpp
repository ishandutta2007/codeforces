#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;

struct edge
{
	int to,nxt;
}e[MAXN];

int n,ec,first[MAXN],son[MAXN],size[MAXN],ans[MAXN];
multiset <int> anc,chd,oth;

void addedge(int u,int v)
{
	e[ec]=(edge){v,first[u]};
	first[u]=ec++;
}

void dfs1(int u)
{
	int maxson=0;
	size[u]=1;
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		dfs1(v);
		if (size[v]>maxson)
		{
			maxson=size[v];
			son[u]=v;
		}
		size[u]+=size[v];
	}
}

void add_subtree(int u)
{
	oth.erase(oth.find(size[u]));
	chd.insert(size[u]);
	for (int i=first[u];i!=-1;i=e[i].nxt)
		add_subtree(e[i].to);
}

void clear(int u)
{
	oth.insert(size[u]);
	chd.erase(chd.find(size[u]));
	for (int i=first[u];i!=-1;i=e[i].nxt)
		clear(e[i].to);
}

void update(int &max1,int &max2,int x)
{
	if (max1<=x)
	{
		max2=max1;
		max1=x;
	}
	else if (max2<x)
		max2=x;
}

int query(multiset <int> &s,int large,int small,int d=0)
{
	if (small==INT_MAX) return n-1;
	int ret=INT_MAX;
	multiset <int> :: iterator it=s.upper_bound((large-small+2*d)/2);
	if (it!=s.end())
		ret=small+*it-d;
	if (it!=s.begin())
	{
		--it;
		ret=min(ret,large-(*it-d));
	}
	return ret;
}

void dfs2(int u)
{
	oth.erase(oth.find(size[u]));
	anc.insert(size[u]);
	int mins=INT_MAX,max1=-1,max2=-1;
	for (int i=first[u];i!=-1;i=e[i].nxt)
		update(max1,max2,size[e[i].to]);
	update(max1,max2,n-size[u]);
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=son[u])
		{
			mins=min(mins,size[v]);
			dfs2(v);
			clear(v);
		}
	}
	ans[u]=max1;
	if (son[u])
	{
		dfs2(son[u]);
		anc.erase(anc.find(size[u]));
		bool flag=size[son[u]]>n-size[u];
		if (flag)
			ans[u]=min(ans[u],query(chd,size[son[u]],min(n-size[u]?n-size[u]:INT_MAX,mins)));
		for (int i=first[u];i!=-1;i=e[i].nxt)
		{
			int v=e[i].to;
			if (v!=son[u])
				add_subtree(v);
		}
		if (!flag)
		{
			ans[u]=query(oth,n-size[u],min(mins,size[son[u]]));
			ans[u]=min(ans[u],query(anc,n-size[u],min(mins,size[son[u]]),size[u]));
		}
		if (mins!=INT_MAX)
			ans[u]=max(ans[u],max2);
	}
	else
		anc.erase(anc.find(size[u]));
	chd.insert(size[u]);
}

int main()
{
	int root;
	scanf("%d",&n);
	fill(first+1,first+n+1,-1);
	for (int i=0;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if (u==0) root=v;
		else addedge(u,v);
	}
	dfs1(root);
	for (int i=1;i<=n;i++) oth.insert(size[i]);
	dfs2(root);
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}