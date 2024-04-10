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
int inf=1.05e9;
db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
int n,m;
struct ee{
	int a,b,d;
}E[155];
int cmpe(const ee&a,const ee&b){
	return a.d<b.d;
}
struct edge{
	int v,next;
}e[333];int g[555];int etot=0;
void ae(int u,int v){
	e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
struct mat{bool a[150][150];}uno;
bitset<150> le[150],ri[150];
mat operator*(const mat&a,const mat&b){
	rep(i,0,n)rep(j,0,n){
		le[i][j]=a.a[i][j];
		ri[j][i]=b.a[i][j];
	}
	mat c;
	rep(i,0,n)rep(j,0,n){
		c.a[i][j]=(le[i]&ri[j]).any();
	}
	return c;
}
mat qp(mat a,int b){mat n=uno;do{if(b&1)n=n*a;a=a*a;}while(b>>=1);return n;}
mat a,b;
bitset<150> cur,ne;

int dis[150];
int gao(){
	static int qu[222];
	int p=0,q=0;
	rep(i,0,n)dis[i]=(cur[i])?0:inf;
	rep(i,0,n)if(dis[i]==0){
		qu[q++]=i;
	}
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].next)if(dis[e[i].v]==inf){
			dis[e[i].v]=dis[u]+1;
			qu[q++]=e[i].v;
		}
	}
	return dis[n-1];
}

int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	fil(g,-1);
	gn(n);gn(m);
	rep(i,0,n)uno.a[i][i]=1;
	rep(i,1,m+1){
		gn(E[i].a);
		gn(E[i].b);
		gn(E[i].d);
		E[i].a--;
		E[i].b--;
	}
	int mi=inf;
	sort(E+1,E+1+m,cmpe);

	if(E[1].d>0){
		printf("Impossible\n");
		return 0;
	}cur[0]=1;
	for (int i=1,j=1;i<=m;i=j){
		for (;j<=m && E[j].d==E[i].d;j++)
			a.a[E[j].a][E[j].b]=1,ae(E[j].a,E[j].b);
		upmin(mi,E[i].d+gao());
		if(j<=m){
			b=qp(a,E[j].d-E[i].d);
			ne=0;
			rep(i,0,n)if(cur[i]){
				for (int j=0;j<n;j++)if(b.a[i][j])ne[j]=1;
			}
			cur=ne;
		}
	}
	if(mi==inf)printf("Impossible\n");
	else printf("%d\n",mi);
	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}