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

int n;
int per[1111];
int got[1111];

char bd[1111][1111];
int tot=0;
int vis[1111];

int lis[1111];
int main()
{
	cl(bd);
	gn(n);
	rep(i,1,n+1)gn(per[i]);
	int bo=0;
	rep(i,1,n+1)if(per[i]!=i) {
		bo=1;
		break;
	}
	rep(i,1,n+1)got[per[i]]=i;
	if(bo==0) {
		printf("%d\n",n);
		rep(i,1,n+1) {
			rep(j,1,n+1)printf(".");
			printf("\n");
		}
		return 0;
	}
	int left=0;
	rep(i,1,n+1)if(per[i]!=i) {
		left=i;
		break;
	}

	rep(i,1,n+1)if(per[i]!=i) {
		if(vis[i])continue;

		int but = tot+1;
		int len=0;
		lis[++len]=i;
		vis[i]=1;
		int x=got[i];
		while(x!=i) {
			vis[x]=1;
			lis[++len]=x;
			x=got[x];
		}

		if(lis[1]!=left) {
			for (int j=1;j<len;j++) {
				tot++;
				if(lis[j+1]>lis[j]) {
					bd[tot][lis[j]] = bd[tot][lis[j+1]]='\\';
				} else {
					bd[tot][lis[j]]=bd[tot][lis[j+1]]='/';
				}
			}
			tot++;
			bd[tot][lis[len]]=bd[tot][left]='/';
			bd[but][left]=bd[but][lis[1]] = '\\';
		}else {
			for (int j=2;j<=len;j++) {
				tot++;
				int j1 = j+1;
				if(j==len)j1=1;

				if(lis[j1]>lis[j]) {
					bd[tot][lis[j]] = bd[tot][lis[j1]]='\\';
				} else {
					bd[tot][lis[j]]=bd[tot][lis[j1]]='/';
				}
			}
		}
	}
	printf("%d\n",n-1);
	for (int i=n;i>=1;i--) {
		rep(j,1,n+1){
			if(bd[i][j]==0)bd[i][j]='.';
			putchar(bd[i][j]);
		}
		printf("\n");
	}


	return 0;
}