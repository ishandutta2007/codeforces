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
#define SZ(A) ((int)A.size())
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e5+20;
const ll inf=1ll<<60;

struct node {
	int v,next; ll w;
};
node e[maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v,ll w){ e[++cnt]=(node){v,start[u],w};start[u]=cnt;}

int n,k;
ll pre[maxn],suf[maxn];
int w[maxn],g[maxn];
int fa[maxn];ll faw[maxn];
int R[maxn];

int chain[maxn],tp,now;
ll dj[maxn];

void dfs(int u)
{
	chain[++tp]=u; 
	while(now<tp && dj[tp]-dj[now+1]>k)now++;
	R[u]=chain[now]-1;
	int Now=now;
	EREP(i,u)dj[tp+1]=dj[tp]+e[i].w,dfs(e[i].v),now=Now;
	--tp;
}

struct Node {
	ll ans,smx,mx,lz;
	//inline void Merge(Node lc,Node rc) {
	//	smx=max(lc.smx,rc.smx);
	//	ans=min(min(lc.ans,rc.ans),lc.smx-rc.mx);
	//}
};
Node c[(1<<18)+20];

#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r

inline void Add(int o,ll d){ c[o].ans+=d; c[o].smx+=d; c[o].lz+=d;}

inline void pushdown(int o)
{
	if(c[o].lz)
	{
		Add(lc,c[o].lz);
		Add(rc,c[o].lz);
		c[o].lz=0;
	}
}

ll queryans(ll smx,int o,int l,int r)
{
	if(l==r)return smx==-inf?inf:smx-c[o].mx;
	int mid=l+r>>1; //ll ans=inf;
	pushdown(o);
	if(smx<c[lc].smx)return min(queryans(smx,left),c[o].ans);
	else return min(smx-c[lc].mx,queryans(smx,right));
}

void Merge(int o,int l,int r)
{
	int mid=l+r>>1;
	c[o].smx=max(c[lc].smx,c[rc].smx);
	c[o].ans=queryans(c[lc].smx,right);
}

inline void make_tree(int o,int l,int r)
{
	if(l==r)return c[o].ans=inf,c[o].smx=c[o].mx=suf[l],void();
	int mid=l+r>>1;
	make_tree(left);
	make_tree(right);
	c[o].mx=max(c[lc].mx,c[rc].mx); Merge(o,l,r);//c[o].Merge(c[lc],c[rc]); 
}

void update(int ql,int qr,ll d,int o,int l,int r)
{
	if(ql<=l && r<=qr)return Add(o,d),void();
	int mid=l+r>>1;
	pushdown(o);
	if(ql<=mid)update(ql,qr,d,left);
	if(qr>mid)update(ql,qr,d,right);
	Merge(o,l,r);//c[o].Merge(c[lc],c[rc]);
}

ll Pre[maxn];
int om[maxn],lm[maxn],rm[maxn];

void query(int ql,int qr,int o,int l,int r)
{
	if(ql<=l && r<=qr)return ++tp,om[tp]=o,lm[tp]=l,rm[tp]=r,void();
	int mid=l+r>>1;
	pushdown(o);
	if(ql<=mid)query(ql,qr,left);
	if(qr>mid)query(ql,qr,right);
}

int Query(ll x,int o,int l,int r)
{
	if(l==r)return l;
	pushdown(o);
	int mid=l+r>>1;
	if(queryans(max(x,c[lc].smx),right)<=k)return Query(max(x,c[lc].smx),right);
	else return Query(x,left);
}

inline int QUERY(int l,int r)
{
	tp=0;
	query(l,r,1,1,n);
	Pre[0]=-inf; REP(i,1,tp)Pre[i]=max(Pre[i-1],c[om[i]].smx);
	DREP(i,tp,1)
	{
		if(queryans(Pre[i-1],om[i],lm[i],rm[i])<=k)return Query(Pre[i-1],om[i],lm[i],rm[i]);
	}
	return l;
}

inline void init()
{
	n=read();k=read();
	REP(i,1,n-1)w[i]=read();
	REP(i,1,n)g[i]=read();
	REP(i,1,n-1)pre[i]=pre[i-1]+g[i]-w[i];
	REP(i,2,n)suf[i]=suf[i-1]+g[i]-w[i-1];
	static int st[maxn]; int top=0;
	REP(i,1,n)
	{
		while(top && pre[st[top]-1]>pre[i-1])faw[st[top]]=pre[st[top]-1]-pre[i-1],fa[st[top--]]=i;
		st[++top]=i;
	}
	REP(i,1,n)if(!fa[i])fa[i]=n+1;
	REP(i,1,n)addedge(fa[i],i,faw[i]);
	now=1; dfs(n+1);
	make_tree(1,1,n);
}

int ans;

void dfs1(int u)
{
	if(faw[u])update(fa[u]-1,n,faw[u],1,1,n);
	if(u<=R[u])chkmax(ans,QUERY(u,R[u])-u+1);
	EREP(i,u)dfs1(e[i].v);
	if(faw[u])update(fa[u]-1,n,-faw[u],1,1,n);
}

inline void doing()
{
	//int MAX=0;REP(i,1,n)chkmax(MAX,R[i]-i+1);
	//cerr<<MAX<<endl;
	dfs1(n+1);
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("sightseeing.in","r",stdin);
	freopen("sightseeing.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}