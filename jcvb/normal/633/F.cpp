#include<cstdio>
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
#define foreach(it,a) for(typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
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
int inf=0x3f3f3f3f;
db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
// vertex 1 based
////////////////////////////////////
const int MAXV=110000+5;
////////////////////////////////////
struct edge{int v,next;}e[MAXV*2];int g[MAXV],etot;
void ae(int u,int v){
	e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
int qu[MAXV],pre[MAXV];int n;
void bfs(int rt){
	int p=0,q=0;
	pre[rt]=0;
	qu[q++]=rt;
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
			pre[e[i].v]=u;
			qu[q++]=e[i].v;
		}
	}
}
void init(){
	etot=0;
	memset(g,-1,sizeof(g));
		
}

int ai[111111];

ll f[111111][4]={0};


ll ma[4][3];
int opt[4][3];

void ad(int i,ll x,int o){
	if(x>ma[i][0]){
		opt[i][2]=opt[i][1];
		opt[i][1]=opt[i][0];
		ma[i][2]=ma[i][1];
		ma[i][1]=ma[i][0];
		opt[i][0]=o;
		ma[i][0]=x;
	}else if(x>ma[i][1]){
		opt[i][2]=opt[i][1];
		ma[i][2]=ma[i][1];
		opt[i][1]=o;
		ma[i][1]=x;
	}else if(x>ma[i][2]){
		opt[i][2]=o;
		ma[i][2]=x;
	}
}

inline bool eq(int a,int b){
	return a && b && a==b;
}
ll adj(int id1,int id2){
	ll an=0;
	rep(i,0,3)rep(j,0,3){
		if(eq(opt[id1][i], opt[id2][j]))continue;
		upmax(an,ma[id1][i]+ma[id2][j]);
	}
	return an;
}
ll adj(int id1,int id2,int id3){
	ll an=0;
	rep(i,0,3)rep(j,0,3)rep(k,0,3){
		if(eq(opt[id1][i],opt[id2][j]) || eq(opt[id2][j],opt[id3][k]) || eq(opt[id3][k],opt[id1][i]))continue;
		upmax(an,ma[id1][i]+ma[id2][j]+ma[id3][k]);
	}
	return an;
}
void dp(int u){
	cl(ma);cl(opt);
	for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
		int v=e[i].v;

		ad(0,f[v][0],v);
		ad(1,f[v][1],v);
		ad(2,f[v][2],v);
		ad(3,f[v][3],v);
	}
	f[u][0]=ma[0][0]+ai[u];
	f[u][2]=ma[0][0]+ma[0][1]+ai[u];
	upmax(f[u][2],ma[2][0]);

	f[u][1]=ai[u]+ma[1][0];
	upmax(f[u][1],ai[u]+adj(0,2));
	f[u][3]=ai[u]+adj(1,0);
	upmax(f[u][3],ma[3][0]);
	upmax(f[u][3],ai[u]+adj(0,0,2));
	upmax(f[u][3],adj(2,2));
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	init();
	gn(n);
	rep(i,1,n+1)gn(ai[i]);
	for (int i=1;i<n;i++){
		int x,y;gn(x);gn(y);
		ae(x,y);ae(y,x);
	}
	bfs(1);

	for (int i=n-1;i>=0;i--)dp(qu[i]);


	cout<<f[1][3]<<endl;
	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}