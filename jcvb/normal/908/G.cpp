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


int memo[777][10];//f[a+b][d]
int memo2[777][10];//g[a+b][d]
int fac[4444];
int ifac[4444];
char s[777];
int po[11][777];
int invpo[11][777];
int n;
int main()
{
	rep(d,0,11){
		po[d][0]=1;
		rep(i,1,777)po[d][i]=1ll*po[d][i-1]*d%mo;
		rep(i,0,777)invpo[d][i] = qp(po[d][i],mo-2);
	}
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gs(s+1);
	n=strlen(s+1);
	fac[0]=1;
	rep(i,1,4444)fac[i]=1ll*fac[i-1]*i%mo;
	rep(i,0,4444)ifac[i]=qp(fac[i],mo-2);

	rep(d,0,10)
		rep(a,0,n+1)
			for (int b=0;b+a<=n;b++){
				upmo(memo[a+b][d] , 1ll*ifac[a]*ifac[b]%mo * invpo[d][a+b]%mo * po[9-d][b]%mo * po[10][b]%mo * (po[10][a])%mo *invpo[9][1]%mo*d%mo);
				upmo(memo2[a+b][d] , 1ll*ifac[a]*ifac[b]%mo * invpo[d][a+b]%mo * po[9-d][b]%mo * po[10][b]%mo * (-1)%mo *invpo[9][1]%mo*d%mo);
			}

	int tot=0;
	for (int t=1;t<=n;t++){
		int nex = s[t]-'0';
		if(t!=n)
			nex--;
		for(int da=0;da<=nex;da++){
			int num[10]={0};
			for (int j=1;j<=t-1;j++)num[s[j]-'0']++;
			num[da]++;
			for (int d=1;d<=9;d++){
				int L = n-t;
				int p = num[d];
				int q=0;
				for (int tt=d+1;tt<=9;tt++)q+=num[tt];

				for (int ab=0;ab<=L;ab++){
					int temp = (1ll * memo[ab][d]*po[10][p] + memo2[ab][d])%mo;
					mmo(temp, po[d][L]);
					mmo(temp, fac[L]);
					mmo(temp,ifac[L-ab]);
					mmo(temp,po[10][q]);
					upmo(tot,temp);
				}
			}
		}
	}
	printf("%d\n",tot);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}