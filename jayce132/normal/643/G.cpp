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
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=(1<<19)+20;
const int inf=0x3f3f3f3f;
int LIM;

#define pii pair<int,int>
struct Node {
	pii a[5];
	Node(pii x=mkr(0,0)){ a[0]=x;REP(i,1,LIM-1)a[i]=mkr(0,0); }

	
	void insert(pii x)
	{
		int mn=inf;
		REP(i,0,LIM-1)
		{
			if(a[i].fi==x.fi)return a[i].se+=x.se,void();
			else chkmin(mn,a[i].se);
		}
		chkmin(mn,x.se);
		REP(i,0,LIM-1)a[i].se-=mn;
		x.se-=mn;
		if(x.se)
		{
			REP(i,0,LIM-1)if(a[i].se==0)return a[i]=x,void();
		}
	}
};

inline Node operator + (Node a,Node b)
{
	REP(i,0,LIM-1)if(b.a[i].se)
		a.insert(b.a[i]);
	return a;
}
struct node {
	Node s;
	int lz;
};

#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r


node c[maxn];
int a[maxn],n;

void make_tree(int o,int l,int r)
{
	if(l==r)return (c[o].s=Node(mkr(a[l],1) )),void();
	int mid=l+r>>1;
	make_tree(left);
	make_tree(right);
	c[o].s=c[lc].s+c[rc].s;
}

inline void Set(int o,int d,int l,int r){ c[o].s=Node(mkr(d,r-l+1));c[o].lz=d;}

inline void pushdown(int o,int l,int r)
{
	int mid=l+r>>1;
	if(c[o].lz)
	{
		Set(lc,c[o].lz,l,mid);
		Set(rc,c[o].lz,mid+1,r);
		c[o].lz=0;
	}
}

void update(int ql,int qr,int d,int o,int l,int r)
{
	if(ql<=l && r<=qr)return Set(o,d,l,r),void();
	int mid=l+r>>1;
	pushdown(o,l,r);
	if(ql<=mid)update(ql,qr,d,left);
	if(qr>mid)update(ql,qr,d,right);
	c[o].s=c[lc].s+c[rc].s;
}

Node query(int ql,int qr,int o,int l,int r)
{
	if(ql<=l && r<=qr)return c[o].s;
	int mid=l+r>>1;
	pushdown(o,l,r);
	if(qr<=mid)return query(ql,qr,left);
	else if(ql>mid)return query(ql,qr,right);
	else return query(ql,qr,left)+query(ql,qr,right);
}
int m,p;

inline void init()
{
	n=read();m=read();p=read();	LIM=(100)/p;
	REP(i,1,n)a[i]=read();
	make_tree(1,1,n);
}

inline void doing()
{
	REP(i,1,m)
	{
		int op=read(),l=read(),r=read();
		if(op==1)update(l,r,read(),1,1,n);
		else {
			Node c=query(l,r,1,1,n);
			int num=0;
			REP(i,0,LIM-1)if(c.a[i].se>0)num++;
			printf("%d ",num);REP(i,0,LIM-1)if(c.a[i].se>0)printf("%d ",c.a[i].fi);puts("");
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}