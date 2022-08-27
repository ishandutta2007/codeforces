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
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

char s[33];
int vis[1111];

char ans[3][111];

void tu1(int r,int c,int i){
	if(i==0)return;
	if(r==1 && c==0){
		r=2,c=1;
	}
	ans[r][c]=s[i];
	if(r==1){
		if(c==1)tu1(2,1,i-1);
		else tu1(1,c-1,i-1);
	}else tu1(2,c+1,i-1);
}
void tu2(int r,int c,int i){
	if(i==28)return;
	if(r==2 && c==0){
		r=1,c=1;
	}
	ans[r][c]=s[i];
	if(r==2){
		if(c==1)tu2(1,1,i+1);
		else tu2(2,c-1,i+1);
	}else tu2(1,c+1,i+1);
}

	
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gs(s+1);
	rep(i,1,27+1)vis[s[i]]++;

	char rep;
	for (char c='A';c<='Z';c++)if(vis[c]==2){
		rep=c;
		break;
	}
	int p1,p2;
	per(i,1,27+1)if(s[i]==rep)p1=i;
	rep(i,1,27+1)if(s[i]==rep)p2=i;

	if(abs(p1-p2)==1){
		printf("Impossible\n");
		return 0;
	}

	int dis=p2-p1;
	int ro=(dis+1)/2;

	if(dis%2==0){
		for (int i=1;i<=ro;i++){
			ans[1][13-ro+i]=s[p1+i-1];
			ans[2][13-i+1]=s[p1+ro+i-1];
		}
		tu1(1,13-ro,p1-1);
		tu2(2,13-ro,p2+1);
	}else{
		for (int i=1;i<=ro;i++){
			ans[1][13-ro+i]=s[p1+i-1];
			if(i<ro)ans[2][13-i+1]=s[p1+ro+i-1];
		}
		tu1(1,13-ro,p1-1);
		tu2(2,13-ro+1,p2+1);
	}
	rep(i,1,13+1)putchar(ans[1][i]);
	putchar('\n');
	rep(i,1,13+1)putchar(ans[2][i]);
	putchar('\n');



#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}