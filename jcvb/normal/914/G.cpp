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
const int mo=1e9+7;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

const int N = 131072;
ll inv2;
int have[N];
int a[N];
int g[N];

int h[N];

int A[N],B[N],C[N],D[N],E[N];
int f[N];

void gao(int *a,int *b,int *c){
	rep(i,0,17){
		rep(j,0,N) if (j&pw(i)){
			upmo(a[j^pw(i)],a[j]);
			upmo(b[j^pw(i)],b[j]);
		}
	}
	rep(i,0,N){
		c[i]=1ll*a[i]*b[i]%mo;
	}
	rep(i,0,17){
		rep(j,0,N) if (j&pw(i)){
			upmo(c[j^pw(i)],-c[j]);
		}
	}
}
void dft(int l,int r) {
	if (l==r) return;
	int md=(l+r)>>1,len=(r-l+1)>>1;
	dft(l,md);dft(md+1,r);
	rep(i,0,len) {
		int x1=a[l+i],x2=a[l+len+i];
		a[l+i]=(x1-x2)%mo;
		a[l+len+i]=(x1+x2)%mo;
	}
}
void idft(int l,int r) {
	if (l==r) return;
	int md=(l+r)>>1,len=(r-l+1)>>1;
	rep(i,0,len) {
		int x1=a[l+i],x2=a[l+len+i];
		a[l+i]=(x1+x2)*inv2%mo;
		a[l+len+i]=(x2-x1)*inv2%mo;
	}
	idft(l,md);idft(md+1,r);
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	inv2 = qp(2,mo-2);

	int n;gn(n);
	while(n--){
		int x;gn(x);
		have[x]++;
	}
	rep(x,0,N){
		for (int i=x;i;i=(i-1)&x){
			upmo(g[x],1ll*have[x^i]*have[i]);
		}
		upmo(g[x],1ll*have[x]*have[0]);
	}
	rep(i,0,N){
		a[i] = have[i];
	}
	dft(0,N-1);
	rep(i,0,N)a[i]=1ll*a[i]*a[i]%mo;
	idft(0,N-1);

	f[0]=0;
	f[1]=1;
	rep(i,2,N){
		f[i]=(f[i-1]+f[i-2])%mo;
	}
	rep(i,0,N){
		A[i]=1ll*g[i]*f[i]%mo;
		B[i]=1ll*have[i]*f[i]%mo;
		C[i]=1ll*a[i]*f[i]%mo;
	}

	gao(A,B,D);
	gao(D,C,E);
	int su=0;
	rep(i,0,17)upmo(su,E[pw(i)]);
	printf("%d\n",su);

		







#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}