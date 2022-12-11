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

const int maxn=3e5+20;
const int lim=1e6;

struct node {
	int mx,lz;
};
node c[(1<<21)+20];

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
	if(ql<=l && r<=qr)return Add(o,d);
	pushdown(o);
	int mid=l+r>>1;
	if(ql<=mid)update(ql,qr,d,left);
	if(qr>mid)update(ql,qr,d,right);
	c[o].mx=max(c[lc].mx,c[rc].mx);
}

int query(int o,int l,int r)
{
	if(l==r)return c[o].mx>0?l:-1;
	int mid=l+r>>1;
	pushdown(o);
	if(c[rc].mx>0)return query(right);
	else return query(left);
}

int n,m;
int a[maxn],b[maxn];

inline void init()
{
	n=read();m=read();
	REP(i,1,n)a[i]=read(),update(1,a[i],1,1,1,lim);
	REP(i,1,m)b[i]=read(),update(1,b[i],-1,1,1,lim);
}

inline void doing()
{
	int q=read();
	while(q--)
	{
		int op=read(),i=read(),x=read();
		if(op==1)update(1,a[i],-1,1,1,lim),update(1,a[i]=x,1,1,1,lim);
		else update(1,b[i],1,1,1,lim),update(1,b[i]=x,-1,1,1,lim);
		printf("%d\n",query(1,1,lim));
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}