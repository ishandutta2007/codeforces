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


// tot = sieve(n)
// prime[1..tot] = {1<= prime <=n}
// bo[i]==1, i is composite ; bo[i]==0, i==1 or prime

//basic

const int SIEVE_MAXN=2000000+5;
int prime[SIEVE_MAXN>100000?SIEVE_MAXN/10:10000];bool bo[SIEVE_MAXN];
int nex[21111111];
int sieve(int n){
	int tot=0;
	for (int i=2;i<=n;i++){
		if (!bo[i]){
			prime[++tot]=i;
				nex[i]=i;
		}
		for (int j=1;j<=tot && prime[j]*i<=n;j++){
			bo[i*prime[j]]=1;
			nex[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
	return tot;
}
int n;
int a[2222222];
int has[2222222];

int res[2222222];
int tot=0;
int upd(int p) {
	res[++tot]=p;
	int ret=0;
	while(p>1) {
		int q = nex[p];
		int r = 0;
		while(p%q==0) {
			p/=q;
			r++;
		}
		if(upmax(has[q],r))ret=1;
	}
	return ret;
}

int tim[2222222];
void upd2(int p) {
	while(p>1) {
		int q = nex[p];
		int r = 0;
		while(p%q==0) {
			p/=q;
			r++;
		}
		if(has[q]==r) {
			tim[q]++;
		}
	}
}
int upd3(int p) {
	while(p>1) {
		int q = nex[p];
		int r = 0;
		while(p%q==0) {
			p/=q;
			r++;
		}
		if(has[q]==r) {
			if(tim[q]==1)return 0;
		}
	}
	return 1;

}
int main()
{
	sieve(2000000);
	gn(n);
	rep(i,1,n+1){
		int x;gn(x);
		a[x]++;
	}
	int noneed=0;
	for (int p=2000000;p>=1;p--) {
		if(a[p]) {
			if(a[p]>=2) {
				if(!upd(p))noneed=1;
				if(!upd(p-1))noneed=1;
				if(a[p]>=3)noneed=1;
			} else  {
				if(!has[p]) {
					if(!upd(p))noneed=1;
				}else {
					if(!upd(p-1))noneed=1;
				}
			}
		}
	}
	int ret=1;
	if(!noneed) {
		rep(i,1,tot+1) upd2(res[i]);
		rep(i,1,tot+1) if(upd3(res[i])) {
			noneed=1;
			break;
		}
	}

	rep(i,1,2000000+1)
		while(has[i]>0) {
			mmo(ret,i);
			has[i]--;
		}
	if(noneed)upmo(ret,1);
	printf("%d\n",ret);
	return 0;


}