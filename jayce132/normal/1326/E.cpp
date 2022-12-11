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

const int maxn=3e5+20;

int p[maxn],q[maxn],n,id[maxn];

inline void init()
{
	n=read();
	REP(i,1,n)p[i]=read(),id[p[i]]=i;
	REP(i,1,n)q[i]=read();
}

struct node {
	int mx,lz;
};
node c[(1<<20)+20];
#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r

inline void Add(int o,int d){ c[o].mx+=d; c[o].lz+=d;}

inline void pushdown(int o)
{
	if(c[o].lz)
	{
		Add(lc,c[o].lz);
		Add(rc,c[o].lz);
		c[o].lz=0;
	}
}

void update(int ql,int qr,int d,int o,int l,int r)
{
	if(ql<=l && r<=qr)return Add(o,d),void();
	int mid=l+r>>1;
	pushdown(o);
	if(ql<=mid)update(ql,qr,d,left);
	if(qr>mid)update(ql,qr,d,right);
	c[o].mx=max(c[lc].mx,c[rc].mx);
}

inline void doing()
{
	int ans=n;
	update(1,id[n],1,1,1,n);
	REP(i,1,n)
	{
		while(c[1].mx<=0)
		{
			ans--;
			update(1,id[ans],1,1,1,n);
		}
		printf("%d ",ans);
		update(1,q[i],-1,1,1,n);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}