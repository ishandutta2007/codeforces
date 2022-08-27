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
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

namespace rho{
	ll mul(ll x,ll y,ll z){
		x%=z,y%=z;
		if(z<=2e9)return (x*y%z+z)%z;
		return (x*y-(ll)(x/(long double)z*y)*z+z)%z;
	}
	ll qp(ll a,ll b,ll mo){ll ans=1;do{if(b&1)ans=mul(ans,a,mo);a=mul(a,a,mo);}while(b>>=1);return ans;}
	ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
	int pr[9]={2,3,5,7,11,13,17,19,23};
	ll tmp[100];int tot;
	int mr(ll n){
		if(n<=1)return 0;
		for (int i=0,a;i<9;i++){
			if((a=pr[i])==n)return 1;
			ll t=n-1;int k=0;
			while(~t&1)t>>=1,k++;
			ll c=qp(a,t,n);
			if(c==1)continue;
			int bo=0;
			for (int i=0;i<k;i++){
				if(c==n-1){bo=1;break;}
				c=mul(c,c,n);
			}
			if(!bo)return 0;
		}
		return 1;
	}
	void rho(ll n){
		if(mr(n))tmp[++tot]=n;
		else{
			for (int c=12345;;c++){
				ll x=0,y=0;
				while(1){
					x=(mul(x,x,n)+c)%n;
					y=(mul(y,y,n)+c)%n;
					y=(mul(y,y,n)+c)%n;
					ll d=gcd(n,abs(x-y));
					if(d!=1){
						if(d!=n){
							rho(d);
							rho(n/d);
							return;
						}else break;
					}
				}
			}
		}
	}
	void facto(ll n){
		tot=0;
		for (int i=0;i<9;i++)while(n%pr[i]==0){
			tmp[++tot]=pr[i];
			n/=pr[i];
		}
		if(n>1)rho(n);
		sort(tmp+1,tmp+1+tot);
	}
};


ll phi(ll n){
	using namespace rho;
	facto(n);
	ll res=1;
	for (int i=1;i<=tot;i++){
		if(i==1 || tmp[i]!=tmp[i-1])res=res*(tmp[i]-1);
		else res*=tmp[i];
	}
	return res;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	ll n,k;
	gn(n);gn(k);
	k=(k+1)/2;

	while(k>=1 && n>1){
		n=phi(n);
		k--;
	}

	cout<<n%mo<<endl;


#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}