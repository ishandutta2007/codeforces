#include<cstdio>
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
#define pi ((db)3.14159265358979323846264338327950288L)
#define buli __builtin_popcountll
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
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
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
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 
#endif
typedef long long ll;
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
int inf=0x3f3f3f3f;
db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
struct quer{
	int ai,bi,id;
}qs[444444];
int cmpl(const quer&a,const quer&b){
	return a.ai<b.ai;
}
int cmpr(const quer&a,const quer&b){
	return a.ai>b.ai;
}
int cmpid(const quer&a,const quer&b){
	return a.id<b.id;
}
int n,m;
int hi[444444];
map<int,int>ma;
int tot=0;

struct data{
	int i,v;
};
int operator<(const data&a,const data&b){
	if(a.v!=b.v)return a.v<b.v;
	else return a.i>b.i;
}
data bit[888888];
void bitupd(int x,data v){
	for(;x<=tot;x+=x&-x)upmax(bit[x],v);
}
data bitque(int x){
	data an;
	an=(data){0,0};
	for(;x;x-=x&-x)upmax(an,bit[x]);
	return an;
}

int las[444444];
int idlef[444444],idrig[444444];

int mus[444444];
int out[444444];
int lefan[444444],rigan[444444];
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);
	rep(i,1,n+1){
		gn(hi[i]);
		ma[hi[i]];
	}
	rep(i,1,m+1){
		gn(qs[i].ai);
		gn(qs[i].bi);
		ma[qs[i].bi];
		qs[i].id=i;
	}
	foreach(i,ma)i->second=++tot;
	rep(i,1,n+1)hi[i]=ma[hi[i]];
	rep(i,1,m+1){
		qs[i].bi=ma[qs[i].bi];
	}

	sort(qs+1,qs+1+m,cmpl);

	int ma=0,id;
	for (int i=1,ci=1;i<=n;i++){
		while(ci<=m && qs[ci].ai==i){
			lefan[qs[ci].id]=bitque(qs[ci].bi-1).v;
			ci++;
		}
		int x=hi[i];
		data ret=bitque(x-1);
		las[i]=ret.i;
		bitupd(hi[i],(data){i,ret.v+1});
		if(upmax(ma,ret.v+1)){
			id=i;
		}
	}
	int u=id,cn=ma;
	while(u){
		idlef[u]=cn;
		cn--;
		u=las[u];
	}

	ma=0;
	cl(bit);

	sort(qs+1,qs+1+m,cmpr);
	for (int i=n,ci=1;i>=1;i--){
		while(ci<=m && qs[ci].ai==i){
			rigan[qs[ci].id]=bitque(tot-qs[ci].bi+1-1).v;
			ci++;
		}
		int x=tot-hi[i]+1;
		data ret=bitque(x-1);
		las[i]=n-ret.i+1;
		bitupd(tot-hi[i]+1,(data){n-i+1,ret.v+1});
		if(upmax(ma,ret.v+1)){
			id=i;
		}
	}
	u=id;cn=ma;
	while(u!=n+1){
		idrig[u]=ma-cn+1;
		cn--;
		u=las[u];
	}



	for (int i=1;i<=n;i++)if(idlef[i]==idrig[i] && idlef[i]){
		mus[i]=1;
	}


	sort(qs+1,qs+1+m,cmpid);
	for (int i=1;i<=m;i++){
		int mm=ma;
		if(mus[qs[i].ai])mm--;
		upmax(mm,1+lefan[i]+rigan[i]);
		printf("%d\n",mm);
	}



	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}