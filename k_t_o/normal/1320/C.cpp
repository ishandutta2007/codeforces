//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx") 
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3f
#define y0 _lxybz_
#define y1 _ljmnzyzhhhoscartxdy_
typedef long double ld;
typedef long long ll;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize
#define lo(x) ((x)&(-(x)))
#define trav(a, x) for (auto &a : x)
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
const ld Pi = 4*atan((ld)1);
template<class T> void chmin(T &a,const T&b) { a = min(a, b); }
template<class T> void chmax(T &a,const T&b) { a = max(a, b); }
namespace IO{
template<class T> inline void read(T&ret)
{
	ret=0; int f=1; char c=getchar();
	while(c<48||c>57){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	ret*=f;
}
template<class T> inline void prin(const T&ret)
{
	if(!ret){putchar(48);return;} static T o; o=ret;
	if(o<0){putchar('-');o=-o;}
	static int op[25],tt; tt=0;
	while(o){
		op[++tt]=o%10;
		o/=10;
	}
	for(int i=tt;i;--i)putchar(op[i]+48);
}
template<class T> inline void pri_(const T&ret)
{
	prin(ret);putchar(' ');
}
template<class T> inline void priE(const T&ret)
{
	prin(ret);putchar('\n');
}
}
using namespace IO;

#define N 405000
#define M 1000500
#define MO 
struct node {
	int o, w;
	bool operator < (const node& a)const{
		if(o==a.o)return w>a.w;
		return o<a.o;
	}
}a[N],b[N],c[N],d[N];
struct P {
	int x, y, z;
	bool operator < (const P& a)const{
		return x<a.x;
	}
}A[N];
int u,v,n,m,ss,Ans,uu,st[N],tp1,tp2,p;
struct BIT {
#define ls (p<<1)
#define rs ((p<<1)|1)
#define O 2150000
int ad[O],su[O];
inline void pudo(int p, int l, int r)
{
	int mi=l+r>>1;
	ad[ls]+=ad[p];
	ad[rs]+=ad[p];
	su[ls]+=ad[p];
	su[rs]+=ad[p];
	ad[p]=0;
}

inline void upd(int p)
{
	su[p]=max(su[ls],su[rs]);
}

void ins(int p, int l, int r, int x, int y, int w)
{
	if(x<=l&&r<=y){
		ad[p]+=w;
		su[p]+=w;
		return;
	}
	if(x>r||y<l)return;
	pudo(p,l,r);
	int mi=l+r>>1;
	ins(ls,l,mi,x,y,w);
	ins(rs,mi+1,r,x,y,w);
	upd(p);
}

}T; 

inline void _Sol_()
{
	read(n);read(m);read(p);
	F(i,1,n){
		read(a[i].o);read(a[i].w);
	}
	sort(a+1,a+n+1);
	F(i,1,n){
		while(tp1&&a[st[tp1]].w>=a[i].w)--tp1;
		st[++tp1]=i;
	}
	F(i,1,tp1){
		c[i]=a[st[i]];
	}
	
	F(i,1,m){
		read(b[i].o);read(b[i].w);
	}
	sort(b+1,b+m+1);
	F(i,1,m){
		while(tp2&&b[st[tp2]].w>=b[i].w)--tp2;
		st[++tp2]=i;
	}
	F(i,1,tp2){
		d[i]=b[st[i]];
	}
	
	F(i,1,tp2){
		u=d[i-1].o; v=d[i].o;
		T.ins(1,1,M,u+1,M,d[i-1].w-d[i].w);
	}
	
	F(i,1,p){
		read(A[i].x);read(A[i].y);read(A[i].z);
		++A[i].x; ++A[i].y;
	}
	sort(A+1,A+p+1);
	
	Ans=-2100000000; u=1;
	F(i,1,tp1){
		ss=-c[i].w;
		while(u<=p&&A[u].x<=c[i].o){
			if(A[u].y<=d[tp2].o)T.ins(1,1,M,A[u].y,M,A[u].z);
			++u;
		}
		uu=T.su[1];
		ss+=uu;
		chmax(Ans,ss);
	}
	priE(Ans);
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}
/*
2 3 3
2 3
4 7
2 4
3 2
5 11
1 2 0
2 1 0
3 4 0
*/