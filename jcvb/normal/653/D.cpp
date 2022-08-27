#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<utility>
#include<functional>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<cassert>
using namespace std;
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#define pi ((db)3.14159265358979323846264338327950288L)
#define buli __builtin_popcountll
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fil(a,b) memset((a),(b),sizeof(a))
#define cl(a) fil(a,0)
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 
#endif
typedef long long ll;
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
const int inf=0x3f3f3f3f;
const db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


// first call dinic_init();
// ae(u,v,capacity)
// v index from 1, e index from 0
// s=1,t=2 by default, need not set vtot manually

typedef ll dinic_nu;
const dinic_nu dinic_inf=0x3f3f3f3f;
const int DINIC_MAXV=105+5;
const int DINIC_MAXE=1555+5;

int s,t,vtot;
struct edge{int v,next;dinic_nu f;}e[DINIC_MAXE*2];int g[DINIC_MAXV],etot;
void ae(int u,int v,dinic_nu f){
	upmax(vtot,u);upmax(vtot,v);
	e[etot].v=v;e[etot].f=f;e[etot].next=g[u];g[u]=etot++;
	e[etot].v=u;e[etot].f=0;e[etot].next=g[v];g[v]=etot++;
}
int d[DINIC_MAXV];
bool lb(){
	for (int i=0;i<=vtot;i++)d[i]=0;
	static int qu[DINIC_MAXV];
	int p=0,q=0;
	qu[q++]=s,d[s]=1;
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].next)if(e[i].f && !d[e[i].v]){
			d[e[i].v]=d[u]+1;
			if(e[i].v==t)return 1;
			qu[q++]=e[i].v;
		}
	}return 0;
}
dinic_nu aug(int u,dinic_nu mi){
	if(u==t)return mi;
	dinic_nu su=0,del;
	for (int i=g[u];~i;i=e[i].next)if(e[i].f && d[e[i].v]==d[u]+1){
		del=aug(e[i].v,min(mi,e[i].f));
		e[i].f-=del;e[i^1].f+=del;
		mi-=del;su+=del;
		if(!mi)break;
	}
	if(!su)d[u]=-1;
	return su;
}
dinic_nu dinic(){
	dinic_nu su=0;
	while(lb())su+=aug(s,dinic_inf);
	return su;
}
void dinic_init(){
	static bool ini=0;
	if(!ini){
		ini=1;
		memset(g,-1,sizeof(g));
	}else{
		for (int i=0;i<=vtot;i++)g[i]=-1;
	}
	etot=0;
	vtot=2,s=1,t=2;
}
//0 <= ei < (etot>>1)
inline dinic_nu capaof(int ei){return e[ei<<1].f+e[ei<<1^1].f;}
inline dinic_nu flowof(int ei){return e[ei<<1^1].f;}
inline dinic_nu resiof(int ei){return e[ei<<1].f;}
inline int uof(int ei){return e[ei<<1^1].v;}
inline int vof(int ei){return e[ei<<1].v;}

int n,m,x;
int ai[555],bi[555],ci[555];

bool check(db to){
	dinic_init();
	s=1,t=n;
	rep(i,1,m+1){
		ll id=ll(ci[i]/to);
		ae(ai[i],bi[i],id);
	}
	return dinic()>=x;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);gn(x);
	rep(i,1,m+1)gn(ai[i]),gn(bi[i]),gn(ci[i]);
	db l=0.0,r=1e9,mid;
	rep(_,0,200){
		mid=0.5*(l+r);
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%.10lf\n",r*x);
	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}