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

struct edge{
	int v,next;
}e[6666];int g[3333];int etot=0;
void ae(int u,int v){
	e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
	e[etot].v=u;e[etot].next=g[v];g[v]=etot++;
}
int n,m;
int s1,t1,l1,s2,t2,l2;

int dis[3333][3333];

int d[3333];
void bfs(int rt){
	fil(d,63);
	d[rt]=0;
	static int qu[3333];
	int p=0,q=0;
	qu[q++]=rt;
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].next)if(d[u]+1<d[e[i].v]){
			d[e[i].v]=d[u]+1;
			qu[q++]=e[i].v;
		}
	}
	rep(i,1,n+1)dis[rt][i]=d[i];
}
int an=-1;
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	fil(g,-1);
	gn(n);gn(m);
	rep(_,0,m){
		int u,v;
		gn(u);gn(v);
		ae(u,v);
	}
	cin>>s1>>t1>>l1>>s2>>t2>>l2;
	rep(i,1,n+1)bfs(i);

	rep(i,1,n+1)rep(j,1,n+1){
		if(0ll+dis[i][j]+dis[s1][i]+dis[j][t1]<=l1 && 0ll+dis[i][j]+dis[s2][i]+dis[j][t2]<=l2){
			upmax(an,m-dis[i][j]-dis[s1][i]-dis[j][t1]-dis[s2][i]-dis[j][t2]);
		}
		if(0ll+dis[i][j]+dis[s1][i]+dis[j][t1]<=l1 && 0ll+dis[i][j]+dis[s2][j]+dis[i][t2]<=l2){
			upmax(an,m-dis[i][j]-dis[s1][i]-dis[j][t1]-dis[s2][j]-dis[i][t2]);
		}
	}
	if(dis[s1][t1]<=l1 && dis[s2][t2]<=l2)upmax(an,m-dis[s1][t1]-dis[s2][t2]);
	printf("%d\n",an);






	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}