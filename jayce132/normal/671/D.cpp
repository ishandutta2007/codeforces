#include <bits/stdc++.h>
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

const int maxn=3e5+20;
const ll inf=1ll<<60;

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int n,m;

struct Node {
	ll val,lz;int ls,rs,dis,id,tp;
};
Node c[maxn<<1];
int tot,deep[maxn];

inline void Add(int x,ll d){ c[x].val+=d; c[x].lz+=d;}

inline void pushdown(int x)
{
	if(c[x].lz)
	{
		if(c[x].ls)Add(c[x].ls,c[x].lz);
		if(c[x].rs)Add(c[x].rs,c[x].lz);
		c[x].lz=0;
	}
}

int merge(int x,int y)
{
	if(!x || !y)return x|y;
	pushdown(x); pushdown(y);
	if(c[x].val>c[y].val)swap(x,y);
	c[x].rs=merge(c[x].rs,y);
	if(c[c[x].ls].dis<c[c[x].rs].dis)swap(c[x].ls,c[x].rs);
	c[x].dis=c[c[x].rs].dis+1;
	return x;
}

inline ll Top(int &rt,int u)
{
	while(rt && deep[c[rt].tp]>deep[u])
	{
		rt=merge(c[rt].ls,c[rt].rs);
	}
	return !rt?inf:c[rt].val;
}

struct Chain {
	int u,v,w;
};
Chain C[maxn];
vector<int>cm[maxn];

inline void init()
{
	n=read();m=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	REP(i,1,m)
	{
		int u=read(),v=read(),w=read();
		C[i].v=u; C[i].u=v; C[i].w=w;
		cm[u].push_back(i);
	}
}

int rt[maxn];

void dfs(int u,int fa)
{
	rt[u]=++tot; c[tot].tp=u;
	for(int i:cm[u])
	{
		++tot; c[tot].val=C[i].w;
		c[tot].tp=C[i].u;
		rt[u]=merge(rt[u],tot);
	}
	
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		deep[v]=deep[u]+1;
		dfs(v,u);
		ll mnu=Top(rt[u],u),mnv=Top(rt[v],u);
		if(mnu==inf || mnv==inf)puts("-1"),exit(0);
		Add(rt[u],mnv); Add(rt[v],mnu);
		rt[u]=merge(rt[u],rt[v]);
	}
}

inline void doing()
{
	deep[1]=1; dfs(1,0);
	ll x=Top(rt[1],1);
	printf("%lld\n",x);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}