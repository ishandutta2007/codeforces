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
const int mo=1e9+7;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

int n,q;
ll bit[222222];
int bit2[222222];
ll bitque(int x) {
	ll su=0;
	for(;x;x-=x&-x)su+=bit[x];
	return su;
}
int bit2que(int x) {
	int su=0;
	for(;x;x-=x&-x)upmo(su,bit2[x]);
	return su;
}
void bitupd(int x,ll del){
	for (;x<=n;x+=x&-x)bit[x]+=del;
}
void bit2upd(int x,int del){
	for (;x<=n;x+=x&-x)upmo(bit2[x],del);
}
int a[222222],w[222222];
int main()
{
	gn(n);gn(q);
	rep(i,1,n+1) {
		gn(a[i]);
		a[i]+=n-i;
	}
	rep(i,1,n+1){
		gn(w[i]);
		bitupd(i,w[i]);
		bit2upd(i,1ll*a[i]*w[i]%mo);
		//
	}
	while(q--){
		int x,y;
		gn(x);gn(y);
		if(x<0) {
			x=-x;
			int del = y-w[x];
			w[x]=y;
			bitupd(x,del);
			bit2upd(x,1ll*a[x]*del%mo);
			//
		}else {
			ll fa = bitque(y);
			ll left = bitque(x-1);
			ll su = fa-left;
			ll th = (su+1)/2;
			ll want = th + left;  //smallest i >= want

			int l=x,r=y;
			while(l<=r) {
				int mid=l+r>>1;
				ll has = bitque(mid);
				if(has>=want)r=mid-1;
				else l=mid+1;
			}// goto l

			int rigsum = ((bit2que(y)-bit2que(l-1)) - 1ll*(bitque(y)-bitque(l-1))%mo*a[l])%mo;
			int lefsum = (-(bit2que(l-1)-bit2que(x-1)) + 1ll*(bitque(l-1)-bitque(x-1))%mo*a[l])%mo;
			int ret=((0ll+rigsum+lefsum)%mo+mo)%mo;
			printf("%d\n",ret);

		}

	}
	return 0;


}