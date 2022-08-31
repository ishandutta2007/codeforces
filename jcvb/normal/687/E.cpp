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


// manually set n = number of vertices 
// vertex index from 1 to n
// first call scc_init();
// call scc() after reading edges
// recursive
// sccid[]: 1 ~ scctot, reversed top sort

const int SCC_MAXV=5000+5;
const int SCC_MAXE=5000+5;
struct edge{int v,next;}e[SCC_MAXE];int g[SCC_MAXV],etot;
int n;
void ae(int u,int v){
	e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
int dfn[SCC_MAXV],low[SCC_MAXV],stk[SCC_MAXV];bool inst[SCC_MAXV];int ind,top;
int scctot,sccid[SCC_MAXV];
int ssz[5555];
int out[5555];
void dfs(int u){
	dfn[u]=low[u]=++ind;
	inst[stk[++top]=u]=1;
	for (int i=g[u];~i;i=e[i].next)
		if(!dfn[e[i].v]){
			dfs(e[i].v);
			low[u]=min(low[u],low[e[i].v]);
		}else if(inst[e[i].v])
			low[u]=min(low[u],dfn[e[i].v]);
	if(low[u]==dfn[u]){
		++scctot;
		while(1){
			bool bo=stk[top]==u;
			sccid[stk[top]]=scctot;
			ssz[scctot]++;
			inst[stk[top--]]=0;
			if(bo)break;
		}
	}
}
void scc(){
	rep(i,1,n+1)if(!dfn[i])dfs(i);
}
void scc_init(){
	static bool ini=0;
	if(!ini){
		ini=1;
		memset(g,-1,sizeof(g));
	}else{
		for (int i=0;i<=n;i++)g[i]=-1,dfn[i]=low[i]=sccid[i]=0;
	}
	etot=scctot=ind=0;
}


int mincir[5555];
int mii[5555];
void workcir(int rt){
	static int qu[5555];
	static int dis[5555];
	int p=0,q=0;
	rep(i,1,n+1)dis[i]=0;
	qu[q++]=rt;
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].next)if(!dis[e[i].v]){
			dis[e[i].v]=dis[u]+1;
			qu[q++]=e[i].v;
			if(e[i].v==rt){
				mincir[rt]=dis[e[i].v];
				return;
			}
		}
	}
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	int m;
	gn(n);gn(m);
	scc_init();
	while(m--){
		int u,v;gn(u);gn(v);
		ae(u,v);
	}
	rep(i,1,n+1)workcir(i);

	scc();
	rep(u,1,n+1)
		for (int i=g[u];~i;i=e[i].next)if(sccid[e[i].v]!=sccid[u]){
			out[sccid[u]]=1;
		}
	rep(i,1,scctot+1)mii[i]=inf;
	rep(u,1,n+1)upmin(mii[sccid[u]],mincir[u]);
	int res=0;
	rep(i,1,scctot+1){
		if(out[i] || (!out[i] && ssz[i]==1)){
			res+=ssz[i];
		}else{
			res+=1+999*(mii[i])+(ssz[i]-mii[i]);
		}
	}


	printf("%d\n",res);


	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}