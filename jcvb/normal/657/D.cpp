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
typedef long double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
const int inf=0x3f3f3f3f;
const db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
int n;
struct node{
	int p,t;
}a[222222];
int cmp(const node&a,const node&b){
	return 1ll*a.t*b.p<1ll*b.t*a.p;
}
ll tsu[222222];
int lef[222222],rig[222222];
ll tmi[222222],tma[222222];

db T;
struct pkt{
	int x;
	db y;
}p[444444];
int cmpp(const pkt&a,const pkt&b){
	if(a.x==b.x)return a.y>b.y;
	return a.x<b.x;
}
int ptot=0;
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	rep(i,1,n+1){
		gn(a[i].p);
	}
	rep(i,1,n+1){
		gn(a[i].t);
	}
	sort(a+1,a+1+n,cmp);
	tsu[0]=0;
	rep(i,1,n+1)tsu[i]=tsu[i-1]+a[i].t;
	T=tsu[n];
	lef[1]=1;
	rep(i,2,n+1){
		if(!cmp(a[i],a[i-1]) && !cmp(a[i-1],a[i]))lef[i]=lef[i-1];
		else lef[i]=i;
	}
	rig[n]=n;
	per(i,1,n){
		if(!cmp(a[i],a[i+1]) && !cmp(a[i+1],a[i]))rig[i]=rig[i+1];
		else rig[i]=i;
	}

	rep(i,1,n+1){
		tmi[i]=tsu[lef[i]-1]+a[i].t;
		tma[i]=tsu[rig[i]];
	}

	rep(i,1,n+1){
		p[++ptot]=(pkt){a[i].p,db(a[i].p)*tmi[i]};
		p[++ptot]=(pkt){a[i].p,db(a[i].p)*tma[i]};
	}
	sort(p+1,p+1+ptot,cmpp);
	db ma=T;
	rep(i,1,ptot)if(p[i].x!=p[i+1].x){
		upmax(ma,(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x));
	}
	printf("%.10lf\n",double(T/ma));
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}