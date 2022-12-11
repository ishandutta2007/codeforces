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
#include<cassert>
#include<vector>
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

const int maxn=6e5+20;
const int inf=0x3f3f3f3f;

int n,m,k;
int l[maxn],r[maxn],p[maxn];
int tx,sx[maxn];
vector<int>to[maxn];

struct node {
	int mn,ls,rs;
};
node c[maxn<<5];
int rt[maxn],tot;

int update(int x,int d,int o,int l,int r)
{
	int no=++tot;
	c[no]=c[o];
	if(l==r)return chkmax(c[no].mn,d),no;
	int mid=l+r>>1;
	if(x<=mid)c[no].ls=update(x,d,c[no].ls,l,mid);
	else c[no].rs=update(x,d,c[no].rs,mid+1,r);
	int lc=c[no].ls,rc=c[no].rs;
	c[no].mn=inf;
	chkmin(c[no].mn,c[lc].mn);
	chkmin(c[no].mn,c[rc].mn);
	return no;
}

inline void init()
{
	n=read();m=read();k=read();
	REP(i,1,k)
	{
		l[i]=read();r[i]=read();p[i]=read();
		sx[++tx]=l[i]; sx[++tx]=r[i]; 
	}
	sort(sx+1,sx+tx+1); tx=unique(sx+1,sx+tx+1)-(sx+1);
	REP(i,1,k)l[i]=lower_bound(sx+1,sx+tx+1,l[i])-sx,r[i]=lower_bound(sx+1,sx+tx+1,r[i])-sx;
	REP(i,1,k)to[r[i]].push_back(i);
	REP(i,1,tx)
	{
		rt[i]=rt[i-1];
		for(int v:to[i])
		{
			rt[i]=update(p[v],l[v],rt[i],1,tx);
		}
	}
}

int query(int ql,int qr,int o,int l,int r)
{
	if(ql>qr || !o)return 0;
	if(ql<=l && r<=qr)return c[o].mn;
	int mid=(l+r)>>1;
	if(qr<=mid)return query(ql,qr,c[o].ls,l,mid);
	else if(ql>mid)return query(ql,qr,c[o].rs,mid+1,r);
	else return min(query(ql,qr,c[o].ls,l,mid),query(ql,qr,c[o].rs,mid+1,r));
}

inline void doing()
{
	REP(i,1,m)
	{
		int a=read(),b=read(),x=read(),y=read();
		int X=lower_bound(sx+1,sx+tx+1,x)-sx,Y=upper_bound(sx+1,sx+tx+1,y)-sx-1;
		if(query(a,b,rt[Y],1,tx)<X)puts("no");
		else puts("yes");
		
		fflush(stdout);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}