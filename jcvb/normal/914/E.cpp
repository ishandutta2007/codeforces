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
//const ll inf=0x3f3f3f3f3f3f3f3fll;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


ll ans[333333];
int lab[333333];
// manually set n = number of vertices 
// vertex index from 1 to n
// first call tree_init();
// ae(u,v) only one direction
// call work(1);

int ok[100];
int oktot;
inline bool valid(int x){
	return (x&(-x)) == x;
}
const int TREE_MAXV=300000+5;
struct edge{int v,next;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
int qu[TREE_MAXV],pre[TREE_MAXV],off[TREE_MAXV];
int n;
void ae(int u,int v){
	e[etot].v=v;
	e[etot].next=g[u];g[u]=etot++;
}
int getcen(int rt){
	static int sz[TREE_MAXV];
	static bool bo[TREE_MAXV];
	int p=0,q=0;
	pre[rt]=0;
	qu[q++]=rt;
	while(p!=q){
		int u=qu[p++];
		sz[u]=bo[u]=1;
		for (int i=g[u];~i;i=e[i].next)if(!off[e[i].v] && e[i].v!=pre[u]){
			pre[e[i].v]=u;
			qu[q++]=e[i].v;
		}
	}
	for (int i=q-1;i>=0;i--){
		int u=qu[i];
		if(bo[u] && sz[u]*2>=q)return u;
		sz[pre[u]]+=sz[u];
		if(sz[u]*2>q)bo[pre[u]]=0;
	}
}

ll cnt[1<<20];
int h[333333];
ll jia[333333];

ll headnum;
void bfssuan(int rt,int preroot){
	int p=0,q=0;
	pre[rt]=preroot;
	h[rt]=pw(lab[rt])^pw(lab[preroot]);
	qu[q++]=rt;
	while(p!=q){
		int u=qu[p++];
		jia[u]=0;
		for (int i=g[u];~i;i=e[i].next)if(!off[e[i].v] && e[i].v!=pre[u]){
			pre[e[i].v]=u;
			h[e[i].v] = h[u]^pw(lab[e[i].v]);
			qu[q++]=e[i].v;
		}
		cnt[h[u]^pw(lab[preroot])]-=1;
	}
	rep(i,0,q){
		int u = qu[i];
		rep(j,0,oktot){
			int fin = h[u]^ok[j];
			jia[u]+=cnt[fin];
			headnum+=cnt[fin];
			if(fin==0){
				jia[u]+=1;
				headnum+=2;
			}
		}
	}
	rep(i,0,q){
		int u=qu[i];
		cnt[h[u]^pw(lab[preroot])]+=1;
	}
	per(j,0,q){
		int u=qu[j];
		if(u!=rt){
			jia[pre[u]]+=jia[u];
		}
		ans[u]+=jia[u];
	}
}
void bfsplus(int rt,int preroot,int del){
	int p=0,q=0;
	pre[rt]=preroot;
	h[rt]=pw(lab[rt]);
	qu[q++]=rt;
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].next)if(!off[e[i].v] && e[i].v!=pre[u]){
			pre[e[i].v]=u;
			h[e[i].v] = h[u]^pw(lab[e[i].v]);
			qu[q++]=e[i].v;
		}
	}
	rep(j,0,q){
		cnt[h[qu[j]]]+=del;
	}
}
void work(int rt){
	int cen=getcen(rt);
	off[cen]=1;

	for (int i=g[cen];~i;i=e[i].next)if(!off[e[i].v]){
		bfsplus(e[i].v,cen,1);
	}
	headnum=0;
	for (int i=g[cen];~i;i=e[i].next)if(!off[e[i].v]){
		bfssuan(e[i].v,cen);
	}
	for (int i=g[cen];~i;i=e[i].next)if(!off[e[i].v]){
		bfsplus(e[i].v,cen,-1);
	}
	ans[cen]+=headnum/2;
	for (int i=g[cen];~i;i=e[i].next)if(!off[e[i].v]){
		work(e[i].v);
	}
}
void tree_init(){
	static bool ini=0;
	if(!ini){
		ini=1;
		memset(g,-1,sizeof(g));
	}else{
		for (int i=0;i<=n;i++)off[i]=0,g[i]=-1;
	}
	etot=0;
}
void readedge(){
	for (int i=1;i<n;i++){
		int x,y;gn(x);gn(y);
		ae(x,y);ae(y,x);
	}
}


 char s[333333];
int main()
{
	ok[oktot++]=0;
	rep(i,0,20)ok[oktot++]=pw(i);
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	tree_init();
	gn(n);
	readedge();
	gs(s+1);
	rep(i,1,n+1){
		lab[i]=s[i]-'a';
	}
	work(1);
	rep(i,1,n+1)printf(lld" ",ans[i]+1);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}