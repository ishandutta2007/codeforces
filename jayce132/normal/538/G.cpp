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
#define int ll

inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int inf=0x3f3f3f3f;
const int maxn=2e5+20;

int n,l;

struct point {
	int tim,pos,timp;
};
point A[maxn],B[maxn];
int a[maxn*10],b[maxn*10];

inline void init()
{
	n=read();l=read();
	REP(i,1,n)
	{
		int tim=read(),x=read(),y=read();
		A[i]=(point){tim,x+y};
		B[i]=(point){tim,x-y};
	}
}

inline void Solve(int l,int r,int b,int &nl,int &nr)
{
	if(b==0 )
	{
		nl=-inf,nr=inf;
		if(l<=0 && 0<=r)return;
		else return swap(nl,nr),void();
	}
	if(b<0)l=-l,r=-r,b=-b,swap(l,r);
	nr=r/b-(r%b<0);
	nl=l/b+(l%b>0);
}

inline void work(point *A,int *a)
{
	REP(i,1,n)if(A[i].tim-A[i].pos&1)puts("NO"),exit(0);
	REP(i,1,n)A[i].timp=A[i].tim%l;
	sort(A+1,A+n+1,[](point x,point y){ return x.timp==y.timp?x.tim<y.tim:x.timp<y.timp;});
	int L=-l,R=l;
	REP(i,1,n)
	{
		int x=A[i].timp-A[i-1].timp,b=(A[i].tim-x-A[i-1].tim)/l,cha=A[i].pos-A[i-1].pos;
		int nl,nr,l=cha-x,r=cha+x;
		Solve(l,r,b,nl,nr);
		chkmax(L,nl);
		chkmin(R,nr);
	}
	{
		int x=l-A[n].timp,b=(0-A[n].tim-x)/l,cha=-A[n].pos;
		int nl,nr,l=cha-x,r=cha+x;
		Solve(l,r,b,nl,nr);
		chkmax(L,nl);
		chkmin(R,nr);
	}

	int p;
	L+=L-l&1; R-=R-l&1;
	if(L>R)puts("NO"),exit(0);
	else if(L<=R)p=L;
	int lstsum=0,num=0;
	REP(i,1,n)
	{
		int rest=A[i].pos-(A[i].tim/l)*p;
		int now=A[i].timp;
		int sl=(rest-lstsum+(now-num))/2;
		REP(j,1,sl)a[++num]=1,lstsum++;
		REP(j,1,now-num)a[++num]=-1,lstsum--;
	}
	int now=l;
	int sl=(p-lstsum+(now-num))/2;
	REP(j,1,sl)a[++num]=1,lstsum++;
	REP(j,1,now-num)a[++num]=-1,lstsum--;
	
	
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("CF538G.in","r",stdin);
	freopen("CF538G.out","w",stdout);
#endif
	init();
	work(A,a);
	work(B,b);
	REP(i,1,l)if(~a[i])
	{
		if(~b[i])putchar('R'); //(x,y)->(x+1,y)
		else putchar('U'); //(x,y)->(x,y+1)
	}else
	{
		if(~b[i])putchar('D'); //(x,y)->(x,y-1)
		else putchar('L'); //(x,y)->(x-1,y)
	}
	return 0;
}