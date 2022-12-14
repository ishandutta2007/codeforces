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

#define N 300500
#define MO


struct BIT {
#define ls (p<<1)
#define rs ((p<<1)|1)
#define M 1100000
long long ad[M],su[M];
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

void ins(int p, int l, int r, int x, int y, ll w)
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

long long que(int p, int l, int r, int x, int y)
{
	if(x<=l&&r<=y)return su[p];
	if(x>r||y<l)return -1e18;
	pudo(p,l,r);
	int mi=l+r>>1;
	return max(que(ls,l,mi,x,y),que(rs,mi+1,r,x,y));
}

}T;  
int n,h[N],b[N],st[N],tp;
ll d[N];
inline void _Sol_()
{
	read(n); F(i,1,n)read(h[i]); F(i,1,n)read(b[i]);
	st[tp=1]=0;
	F(i,1,n){
		while(h[i] < h[st[tp]]) {
			T.ins(1,0,n,st[tp-1],st[tp]-1,-b[st[tp]]);
			--tp;
		}
		T.ins(1,0,n,st[tp],i-1,b[i]);
		st[++tp]=i;
		d[i] = T.que(1,0,n,0,i-1);
		T.ins(1,0,n,i,i,d[i]);
	}
	priE(d[n]);
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}