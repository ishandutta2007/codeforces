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
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=3e5+20;

int n,m;

struct Edge {
	int u,v,w,id;
};

Edge E[maxn];
int Ed[maxn];

inline bool operator <(Edge a,Edge b) { return a.w==b.w?a.u==b.u?a.v<b.v:a.u<b.u:a.w<b.w;}
inline bool operator ==(Edge a,Edge b){ return a.u==b.u && a.v==b.v && a.w==b.w;}

inline void init()
{
	n=read();m=read();
}

struct node {
	int ch[2],fa,sz,si,id,mxid,rev;
};
node c[maxn<<1];
int tot;

#define lc (c[x].ch[0])
#define rc (c[x].ch[1])

inline void Merge(int x)
{
	c[x].mxid=c[x].id;
	if(E[c[x].mxid].w<E[c[lc].mxid].w)c[x].mxid=c[lc].mxid;
	if(E[c[x].mxid].w<E[c[rc].mxid].w)c[x].mxid=c[rc].mxid;
	c[x].sz=c[lc].sz+c[rc].sz+c[x].si;
}

inline bool isroot(int x){ return c[c[x].fa].ch[0]!=x && c[c[x].fa].ch[1]!=x;}

inline void rotate(int x)
{
	int y=c[x].fa,z=c[y].fa,k=c[y].ch[1]==x;
	if(!isroot(y))c[z].ch[c[z].ch[1]==y]=x; c[x].fa=z;
	c[y].ch[k]=c[x].ch[k^1]; c[c[y].ch[k]].fa=y;
	c[x].ch[k^1]=y; c[y].fa=x;
	Merge(y); Merge(x);
}

inline void Reverse(int x){ swap(lc,rc); c[x].rev^=1;}

inline void pushdown(int x)
{
	if(c[x].rev)
	{
		if(lc)Reverse(lc);
		if(rc)Reverse(rc);
		c[x].rev=0;
	}
}

inline void Push(int x)
{
	static int st[maxn],top; top=0;
	while(!isroot(x))st[++top]=x,x=c[x].fa; pushdown(x);
	DREP(i,top,1)pushdown(st[i]);
}

inline void splay(int x)
{
	Push(x);
	while(!isroot(x))
	{
		int y=c[x].fa,z=c[y].fa;
		if(!isroot(y))
			(c[y].ch[1]==x)^(c[z].ch[1]==y)?rotate(x):rotate(y);
		rotate(x);
	}
}

inline void access(int x){ for(int y=0;x;y=x,x=c[x].fa)splay(x),c[x].si+=c[rc].sz,c[x].si-=c[y].sz,rc=y,Merge(x);}
inline void makeroot(int x){ access(x); splay(x); Reverse(x);}
inline int findroot(int x){ access(x);splay(x);while(lc)pushdown(x),x=lc; return splay(x),x;}
inline void link(int x,int y){ makeroot(x); makeroot(y); c[y].fa=x; c[x].si+=c[y].sz;}
inline void cut(int x,int y){ makeroot(x); access(y); splay(x); c[x].ch[1]=c[y].fa=0; Merge(x);}

struct Heap {
	priority_queue<Edge>p,q;
	inline void check(){ while(!q.empty() && p.top()==q.top())p.pop(),q.pop();}
	inline void push(Edge x){ p.push(x); check();}
	inline void pop(){ p.pop(); check();}
	inline Edge top(){ return p.top();}
	inline void del(Edge x){ q.push(x); check();}
}q;


int js;

inline void Check()
{
	while(1)
	{
		Edge t=q.top();
		int u=t.u,v=t.v;
		makeroot(u); access(v); splay(u);
		if(~c[v].sz&1)
		{
			int id=t.id;
			cut(E[id].u,Ed[id]);
			cut(E[id].v,Ed[id]); q.pop();
		}else break;
	}
}

inline void doing()
{
	js=n; tot=n;
	REP(i,1,n)c[i].si=c[i].sz=1;
	REP(i,1,m)
	{
		E[i].u=read();E[i].v=read();E[i].w=read(); E[i].id=i;
		int u=E[i].u,v=E[i].v,w=E[i].w;
		if(findroot(u)==findroot(v))
		{
			makeroot(u); access(v); splay(v);
			int mxid=c[v].mxid;
			if(E[mxid].w>w)
			{
				cut(E[mxid].u,Ed[mxid]);
				cut(E[mxid].v,Ed[mxid]);
				Ed[i]=++tot; c[tot].id=i; 
				link(u,tot); link(v,tot);
				q.push(E[i]); q.del(E[mxid]);
			}
		}else
		{
			makeroot(u); makeroot(v);
			int a=c[u].sz,b=c[v].sz;
			if(a&1 && b&1)js-=2;
			Ed[i]=++tot; c[tot].id=i;
			link(u,tot); link(v,tot);
			q.push(E[i]);
		}
		if(js)puts("-1");
		else Check(),printf("%d\n",q.top().w);;
		
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF603E.in","r",stdin);
	freopen("CF603E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}