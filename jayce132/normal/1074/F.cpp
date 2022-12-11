#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=2e5+20;

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int n,q;

struct Node {
	int s,lz;
	void Merge(Node lc,Node rc,int l,int r) {
		if(lz)s=r-l+1;
		else s=lc.s+rc.s;
	}
};

Node c[maxn<<2];

#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r

int deep[maxn],fa[maxn],top[maxn],son[maxn],sz[maxn],dfn[maxn],times,low[maxn];

void dfs(int u)
{
	sz[u]=1;
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa[u])continue;
		fa[v]=u; deep[v]=deep[u]+1;
		dfs(v);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])son[u]=v;
	}
}

void dfs1(int u)
{
	dfn[u]=++times;
	if(son[u])top[son[u]]=top[u],dfs1(son[u]);
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa[u] || v==son[u])continue;
		top[v]=v;
		dfs1(v);
	}
	low[u]=times;
}


inline void init()
{
	n=read();q=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	deep[1]=1; dfs(1);
	top[1]=1; dfs1(1);
}

inline bool In(int u,int v){ return dfn[u]<=dfn[v] && dfn[v]<=low[u];}

inline int Lowbit(int u,int tp)
{
	if(In(son[tp],u))return son[tp];
	u=top[u];
	while(fa[u]!=tp)u=top[fa[u]];
	return u;
}

#define pii pair<int,int>

set<pii >s;

inline void Add(int o,int d){ c[o].lz+=d;}

void update(int ql,int qr,int d,int o,int l,int r)
{
	if(ql>qr)return;
	if(ql<=l && r<=qr)
	{
		Add(o,d);
		if(c[o].lz)c[o].s=r-l+1;
		else c[o].s=l==r?0:c[lc].s+c[rc].s;
	}else {
		int mid=(l+r)>>1;
		if(ql<=mid)update(ql,qr,d,left);
		if(qr>mid)update(ql,qr,d,right);
		c[o].Merge(c[lc],c[rc],l,r);
	}
}

inline void doing()
{
	REP(i,1,q)
	{
		int u=read(),v=read(),d;
		if(u>v)swap(u,v);
		if(s.count(mkr(u,v))) d=-1,s.erase(mkr(u,v));
		else d=1,s.insert(mkr(u,v));
		if(deep[u]>deep[v])swap(u,v);

		if(In(u,v))
		{
			int t=Lowbit(v,u);
			update(dfn[t],dfn[v]-1,d,1,1,n);
			update(low[v]+1,low[t],d,1,1,n);
		}else
		{
			update(1,min(dfn[u],dfn[v])-1,d,1,1,n);
			update(min(low[u],low[v])+1,max(dfn[u],dfn[v])-1,d,1,1,n);
			update(max(low[u],low[v])+1,n,d,1,1,n);
		}
		printf("%d\n",n-c[1].s);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}