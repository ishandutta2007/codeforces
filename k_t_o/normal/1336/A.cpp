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

#define int ll

#define N 500500
#define MO 

struct node {
	int d, sz, i;
	bool operator < (const node & a)const{
		if(sz-d!=a.sz-a.d)return sz-d<a.sz-a.d;
		return i>a.i;
	}
};
set<node>S;
int d[N],sz[N],n,u,v,tot,a[N],c[N][2],k,Ans;
void dfs(int p, int pr ,int de)
{
	d[p]=de;sz[p]=1;
	for(int o=a[p];o;o=c[o][1]){
		if(c[o][0]==pr)continue;
		dfs(c[o][0],p,de+1);
		sz[p]+=sz[c[o][0]];
	}
}

inline void _Sol_()
{
	read(n);read(k);
	F2(i,1,n){
		read(u);read(v);
		c[++tot][0]=v;c[tot][1]=a[u];a[u]=tot;
		c[++tot][0]=u;c[tot][1]=a[v];a[v]=tot;
	}
	dfs(1,0,0);
	F(i,1,n)S.insert((node){d[i],sz[i],i});
	
	F(i,1,k){
		Ans+=S.begin()->d;
		Ans-=S.begin()->sz-1;
		S.erase(S.begin());
	}
	priE(Ans);
}

signed main()
{

	int T=1; //read(T);
	while(T--)_Sol_();
}