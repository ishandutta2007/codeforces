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

#define N 280
#define MO 
#define FF fflush(stdout); 
int q,n,o,u,v,j;
ll k,a[N][N];
ll _u[N],op;
inline void _Sol_()
{
	read(n);
	F(i,1,n)
	F(j,1,n)a[i][j]=0;
	_u[0]=1; F(i,1,55)_u[i]=_u[i-1]*2;
	F(_,3,n+n-1){
		o=_-3; op=0;
		F(i,1,n){
			j=_-i;
			if(j<1)break;
			a[i][j]=op*_u[o];
			op^=1;
		}
	}
	F(i,1,n){
		F(j,1,n)pri_(a[i][j]);puts("");
		FF
	}
	
	read(q);
	F(i,1,q){
		read(k);
		u=1; v=1;
		printf("%d %d\n",u,v); FF
		F(_,3,n+n-1){
			o=_-3;
			if(u==n){
				++v;
			} else if(v==n){
				++u;
			} else {
				if(k&_u[o]){
					if(a[u+1][v])++u; else ++v;
				} else {
					if(a[u+1][v])++v; else ++u;
				}
			}
			printf("%d %d\n",u,v); FF
		}
		printf("%d %d\n",n,n); FF
	}
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}