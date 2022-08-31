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
int n;
ll x[111111],y[111111],z[111111];

int out=0;
bool check(ll d,int par){
	ll lz,rz;
	lz=-7e18,rz=7e18;

	ll l10,r10,l20,r20;
	ll l1,r1,l2,r2;

	l1=l2=-7e18;
	r1=r2=7e18;
	rep(i,1,n+1){
		upmax(l1,x[i]+y[i]+z[i]-d);
		upmin(r1,x[i]+y[i]+z[i]+d);
		upmax(l2,x[i]+y[i]-z[i]-d);
		upmin(r2,x[i]+y[i]-z[i]+d);
	}
	if((l1&1)!=par)l1++;
	if((l2&1)!=par)l2++;
	if((r1&1)!=par)r1--;
	if((r2&1)!=par)r2--;
	
	if(l1>r1 || l2>r2)return 0;

	upmin(rz,(r1-l2)/2ll);
	upmax(lz,(l1-r2)/2ll);

	l10=l1;
	r10=r1;
	l20=l2;
	r20=r2;

	l1=l2=-7e18;
	r1=r2=7e18;
	rep(i,1,n+1){
		upmax(l1,x[i]-y[i]+z[i]-d);
		upmin(r1,x[i]-y[i]+z[i]+d);
		upmax(l2,x[i]-y[i]-z[i]-d);
		upmin(r2,x[i]-y[i]-z[i]+d);
	}
	if((l1&1)!=par)l1++;
	if((l2&1)!=par)l2++;
	if((r1&1)!=par)r1--;
	if((r2&1)!=par)r2--;
	
	if(l1>r1 || l2>r2)return 0;

	upmin(rz,(r1-l2)/2ll);
	upmax(lz,(l1-r2)/2ll);

	if(lz>rz)return 0;

	ll z=lz;

	ll lplu=max(l10-z,l20+z);
	ll rplu=min(r10-z,r20+z);
	ll lmin=max(l1-z,l2+z);
	ll rmin=min(r1-z,r2+z);

	ll x=(lplu+lmin)/2,y=(lplu-lmin)/2;

	if(out){
		out=0;
		printf("%I64d %I64d %I64d\n",x,y,z);
	}
	return 1;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	int te;gn(te);
	while(te--){
		gn(n);
		rep(i,1,n+1){
			gn(x[i]);
			gn(y[i]);
			gn(z[i]);
		}
		ll l=0,r=3.1e18;
		while(l<=r){
			ll mid=l+r>>1;
			if(check(mid,0) || check(mid,1))r=mid-1;
			else l=mid+1;
		}
		out=1;
		check(l,0);
		check(l,1);
	}
	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}