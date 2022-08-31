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
const int mo=1e9+7;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

ll n;
int k;

// mo < 2^30 = 1073741824
// first call mm_init(sz);
// indices from 0 to mm_n - 1
// call a.plus(),b.plus() before a*b

const int MM_N =33;

int mm_n;
struct mat{
	int a[MM_N][MM_N];
	void plus(){
		rep(i,0,mm_n)rep(j,0,mm_n)a[i][j]=(a[i][j]%mo+mo)%mo;
	}
}one;
mat operator*(const mat&a,const mat&b){
	static ll ans[MM_N][MM_N];
	cl(ans);
	ll infa=8e18;
	rep(k,0,mm_n)rep(i,0,mm_n)rep(j,0,mm_n){
		if((ans[i][j]+=1ll*a.a[i][k]*b.a[k][j])>=infa)ans[i][j]%=mo;
	}
	mat c;
	rep(i,0,mm_n)rep(j,0,mm_n)c.a[i][j]=ans[i][j]%mo;
	return c;
}
mat qp(mat a,ll b){a.plus();mat n=one;do{if(b&1)n=n*a;a=a*a;}while(b>>=1);return n;}
void mm_init(int sz){
	mm_n=sz;
	rep(i,0,mm_n)one.a[i][i]=1;
}


int nu[111];int tot=0;

mat a[100];

mat jia(const mat&x,int d){
	mat ret;
	rep(i,0,k+1)rep(j,0,k+1)ret.a[i!=k?(i+d)%k:k][j!=k?(j+d)%k:k]=x.a[i][j];
	return ret;
}	
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(k);
	mm_init(k+1);

	while(n){
		nu[tot++]=n%k;
		n/=k;
	}
	for (int j=0;j<=k;j++)a[0].a[0][j]=1;
	for (int j=0;j<=k;j++)a[0].a[j][j]=1;
	for (int i=1;i<tot;i++){
		mat now=one;
		rep(j,0,k)now=now*jia(a[i-1],j);
		a[i]=now;
	}
	int ad=0;
	mat ans=one;
	for (int i=tot-1;i>=0;i--){
		for (int j=0;j<nu[i];j++)
			ans=ans*jia(a[i],(j+ad)%k);
		ad=(ad+nu[i])%k;
	}

	int ret=0;
	rep(i,0,k+1)upmo(ret,ans.a[i][k]);
	printf("%d\n",ret);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}