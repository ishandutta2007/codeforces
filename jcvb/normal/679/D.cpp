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

vi g[444];
int d[444][444];
int deg[444];
int n;


int lev[444][444];
int sz[444];


db pro[444];
int app[444];int ind=0;
int lis[444];int listot;


db ma[444];
int vv[444];
int in=0;
int lis2[444],lis2tot;
db gao(int dep){
	db ans=1.0/sz[dep];
	++ind;
	listot=0;

	for (int i=1;i<=sz[dep];i++){
		int u=lev[dep][i];
		for (int j=0;j<siz(g[u]);j++){
			int v=g[u][j];
			if(app[v]!=ind){
				app[v]=ind;
				pro[v]=0.0;
				lis[++listot]=v;
			}
			pro[v]+=1.0/sz[dep]/siz(g[u]);
		}
	}

	for (int v=1;v<=n;v++){
		++in;
		lis2tot=0;
		for (int j=1;j<=listot;j++){
			int w=lis[j];
			int de=d[v][w];
			if(vv[de]!=in){
				vv[de]=in;
				ma[de]=0.0;
				lis2[++lis2tot]=de;
			}
			upmax(ma[de],pro[w]);
		}
		db mi=0.0;
		for (int k=1;k<=lis2tot;k++){
			int de=lis2[k];
			mi+=ma[de];
		}
		upmax(ans,mi);
	}
	return ans;
}
db work(int u){
	rep(i,0,n+1)sz[i]=0;
	rep(i,1,n+1)lev[d[u][i]][++sz[d[u][i]]]=i;
	db res=0;
	rep(i,0,n+1)if(sz[i]>0){
		res+=1.0*sz[i]/n*gao(i);
	}
	return res;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);int m;gn(m);
	fil(d,63);
	rep(i,1,n+1)d[i][i]=0;
	while(m--){
		int x,y;
		gn(x);gn(y);
		g[x].pb(y);g[y].pb(x);
		d[x][y]=d[y][x]=1;
	}
	rep(k,1,n+1)rep(i,1,n+1)rep(j,1,n+1)
		upmin(d[i][j],d[i][k]+d[k][j]);


	db maxans=0;

	rep(i,1,n+1)upmax(maxans,work(i));
	printf("%.10lf\n",maxans);

	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}