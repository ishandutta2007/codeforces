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
//typedef vector<int> vi;
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

#define M 3005
#define N 10005
#define MO
ll Ans,f[M][M];
int vi[N],a[N],si[N],st1[N],tt1,tt2,st2[N],fa[N],c[N][2],R[N],tot,n,u,v,_f[M][M],_g[M][M],V[M][M];
void df(int p, int pr,int de)
{
	int v;//D[_i][p]=de;
	fa[p]=pr;
	v=p;while(v){
		_g[fa[v]][p]=v;
		v=fa[v];
		_f[v][p]=1;
	}
	for(int o=a[p];o;o=c[o][1]){
		v=c[o][0];
		if(v==pr)continue;
		df(v,p,de+1);
	}
}

void fs(int p, int pr)
{
	int v; si[p]=1;
	for(int o=a[p];o;o=c[o][1]){
		v=c[o][0];
		if(v==pr)continue;
		fs(v,p);si[p]+=si[v];
	}
}

ll dp(int p, int q)
{
	if(V[p][q])return f[p][q];
	if(V[q][p])return f[q][p];
	V[p][q]=1;
	int v; 
	ll ss;
	for(int o=a[p];o;o=c[o][1]){
		if(vi[o>>1])continue;
		v=c[o][0];
		if(_f[v][q])ss=si[q]*(n-si[_g[v][q]]);
		else if(_f[q][v])ss=si[v]*(n-si[_g[q][v]]);
		else ss=si[v]*si[q];
		vi[o>>1]=1;
		ss+=dp(v,q);
		vi[o>>1]=0;
		chmax(f[p][q],ss);
	}
	for(int o=a[q];o;o=c[o][1]){
		if(vi[o>>1])continue;
		v=c[o][0];
		if(_f[v][p])ss=si[p]*(n-si[_g[v][p]]);
		else if(_f[p][v])ss=si[v]*(n-si[_g[p][v]]);
		else ss=si[v]*si[p];
		vi[o>>1]=1;
		ss+=dp(v,p);
		vi[o>>1]=0;
		chmax(f[p][q],ss);
	}
	return f[p][q];
}

void dfs(int p, int pr)
{
	int v; ll ss;
	for(int o=a[p];o;o=c[o][1]){
		v=c[o][0];
		if(v==pr)continue;
		vi[o>>1]=1;
		ss=dp(p,v);
		chmax(Ans,ss+si[v]*(n-si[v]));
		vi[o>>1]=0;
		dfs(v,p);
	}
}

inline void _Sol_()
{
	read(n); tot=1;
	F(i,1,n-1){
		read(u);read(v);
		c[++tot][0]=v;c[tot][1]=a[u];a[u]=tot;
		c[++tot][0]=u;c[tot][1]=a[v];a[v]=tot;
	}
//	F(i,1,n)
	df(1,0,0);
	fs(1,0);
	dfs(1,0);
	prin(Ans);
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}