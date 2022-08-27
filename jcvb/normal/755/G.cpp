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
const int mo=998244353;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


// FFT_MAXN = 2^k
// first call fft_init() to precalc FFT_MAXN-th roots
// convo(a,n,b,m,c) a[0..n]*b[0..m] -> c[0..n+m]

const int FFT_MAXN=65536;
struct cp{
	db a,b;
	cp operator+(const cp&y)const{return (cp){a+y.a,b+y.b};}
	cp operator-(const cp&y)const{return (cp){a-y.a,b-y.b};}
	cp operator*(const cp&y)const{return (cp){a*y.a-b*y.b,a*y.b+b*y.a};}
	cp operator!()const{return (cp){a,-b};};
}nw[FFT_MAXN+1];int bitrev[FFT_MAXN];
void dft(cp*a,int n,int flag=1){
	int d=0;while((1<<d)*n!=FFT_MAXN)d++;
	rep(i,0,n)if(i<(bitrev[i]>>d))swap(a[i],a[bitrev[i]>>d]);
	for (int l=2;l<=n;l<<=1){
		int del=FFT_MAXN/l*flag;
		for (int i=0;i<n;i+=l){
			cp *le=a+i,*ri=a+i+(l>>1),*w=flag==1?nw:nw+FFT_MAXN;
			rep(k,0,l>>1){
				cp ne=*ri**w;
				*ri=*le-ne,*le=*le+ne;
				le++,ri++,w+=del;
			}
		}
	}
	if(flag!=1)rep(i,0,n)a[i].a/=n,a[i].b/=n;
}
void fft_init(){
	int L=0;while((1<<L)!=FFT_MAXN)L++;
	bitrev[0]=0;rep(i,1,FFT_MAXN)bitrev[i]=bitrev[i>>1]>>1|((i&1)<<(L-1));
	rep(i,0,FFT_MAXN+1)nw[i]=(cp){(db)cosl(2*pi/FFT_MAXN*i),(db)sinl(2*pi/FFT_MAXN*i)};
}
void convo(const int*a,int n,const int*b,int m,int*c){
	rep(i,0,n+m+1)c[i]=0;
	if(n<=100 && m<=100  || min(n,m)<=5){
		static int tmp[FFT_MAXN];
		rep(i,0,n+m+1)tmp[i]=0;
		rep(i,0,n+1)rep(j,0,m+1)upmo(tmp[i+j],1ll*a[i]*b[j]);
		rep(i,0,n+m+1)c[i]=tmp[i];
		return;
	}
	static cp f[FFT_MAXN],g[FFT_MAXN],t[FFT_MAXN];
	int N=2;while(N<=n+m)N<<=1;
	rep(i,0,N){
		int aa=i<=n?a[i]:0,bb=i<=m?b[i]:0;upmo(aa,0);upmo(bb,0);
		f[i]=(cp){db(aa>>15),db(aa&32767)};
		g[i]=(cp){db(bb>>15),db(bb&32767)};
	}
	dft(f,N);dft(g,N);
	rep(i,0,N){
		int j=i?N-i:0;
		t[i]=((f[i]+!f[j])*(!g[j]-g[i])+(!f[j]-f[i])*(g[i]+!g[j]))*(cp){0,0.25};
	}
	dft(t,N,-1);
	rep(i,0,n+m+1)upmo(c[i],(ll(t[i].a+0.5))%mo<<15);
	rep(i,0,N){
		int j=i?N-i:0;
		t[i]=(!f[j]-f[i])*(!g[j]-g[i])*(cp){-0.25,0}+(cp){0,0.25}*(f[i]+!f[j])*(g[i]+!g[j]);
	}
	dft(t,N,-1);
	rep(i,0,n+m+1)upmo(c[i],ll(t[i].a+0.5)+(ll(t[i].b+0.5)%mo<<30));
}

struct poly{
	int a[32768];
	int deg;
}one,x;
int c[65555];
poly operator*(const poly&a,const poly &b){
	convo(a.a,a.deg,b.a,b.deg,c);
	poly ret;
	ret.deg=a.deg+b.deg;
	upmin(ret.deg,32767);
	rep(i,0,ret.deg+1)ret.a[i]=c[i];
	return ret;
}
poly operator+(const poly&a,const poly &b){
	poly ret;
	ret.deg=max(a.deg,b.deg);
	rep(i,0,ret.deg+1)ret.a[i]=(a.a[i]+b.a[i])%mo;
	return ret;
}
poly operator-(const poly&a,const poly &b){
	poly ret;
	ret.deg=max(a.deg,b.deg);
	rep(i,0,ret.deg+1)ret.a[i]=(a.a[i]-b.a[i]+mo)%mo;
	return ret;
}
int n,k;

pair<poly,poly> suan(int n){//suan n,n-1
	if(n==1){
		return mp(one+x,one);
	}
	if(n==2){
		return mp(one+x+x+x+x*x,one+x);
	}
	int k=(n-1)/2;

	pair<poly,poly>tmp=suan(k);

	pair<poly,poly>ret;
	poly fk2=tmp.fi*tmp.fi,tt;
	if((n-1)%2==0){
		ret.se=fk2+tmp.se*tmp.se*x;
		ret.fi=fk2*(one+x)+(x+x)*(tmp.se*tmp.fi);
	}else{
		tt=fk2+tmp.se*tmp.se*x;
		ret.se=fk2*(one+x)+(x+x)*(tmp.se*tmp.fi);
		ret.fi=(one+x)*ret.se+x*tt;
	}
	return ret;
}
pair<poly,poly> tmp;
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	one.a[0]=1;
	x.a[1]=x.deg=1;
	fft_init();

	gn(n);gn(k);

	tmp=suan(n);
	rep(i,1,k+1)printf("%d\n",tmp.fi.a[i]);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}