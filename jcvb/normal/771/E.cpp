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

int n;

ll a[3][333333];

int nex[3][333333];
int go[3][20][333333];

map<ll,int>cnt;
void init(ll *a,int *nex){
	cnt.clear();
	int las=0;
	rep(i,0,n+1){
		cnt[a[i]]++;
		while(cnt[a[i]]>=2){
			nex[las]=i;
			cnt[a[las]]--;
			las++;
		}
	}
	rep(j,las,n+2)nex[j]=n+1;
}

int f[333333];
map<int,int> g[2][333333];

void kai(map<int,int> *g,int i,int j){
	if(!g[i].count(j))g[i][j]=inf;
}
/* int g[2][2222][2222]; */
/* void kai(int g[2222][2222],int i,int j){ */

/* } */

int zhui(int id,int far,int low,int &bushu){//not farther than far
	bushu=0;
	for (int i=19;i>=0;i--){
		if(go[id][i][low]<=far){
			bushu+=1<<i;
			low=go[id][i][low];
		}
	}
	return low;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	rep(i,1,n+1)gn(a[0][i]);
	rep(i,1,n+1)gn(a[1][i]);
	rep(i,1,n+1){
		a[0][i]=a[0][i-1]+a[0][i];
		a[1][i]=a[1][i-1]+a[1][i];
	}
	rep(i,0,n+1)a[2][i]=a[0][i]+a[1][i];
	rep(j,0,3){
		init(a[j],nex[j]);
		rep(u,0,n+2)go[j][0][u]=nex[j][u];
		rep(i,1,20){
			rep(u,0,n+2)go[j][i][u]=go[j][i-1][go[j][i-1][u]];
		}
	}

	f[0]=0;
	rep(i,0,n+1){
		foreach(it,g[0][i]){
			upmax(f[max(i,it->se)],it->fi);
		}
		foreach(it,g[1][i]){
			upmax(f[max(i,it->se)],it->fi);
		}
		int res=f[i];
		upmax(f[nex[2][i]],res+1);
		kai(g[0],i,res+1);
		upmin(g[0][i][res+1],nex[0][i]);
		kai(g[1],i,res+1);
		upmin(g[1][i][res+1],nex[1][i]);

		kai(g[0],i+1,res+1);
		kai(g[1],i+1,res+1);
		upmin(g[0][i+1][res+1],g[0][i][res+1]);
		upmin(g[1][i+1][res+1],g[1][i][res+1]);

		kai(g[0],nex[1][i],res+2);
		upmin(g[0][nex[1][i]][res+2],g[0][i][res+1]);
		kai(g[1],nex[0][i],res+2);
		upmin(g[1][nex[0][i]][res+2],g[1][i][res+1]);
		kai(g[1],g[0][i][res+1],res+2);
		kai(g[0],g[1][i][res+1],res+2);
		upmin(g[1][g[0][i][res+1]][res+2],nex[1][i]);
		upmin(g[0][g[1][i][res+1]][res+2],nex[0][i]);

		upmax(f[i+1],f[i]);
		upmax(f[g[0][i][res+1]],res+1);
		upmax(f[g[1][i][res+1]],res+1);
	}
	int ans=0;
	rep(i,0,n+1)
		upmax(ans,f[i]);
	printf("%d\n",ans);

#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}