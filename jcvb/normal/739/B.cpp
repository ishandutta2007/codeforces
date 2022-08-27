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
#define buli(x) (__builtin_popcountll(x))
#define bur0(x) (__builtin_ctzll(x))
#define bul2(x) (63-__builtin_clzll(x))
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
#define forg(i,gu) for (int i=gu;~i;i=e[i].next)
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
#define mmo(a,b) (((a)=1ll*(a)*(b)%mo)<0?(a)+=mo:(a))
void getre(){int x=0;printf("%d\n",1/x);}
void gettle(){int res=1;while(1)res<<=1;printf("%d\n",res);}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
template<typename N>inline int sgn(N a){return a>0?1:(a<0?-1:0);}
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
inline void gs(char *s){scanf("%s",s);}
inline void gc(char &c){while((c=getchar())>126 || c<33);}
inline void pc(char c){putchar(c);}
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
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


// 2^LCA_UP > n
// manually set n = number of vertices 
// vertex index from 1 to n
// first call tree_init();
// ae(u,v) only one direction
// call bfs(rt) after reading edges

const int TREE_MAXV=500000+5;
const int LCA_UP=20;
struct edge{int v,next,w;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
int qu[TREE_MAXV],pr[LCA_UP][TREE_MAXV],pre[TREE_MAXV],h[TREE_MAXV];
ll hei[322222];
int n;
void ae(int u,int v,int w){
	e[etot].v=v;e[etot].w=w;
	e[etot].next=g[u];g[u]=etot++;
}
void bfs(int rt){
	int p=0,q=0;
	pr[0][rt]=pre[rt]=0;
	h[rt]=0;
	qu[q++]=rt;
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
			pr[0][e[i].v]=pre[e[i].v]=u;
			qu[q++]=e[i].v;
			h[e[i].v]=h[u]+1;
			hei[e[i].v]=hei[u]+e[i].w;
		}
	}
	for (int i=1;i<LCA_UP;i++)
		for (int u=1;u<=n;u++){
			pr[i][u]=pr[i-1][pr[i-1][u]];
		}
}
int lca(int u,int v){
	if(h[u]>h[v])swap(u,v);
	for (int i=0;h[v]-h[u];i++)if((1<<i)&(h[v]-h[u])){
		v=pr[i][v];
	}
	if(u==v)return u;
	for (int i=LCA_UP-1;i>=0;i--)if(pr[i][u]!=pr[i][v]){
		v=pr[i][v];
		u=pr[i][u];
	}
	return pr[0][u];
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
	for (int i=2;i<=n;i++){
		int x,y,w;gn(x);gn(w);y=i;
		ae(x,y,w);ae(y,x,w);
	}
}

int wei[522222];

int su[522222];
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	tree_init();
	rep(i,1,n+1)gn(wei[i]);
	readedge();
	bfs(1);

	rep(u,1,n+1){
		int v=u;
		int lef=wei[u];
		for (int i=19;i>=0;i--){
			if(!pr[i][v])continue;
			if(hei[v]-hei[pr[i][v]]>lef)continue;
			lef-=(hei[v]-hei[pr[i][v]]);
			v=pr[i][v];
		}
		su[pre[v]]--;
		su[pre[u]]++;
	}
	for (int i=n-1;i>=1;i--){
		int u=qu[i];
		su[pre[u]]+=su[u];
	}
	rep(i,1,n+1)printf("%d ",su[i]);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}