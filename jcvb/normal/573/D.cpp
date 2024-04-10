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
const ll inf=4e18;
const db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
int n,q;
pii w[33333],h[33333];
int ww[33333],hh[33333];
int odw[33333];
int cu[33333];

ll f[33333][4];
void yuchuli(int i){
	if(i>n)return;
	f[i][1]=f[i][2]=f[i][3]=-inf;
	if(cu[i]!=i)f[i][1]=1ll*ww[i]*hh[i];
	if(i>=2 && cu[i]!=i-1 && cu[i-1]!=i)f[i][2]=1ll*ww[i]*hh[i-1]+1ll*ww[i-1]*hh[i];
	if(i>=3){
		if(cu[i]!=i-1 && cu[i-1]!=i-2 && cu[i-2]!=i)upmax(f[i][3],1ll*ww[i]*hh[i-1]+1ll*ww[i-1]*hh[i-2]+1ll*ww[i-2]*hh[i]);
		if(cu[i]!=i-2 && cu[i-1]!=i && cu[i-2]!=i-1)upmax(f[i][3],1ll*hh[i]*ww[i-1]+1ll*hh[i-1]*ww[i-2]+1ll*hh[i-2]*ww[i]);
	}
}
ll dp[33333];
ll gao(){
	rep(i,1,n+1){
		dp[i]=-inf;
		upmax(dp[i],dp[i-1]+f[i][1]);
		if(i>=2)upmax(dp[i],dp[i-2]+f[i][2]);
		if(i>=3)upmax(dp[i],dp[i-3]+f[i][3]);
	}
	return dp[n];
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(q);
	rep(i,1,n+1)gn(w[i].fi),w[i].se=i;
	rep(i,1,n+1)gn(h[i].fi),h[i].se=i;
	sort(w+1,w+1+n);
	sort(h+1,h+1+n);
	rep(i,1,n+1)odw[w[i].se]=i;
	
	rep(i,1,n+1)cu[odw[h[i].se]]=i;

	rep(i,1,n+1)hh[i]=h[i].fi,ww[i]=w[i].fi;
	rep(i,1,n+1)yuchuli(i);
	while(q--){
		int x,y;
		gn(x);
		gn(y);
		x=odw[x];y=odw[y];

		swap(cu[x],cu[y]);
		yuchuli(x);
		yuchuli(x+1);
		yuchuli(x+2);
		yuchuli(y);
		yuchuli(y+1);
		yuchuli(y+2);
		printf(lld "\n",gao());
	}
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}