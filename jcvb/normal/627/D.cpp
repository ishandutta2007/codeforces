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
const int inf=0x3f3f3f3f;
const db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


// vertex 1 based
////////////////////////////////////
const int MAXV=210000+5;
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

int k;
int wi[222222];

int a[222222];

int sz[MAXV];
int su[MAXV];
int baddeg[MAXV];
int go1[MAXV];
int bo[MAXV];
int f[MAXV];
bool check(){
	int boo=1;
	rep(i,1,n+1)if(!a[i])boo=0;
	if(boo==1)return true;

	for (int i=1;i<=n;i++){
		sz[i]=1;
		su[i]=a[i];
	}
	for (int i=n-1;i>=1;i--){
		int u=qu[i];
		sz[pre[u]]+=sz[u];
		su[pre[u]]+=su[u];
	}
	for (int u=1;u<=n;u++)
		if(a[u]==1){
			go1[u]=baddeg[u]=0;
			if(u!=1){
				for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
					if(sz[e[i].v]==su[e[i].v]){
						go1[u]+=su[e[i].v];
					}else{
						baddeg[u]++;
					}
				}
				if(su[1]-su[u]==sz[1]-sz[u]){
					go1[u]+=su[1]-su[u];
				}else baddeg[u]++;

				go1[u]++;
			}else{
				for (int i=g[u];~i;i=e[i].next){
					if(sz[e[i].v]==su[e[i].v]){
						go1[u]+=su[e[i].v];
					}else{
						baddeg[u]++;
					}
				}
				go1[u]++;
			}
		}
	int ma=0;
	for (int u=1;u<=n;u++)if(a[u]==1)ma=max(ma,go1[u]);

	for (int u=1;u<=n;u++)bo[u]= (a[u]==1) && (baddeg[u]>=2);

	cl(f);
	for (int j=n-1;j>=0;j--){
		int u=qu[j-1];

		if(!bo[u])continue;

		int maa=0,sma=0;
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
			if(f[e[i].v]>maa){
				sma=maa;
				maa=f[e[i].v];
			}else if(f[e[i].v]>sma){
				sma=f[e[i].v];
			}
		}
		upmax(ma,maa+sma+go1[u]);
		f[u]=go1[u]+maa;
	}

	return ma>=k;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif

	gn(n);gn(k);
	rep(i,1,n+1)gn(wi[i]);
	init();
	for (int i=1;i<n;i++){
		int x,y;gn(x);gn(y);
		ae(x,y);ae(y,x);
	}
	bfs(1);

	int le=1,ri=1000000;
	while(le<=ri){
		int mid=le+ri>>1;
		rep(i,1,n+1)a[i]=wi[i]>=mid;
		if(check())le=mid+1;
		else ri=mid-1;
	}
	printf("%d\n",ri);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}