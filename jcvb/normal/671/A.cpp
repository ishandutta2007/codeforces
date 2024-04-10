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

struct pkt{
	int x,y;
	void read(){
		gn(x);gn(y);
	}
}a[111111],sa,sb,ed;

db d[111111],ad[111111],bd[111111];
pkt operator-(const pkt&a,const pkt&b){
	return (pkt){a.x-b.x,a.y-b.y};
}
ll dissq(const pkt&a){
	return sqr(a.x)+sqr(a.y);
}
db dis(const pkt&a){
	return sqrt(dissq(a));
}
int n;

db su=0.0;
db le[111111][2],ri[111111][2];
db mi=1e18;
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	sa.read();sb.read();ed.read();
	gn(n);
	rep(i,1,n+1){
		a[i].read();
		su+=dis(a[i]-ed);
		d[i]=dis(a[i]-ed);
		ad[i]=dis(a[i]-sa);
		bd[i]=dis(a[i]-sb);
	}
	le[0][0]=0.0;le[0][1]=1e18;
	rep(i,1,n+1){
		le[i][0]=le[i-1][0]+d[i];
		le[i][1]=min(le[i-1][1]+d[i],le[i-1][0]+ad[i]);
	}
	ri[n+1][0]=0.0;ri[n+1][1]=1e18;
	per(i,1,n+1){
		ri[i][0]=ri[i+1][0]+d[i];
		ri[i][1]=min(ri[i+1][1]+d[i],ri[i+1][0]+bd[i]);
	}
	upmin(mi,su+ri[1][1]);
	upmin(mi,su+le[n][1]);
	rep(i,1,n)upmin(mi,su+le[i][1]+ri[i+1][1]);

	reverse(d+1,d+1+n);
	reverse(ad+1,ad+1+n);
	reverse(bd+1,bd+1+n);

	le[0][0]=0.0;le[0][1]=1e18;
	rep(i,1,n+1){
		le[i][0]=le[i-1][0]+d[i];
		le[i][1]=min(le[i-1][1]+d[i],le[i-1][0]+ad[i]);
	}
	ri[n+1][0]=0.0;ri[n+1][1]=1e18;
	per(i,1,n+1){
		ri[i][0]=ri[i+1][0]+d[i];
		ri[i][1]=min(ri[i+1][1]+d[i],ri[i+1][0]+bd[i]);
	}

	rep(i,1,n)upmin(mi,su+le[i][1]+ri[i+1][1]);
	printf("%.10lf\n",mi);
	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}