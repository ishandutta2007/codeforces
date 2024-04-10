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
//const int mo=0;
int qp(int a,ll b,int mo){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


//mu & phi

const int SIEVE_MAXN=10000000+5;
int prime[SIEVE_MAXN>100000?SIEVE_MAXN/10:10000];bool bo[SIEVE_MAXN];
int mu[SIEVE_MAXN];
int phi[SIEVE_MAXN];
int sieve(int n){
	int tot=0;
	mu[1]=1;
	phi[1]=1;
	for (int i=2;i<=n;i++){
		if (!bo[i]){
			prime[++tot]=i;
			mu[i]=-1;
			phi[i]=i-1;
		}
		for (int j=1;j<=tot && prime[j]*i<=n;j++){
			bo[i*prime[j]]=1;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}else{
				mu[i*prime[j]]=-mu[i];
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}
		}
	}
	return tot;
}

int n,m;
bool ban[222222];
vi has[222222];

int f[222222];//ending at f
int pre[222222];

int pro[222222];int tot=0;
void build(int id){
	if(id==0)return;
	rep(j,0,siz(has[id]))pro[++tot]=has[id][j];
	build(pre[id]);
}
int ans[222222];

int qiuni(int a,int b){
	int g=gcd(a,m);
	if(gcd(b,m)!=g){
		rep(j,0,m)if(1ll*j*a%m==b)return j;
	}
	int m0=m/g;
	int a0=a/g,b0=b/g;
	return 1ll*b0*qp(a0,phi[m0]-1,m0)%m0;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	sieve(222222);
	gn(n);gn(m);
	rep(i,1,n+1){
		int x;gn(x);
		ban[x]=1;
		/*int g=gcd(x,m);
		ban[g].pb(x);*/
	}
	rep(i,0,m)if(!ban[i]){
		has[gcd(i,m)].pb(i);
	}

	rep(i,1,m+1)if(has[i].size()){
		upmax(f[i],has[i].size());
		for (int j=i+i;j<=m;j+=i)if(has[j].size()){
			if(upmax(f[j],has[j].size()+f[i]))pre[j]=i;
		}
	}
	int ma=0;
	int x=0;
	rep(i,1,m+1)if(upmax(ma,f[i]))x=i;

	build(x);

	reverse(pro+1,pro+1+tot);

	ans[1]=pro[1];
	rep(i,2,tot+1){
		ans[i]=qiuni(pro[i-1],pro[i]);
		//if(gcd(pro[i],m)==gcd(pro[i-1],m)) ans[i]=


	}
	printf("%d\n",tot);
	rep(i,1,tot+1)printf("%d ",ans[i]);

#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}