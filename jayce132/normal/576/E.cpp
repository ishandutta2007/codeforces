#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline void myassert(bool a,string s){ if(!a)cerr<<s<<endl,exit(0);}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=5e5+20;

struct Edge {
	int u,v;
};
Edge E[maxn];
int COL[maxn];

#define pii pair<int,int>
pii sx[maxn<<1]; int tx;
int n,m,k,q;

struct Query {
	int id,col;
};
Query qu[maxn];
int nxt[maxn];

int ID[maxn][52];

inline void init()
{
	n=read();m=read();k=read();q=read();
	REP(i,1,m)
	{
		int u=read(),v=read();
		E[i]=(Edge){u,v};
	}
	REP(i,1,q)
	{
		int id=read(),col=read();
		qu[i]=(Query){id,col};
		sx[++tx]=mkr(E[id].u,col);
		sx[++tx]=mkr(E[id].v,col);
	}
	static int num[maxn];
	REP(i,1,m)num[i]=q;
	DREP(i,q,1)nxt[i]=num[qu[i].id],num[qu[i].id]=i;
	sort(sx+1,sx+tx+1); tx=unique(sx+1,sx+tx+1)-sx-1;
	REP(i,1,tx)ID[sx[i].fi][sx[i].se]=i;
}

struct Modify {
	int id,col;
};

struct node {
	vector<Modify>s;
};
node c[(1<<20)+20];
#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r

void update(int ql,int qr,Modify d,int o,int l,int r)
{
	if(ql<=l && r<=qr)return c[o].s.push_back(d),void();
	int mid=l+r>>1;
	if(ql<=mid)update(ql,qr,d,left);
	if(qr>mid)update(ql,qr,d,right);
}

int fa[maxn<<1],faw[maxn<<1],sz[maxn<<1];
vector<pii >rem;

inline int fin(int x,int &w)
{
	w=0;
	while(x!=fa[x])w^=faw[x],x=fa[x];
	return x;
}

inline bool ask(int x,int y)
{
	int xw=0,yw=0;
	int u=fin(x,xw),v=fin(y,yw);
	if(u==v && (xw^yw)==0)return 0;
	else return 1;
}

inline void merge(int x,int y)
{
	int xw=0,yw=0;
	int u=fin(x,xw),v=fin(y,yw);
	if(sz[u]<sz[v])swap(u,v),swap(xw,yw);
	rem.push_back(mkr(u,v));
	if(u==v)return;
	fa[v]=u;
	sz[u]+=sz[v];
	faw[v]=yw^xw^1;
}

inline void undo()
{
	int u=rem.back().fi,v=rem.back().se;
	rem.pop_back();
	if(u!=v)fa[v]=v,sz[u]-=sz[v],faw[v]=0;
}

void dfs(int o,int l,int r)
{
	for(Modify t:c[o].s)
	{
		int id=t.id,col=t.col;
		int u=ID[E[id].u][col],v=ID[E[id].v][col];
		merge(u,v);
	}

	if(l==r)
	{
		int id=qu[l].id,col=qu[l].col;
		int u=ID[E[id].u][col],v=ID[E[id].v][col];
		if(ask(u,v))puts("YES"),COL[id]=col;
		else puts("NO"),col=COL[id];
		update(l+1,nxt[l],(Modify){id,col},1,1,q);
	}else
	{
		int mid=l+r>>1;
		dfs(left);
		dfs(right);
	}
	REP(i,0,SZ(c[o].s)-1)undo();
}

inline void doing()
{             
	REP(i,1,tx)fa[i]=i,sz[i]=1;
	dfs(1,1,q);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF576E.in","r",stdin);
	freopen("CF576E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}