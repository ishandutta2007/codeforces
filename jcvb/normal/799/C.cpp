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
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

int n,c,d;
struct node{
	int beau,cost;
	char typ;
	void read(){
		gn(beau);
		gn(cost);
		gc(typ);
	}
}a[111111];
vector<node> cc,dd;

const int N=100005;
pii ma[N],secma[N];
int work(vector<node> &a,int hav){
	rep(i,0,N)ma[i]=secma[i]=mp(-inf,-1);
	rep(i,0,siz(a)){
		pii x = mp(a[i].beau,i);
		int id=a[i].cost;
		if(x>ma[id]){
			secma[id]=ma[id];
			ma[id]=x;
		}else if(x>secma[id]){
			secma[id]=x;
		}
	}
	
	rep(i,1,N){
		pii tmp[4];
		tmp[0]=secma[i];
		tmp[1]=ma[i];
		tmp[2]=secma[i-1];
		tmp[3]=ma[i-1];
		sort(tmp,tmp+4);
		secma[i]=tmp[2];
		ma[i]=tmp[3];
	}

	int ret=0;
	rep(i,0,siz(a)){
		if(a[i].cost>=hav)continue;
		int res=hav-a[i].cost;
		int to=a[i].beau;
		if(i==ma[res].se)to+=secma[res].fi;
		else to+=ma[res].fi;
		upmax(ret,to);
	}
	return ret;
}
int maa=0;

int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(c);gn(d);
	rep(i,1,n+1)a[i].read();
	rep(i,1,n+1)if(a[i].typ=='C')cc.pb(a[i]);else dd.pb(a[i]);
	upmax(maa,work(cc,c));
	upmax(maa,work(dd,d));

	int havc=-inf,havd=-inf;
	rep(i,1,n+1)if(a[i].typ=='C' && a[i].cost<=c)upmax(havc,a[i].beau);
	rep(i,1,n+1)if(a[i].typ=='D' && a[i].cost<=d)upmax(havd,a[i].beau);
	upmax(maa,havc+havd);
	printf("%d\n",maa);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}