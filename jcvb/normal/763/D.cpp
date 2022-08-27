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
const ll mo=ll(1e18)+3;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
ll mul(ll x,ll y){
	x%=mo,y%=mo;
	return (x*y-(ll)(x/(long double)mo*y)*mo+mo)%mo;
}
namespace myrand{
	// rand : [0,2^31)
	// randint : [-2^31,2^31)
	// randll : [-2^63,2^63)
	// randbit : 0,1
	unsigned int x[5]={107896582, 1107972621, 1195573091, 1224749359, 241825441};
	unsigned int get16(){
		unsigned long long tmp=(107374182ll*x[0]+104480ll*x[4]);
		unsigned int res=(tmp>>31)+(tmp&0x7fffffffu);
		x[0]=x[1],x[1]=x[2],x[2]=x[3],x[3]=x[4];
		return x[4]=res>=2147483647?res-2147483647:res;
	}
	void mysrand(unsigned int seed){
		for (int i=0;i<5;i++) seed=(seed+1)%2147483647,x[i]=seed;
		for (int i=0;i<5;i++) get16();
	}
	int randint(){
		int res=0;
		res+=int(get16());
		res+=int(get16())<<16;
		return res;
	}
	long long randll(){
		long long res=0;
		res+=(long long)(get16());
		res+=(long long)(get16())<<16;
		res+=(long long)(get16())<<32;
		res+=(long long)(get16())<<48;
		return res;
	}
	int randbit(){
		return ((get16())>>7)&1;
	}
	int myrand(){
		int x=randint();
		if(x<0)return ~x;
		return x;
	}
	template<typename RandomAccessIterator>void my_randomshuffle(RandomAccessIterator first,RandomAccessIterator last){
		int n=last-first;
		for (int i=1;i<n;i++){
			int to=myrand()%(i+1);
			swap(first[to],first[i]);
		}
	}
#define rand myrand::myrand
#define srand myrand::mysrand
#define random_shuffle myrand::my_randomshuffle
};

ll wei[111111];





// manually set n = number of vertices 
// vertex index from 1 to n
// first call tree_init();
// ae(u,v) only one direction

const int TREE_MAXV=300000+5;
struct edge{int v,next;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
int qu[TREE_MAXV],pre[TREE_MAXV];
int h[333333];
ll has[333333];
int n;
void ae(int u,int v){
	e[etot].v=v;
	e[etot].next=g[u];g[u]=etot++;
}
void tree_init(){
	static bool ini=0;
	if(!ini){
		ini=1;
		memset(g,-1,sizeof(g));
	}else{
		for (int i=0;i<=n;i++)g[i]=-1;
	}
	etot=0;
}
void readedge(){
	for (int i=1;i<n;i++){
		int x,y;gn(x);gn(y);
		ae(x,y);ae(y,x);
	}
}


void dfs(int u,int pr){
	for(int i=g[u];~i;i=e[i].next)if(e[i].v!=pr){
		dfs(e[i].v,u);
		upmax(h[u],h[e[i].v]+1);
	}
	ll ret=1;
	for(int i=g[u];~i;i=e[i].next)if(e[i].v!=pr){
		ret=mul(ret,wei[h[u]]+has[e[i].v]);
	}
	has[u]=ret;
}
ll has2[333333];
ll hasful[333333];
int h2[333333];
ll lef1[333333],rig1[333333];
ll lef2[333333],rig2[333333];
void dfs2(int u,int pr){
	int mh=0,sh=0;
	for(int i=g[u];~i;i=e[i].next)if(e[i].v!=pr){
		int tmp=h[e[i].v]+1;
		if(tmp>=mh){
			sh=mh;
			mh=tmp;
		}else if(tmp>=sh){
			sh=tmp;
		}
	}
	if(pr!=0){
		int tmp=h2[u]+1;
		if(tmp>=mh){
			sh=mh;
			mh=tmp;
		}else if(tmp>=sh){
			sh=tmp;
		}
	}
	int deg=0;
	for(int i=g[u];~i;i=e[i].next)if(e[i].v!=pr){
		++deg;
		rig1[deg]=lef1[deg]=(has[e[i].v]+wei[mh])%mo;
		rig2[deg]=lef2[deg]=(has[e[i].v]+wei[sh])%mo;
	}
	if(pr==0)lef1[0]=lef2[0]=1;
	else lef1[0]=(has2[u]+wei[mh])%mo,lef2[0]=(has2[u]+wei[sh])%mo;
	rig1[deg+1]=rig2[deg+1]=1;

	rep(i,1,deg+1)lef1[i]=mul(lef1[i-1],lef1[i]),lef2[i]=mul(lef2[i-1],lef2[i]);
	per(i,1,deg+1)rig1[i]=mul(rig1[i+1],rig1[i]),rig2[i]=mul(rig2[i+1],rig2[i]);

	if(u==1)hasful[u]=has[u];
	else hasful[u]=lef1[deg];

	int curd=0;
	for(int i=g[u];~i;i=e[i].next)if(e[i].v!=pr){
		++curd;
		if(h[e[i].v]+1!=mh){
			has2[e[i].v]=mul(lef1[curd-1],rig1[curd+1]);
			h2[e[i].v]=mh;
		} else {
			has2[e[i].v]=mul(lef2[curd-1],rig2[curd+1]);
			h2[e[i].v]=sh;
		}
	}
	for(int i=g[u];~i;i=e[i].next)if(e[i].v!=pr){
		dfs2(e[i].v,u);
	}
}


map<ll,int> ma;
int cnt=0;

int an=0;int out;
void add(ll x){
	if((++ma[x])==1)cnt++;
}
void del(ll x){
	if((--ma[x])==0)cnt--;
}

void dfs3(int u,int pr){
	debug("when %d has %d\n",u,cnt);
	if(upmax(an,cnt))out=u;
	for (int i=g[u];~i;i=e[i].next)if(pr!=e[i].v){
		del(hasful[u]);
		del(has[e[i].v]);
		add(has2[e[i].v]);
		add(hasful[e[i].v]);
		dfs3(e[i].v,u);
		add(hasful[u]);
		add(has[e[i].v]);
		del(has2[e[i].v]);
		del(hasful[e[i].v]);
	}
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	srand(2343);
	rep(i,0,101111){
		wei[i]=myrand::randll()%mo;
	}
	gn(n);
	tree_init();
	readedge();

	dfs(1,0);

	dfs2(1,0);

	rep(u,1,n+1)add(has[u]);

	dfs3(1,0);


	printf("%d\n",out);


#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}