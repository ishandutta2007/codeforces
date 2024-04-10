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

int n,s,m,k;
int a[2222];
pii intv[2222];
int cmp(const pii &a,const pii &b){
	return a.se-a.fi<b.se-b.fi;
}
int off[2222];



int b[2222];
int f[2222];
int tem[2222];

int ne[2222];

int qu[2222];
int suan(int mid) {
	rep(i,1,n+1)if(a[i]<=mid)b[i]=1;else b[i]=0;

	b[0]=0;
	rep(i,1,n+1)b[i]=b[i-1]+b[i];

	rep(i,1,n+1)f[i]=0;

	rep(nu,1,m+1) {

		rep(i,0,n+1)tem[i] = f[i]-b[i];
		int star = 1;

		int p=0,q=0;

		qu[q++]=0;
		rep(i,1,n+1) {
			ne[i]=ne[i-1];
			if(star<=s && intv[star].se==i) {
				int le = intv[star].fi;
				while(p!=q && qu[p]<le-1) p++;
				upmax(ne[i],b[i]+tem[qu[p]]);
				star++;
			}
			while(p!=q && tem[i]>tem[qu[q-1]])q--;
			qu[q++]=i;
		}

		rep(i,1,n+1)f[i]=ne[i];
	}
	return f[n];
}
int main()
{
	gn(n);gn(s);gn(m);gn(k);
	rep(i,1,n+1)gn(a[i]);
	rep(i,1,s+1)gn(intv[i].fi),gn(intv[i].se);
	sort(intv+1,intv+1+s,cmp);
	per(i,1,s+1) {
		if(!off[i]) {
			rep(j,1,i)if(!off[j] && intv[j].se<=intv[i].se && intv[j].fi>=intv[i].fi) {
				off[j]=1;
			}
		}
	}
	int nn=0;
	rep(i,1,s+1) {
		if(!off[i]) {
			intv[++nn]=intv[i];
		}
	}
	s=nn;

	sort(intv+1,intv+1+s);

	upmin(m,s);

	int lef=0,rig=inf;

	while(lef<=rig) {
		int mid=(lef+rig)>>1;
		int max0 = suan(mid);
		// <=mid: is 0

		if(max0>=k) {
			rig=mid-1;
		}else lef=mid+1;
	}
	if(lef==inf+1)lef=-1;
	printf("%d\n",lef);
	return 0;

}