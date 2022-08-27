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
const ll inf=1e18;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}



// manually set n = number of vertices 
// vertex index from 1 to n
// first call tree_init();
// ae(u,v) only one direction

const int TREE_MAXV=300000+5;
struct edge{int v,next;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
int qu[TREE_MAXV],pre[TREE_MAXV];
int h[TREE_MAXV];
int n;
void ae(int u,int v){
	e[etot].v=v;
	e[etot].next=g[u];g[u]=etot++;
}
void bfs(int rt){
	int p=0,q=0;
	pre[rt]=0;
	qu[q++]=rt;
	h[rt]=0;
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
			pre[e[i].v]=u;
			qu[q++]=e[i].v;
			h[e[i].v]=h[u]+1;
		}
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
		ae(x,y);ae(y,x);
	}
}

int m;
struct pat{
	int son,pre,co;
	void read(){
		gn(son);gn(pre);gn(co);
	}
}pa[333333];
vi lis[333333];

map<int,ll> f[333333];
ll del[333333];
multiset<ll> mi[333333];

void inse(int id,int h,ll nu){
	if(!f[id].count(h)){
		f[id][h]=nu;
		mi[id].insert(nu);
	}else if(nu<f[id][h]){
		multiset<ll>::iterator it=mi[id].find(f[id][h]);
		mi[id].erase(it);
		f[id][h]=nu;
		mi[id].insert(nu);
	}
}
void dp(int u){
	int masz=-1,mav;
	for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
		int v=e[i].v;
		if(upmax(masz,siz(f[v]))){
			mav=v;
		}
	}

	ll totmi=0;
	if(masz!=-1){
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
			int v=e[i].v;
			if(mi[v].empty()){
				printf("-1\n");
				exit(0);
			}
			totmi+=*mi[v].begin()+del[v];
		}
		del[mav]+=(totmi-(*mi[mav].begin()+del[mav]));
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u] && e[i].v!=mav){
			int v=e[i].v;
			foreach(it,f[v]){
				inse(mav,it->fi,it->se+del[v]+(totmi-*mi[v].begin()-del[v])-del[mav]);
			}
		}
		f[u].swap(f[mav]);
		mi[u].swap(mi[mav]);
		swap(del[u],del[mav]);
	}else{
		inse(u,h[u],0);
	}
	rep(j,0,siz(lis[u])){
		int p=pa[lis[u][j]].pre;
		int c=pa[lis[u][j]].co;
		if(p==u)continue;
		int hi=h[p];
		inse(u,hi,c+totmi-del[u]);
	}
	if(u==1)return;
	if(f[u].count(h[u])){
		multiset<ll>::iterator it=mi[u].find(f[u][h[u]]);
		mi[u].erase(it);
		f[u].erase(h[u]);
	}
	//debug("%d %lld\n",u,*mi[u].begin()+del[u]);
}

int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);
	tree_init();
	readedge();
	rep(_,1,m+1){
		pa[_].read();
		lis[pa[_].son].pb(_);
	}
	bfs(1);
	for (int i=n-1;i>=0;i--)dp(qu[i]);
	cout<<del[1]+f[1][0]<<endl;
	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}