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
typedef long double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
const int inf=0x3f3f3f3f;
const db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

// manually set n = number of vertices 
// vertex index from 1 to n
// first call tree_init();
// ae(u,v) only one direction

const int TREE_MAXV=300000+5;
struct edge{int v,next,w;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
int qu[TREE_MAXV],pre[TREE_MAXV];
ll h[TREE_MAXV];
int n;
int off[222222];
void ae(int u,int v,int w){
	e[etot].v=v;
	e[etot].w=w;
	e[etot].next=g[u];g[u]=etot++;
}
int wei[222222];
db mi=1e100;int anv;
int nexgo;
void calc(int rt){
	static db dao[222222];
	int p=0,q=0;
	pre[rt]=0;
	qu[q++]=rt;
	h[rt]=0;
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
			pre[e[i].v]=u;
			qu[q++]=e[i].v;
			h[e[i].v]=h[u]+e[i].w;
		}
	}
	db ma=-100;
	rep(i,1,n+1)dao[i]=wei[i]*pow(h[i],0.5);
	per(i,1,q)dao[pre[qu[i]]]+=dao[qu[i]];
	for (int i=g[rt];~i;i=e[i].next)if(upmax(ma,dao[e[i].v]))nexgo=e[i].v;
	db an=0;
	rep(i,1,n+1)an+=wei[i]*pow(h[i],1.5);
	if(upmin(mi,an))anv=rt;
}
int cen(int rt){
	static int sz[222222];
	int p=0,q=0;
	pre[rt]=0;
	qu[q++]=rt;
	while(p!=q){
		int u=qu[p++];
		sz[u]=1;
		for (int i=g[u];~i;i=e[i].next)if(!off[e[i].v] && e[i].v!=pre[u]){
			pre[e[i].v]=u;
			qu[q++]=e[i].v;
		}
	}
	per(i,0,q){
		int u=qu[i];
		if(sz[u]*2>=q)return u;
		sz[pre[u]]+=sz[u];
	}
}
void tree_init(){
	static bool ini=0;
	if(!ini){
		ini=1;
		memset(g,-1,sizeof(g));
	}else{
		for (int i=0;i<=n;i++)g[i]=-1;
	}
	etot=0;
}
void readedge(){
	for (int i=1;i<n;i++){
		int x,y;gn(x);gn(y);
		int w;gn(w);
		ae(x,y,w);ae(y,x,w);
	}
}


void work(int rt){
	if(off[rt])return;
	int c=cen(rt);
	calc(c);
	off[c]=1;
	work(nexgo);
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	tree_init();
	gn(n);
	rep(i,1,n+1)gn(wei[i]);
	readedge();

	work(1);

	printf("%d %.10lf\n",anv,double(mi));
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}