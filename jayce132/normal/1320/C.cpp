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

#define int ll

const int M=1e6+20;
const int LIM=1e6+1;

struct node {
	int mx,lz;
};
node c[(1<<22)+20];

#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r

struct mon{
	int x,y,c;
};
mon md[M];

int a[M],b[M];
int n,m,p;

const int inf=1ll<<60;

inline void Add(int o,int d)
{
	c[o].mx+=d; c[o].lz+=d;
}

inline void pushdown(int o)
{
	if(c[o].lz)Add(lc,c[o].lz),Add(rc,c[o].lz),c[o].lz=0;
}

void make_tree(int o,int l,int r)
{
	if(l==r)return c[o].mx=-a[l],void();
	int mid=l+r>>1;
	make_tree(left);
	make_tree(right);
	c[o].mx=max(c[lc].mx,c[rc].mx);
}

inline void update(int ql,int qr,int d,int o,int l,int r)
{
	if(ql<=l && r<=qr)return Add(o,d),void();
	int mid=l+r>>1;
	pushdown(o);
	if(ql<=mid)update(ql,qr,d,left);
	if(qr>mid)update(ql,qr,d,right);
	c[o].mx=max(c[lc].mx,c[rc].mx);
}

inline void init()
{
	n=read();m=read();p=read();
	memset(a,63,sizeof(a)); memset(b,63,sizeof(b));
	REP(i,1,n)
	{
		int x=read(),cost=read();
		chkmin(a[x],cost);
	}
	REP(i,1,m)
	{
		int x=read(),cost=read();
		chkmin(b[x],cost);
	}
	DREP(i,LIM,1)chkmin(b[i-1],b[i]);
	REP(i,1,p)
	{
		int x=read()+1,y=read()+1,cost=read();
		md[i]=(mon){x,y,cost};
	}
	sort(md+1,md+p+1,[](mon a,mon b){ return a.y<b.y;});
	make_tree(1,1,LIM);
}

inline void doing()
{
	int j=1;
	int ans=-inf;
	REP(i,1,LIM)
	{
		while(j<=p && md[j].y<=i)
		{
			update(md[j].x,LIM,md[j].c,1,1,LIM);
			j++;
		}
		chkmax(ans,c[1].mx-b[i]);
	}
	printf("%lld\n",ans);
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}