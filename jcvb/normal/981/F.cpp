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
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	c=='-'?(sg=-1,x=0):(x=c-'0');
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


int n,l;
ll a[222222],b[222222];

ll as[444444];
ll bs[444444];
int pref[444444];

int qu[422222];
bool check(ll d) {
	if(d*2>=l)return 1;
	int astot=0;
	int bstot=0;
	rep(i,1,n+1){
		if(a[i]-d>=0 && a[i]+d<=2*l)as[++astot]=a[i];
	}
	rep(i,1,n+1){
		if(a[i]+l-d>=0 && a[i]+l+d<=2*l)as[++astot]=a[i]+l;
	}
	rep(i,1,n+1) {
		bs[++bstot]=b[i];
	}
	rep(i,1,n+1) {
		bs[++bstot]=b[i]+l;
	}
	pref[0]=0;
	int x=1;
	rep(i,1,astot+1) {
		pref[i] = pref[i-1]-1;
		while(x<=bstot && bs[x]<=as[i]+d) {
			x++;
			pref[i]++;
		}
	}
	int far=0;
	x=1;
	int cur=0;

	int p=0,q=0;
	rep(i,1,astot+1) {
		while(far<astot && (as[far+1]+d)-(as[i]-d)<l){
			far++;
			while(p!=q && pref[far]<pref[qu[q-1]])q--;
			qu[q++]=far;
		}
		while(x<=bstot && bs[x]<as[i]-d) {
			x++;
			cur--;
		}
		ll tote = 1-i-cur;
		ll ha = pref[qu[p]];
		if(ha<tote) return 0;

		while(p!=q && qu[p]==i) {
			p++;
		}
	}
	return 1;



}
int main()
{
	gn(n);gn(l);
	rep(i,1,n+1)gn(a[i]);
	rep(i,1,n+1)gn(b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	int lef=0,rig=l;
	while(lef<=rig){
		int mid=lef+rig>>1;
		if(!check(mid))lef=mid+1;
		else rig=mid-1;
	}
	printf("%d\n",lef);
	return 0;
}