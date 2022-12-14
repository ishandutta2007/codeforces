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

#define N 500500
#define MO 
int C[N][2],A[N],n,m,c[N][2],u,v,l,r,op[N],k,q[N],qn,di[N],tot,a[N],pr[N],fl[N];
inline void _Sol_()
{
	read(n);read(m);
	F(i,1,m){
		read(u);read(v);
		C[++tot][0]=v;C[tot][1]=A[u];A[u]=tot;
		c[tot][0]=u;c[tot][1]=a[v];a[v]=tot;
	}
	read(k);
	F(i,1,k)read(op[i]);
	memset(di,-1,sizeof di);
	di[op[k]]=0;q[qn=1]=op[k];
	F(q1,1,qn){
		u=q[q1];
		for(int o=a[u];o;o=c[o][1]){
			v=c[o][0];
			if(di[v]!=-1)continue;
			di[v]=di[u]+1;
			pr[v]=u;
			q[++qn]=v;
		}
	}
	F(u,1,n){
		for(int o=A[u];o;o=C[o][1]){
			v=C[o][0]; if(v==pr[u])continue;
			if(di[v]==di[pr[u]])fl[u]=1;
		}
	}
	l=0; r=0;
	F(i,1,k-1){
		u=op[i]; v=op[i+1];
		if(di[v]!=di[u]-1){
			++l; ++r; continue;
		}
		if(fl[u])++r;
	}
	pri_(l);priE(r);
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}