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
const ll inf=0x3f3f3f3f3f3f3f3fll;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
int n,q,s;


const int N=1200000;
const int M=15000000;
int l1,r1;
int V,W;

struct edge{int v,next,w;}e[M];int g[N],etot=0;
int vtot;
void ae(int u,int v,int w){
	upmax(vtot,u);
	upmax(vtot,v);
	e[etot].v=v;e[etot].w=w;
	e[etot].next=g[u];g[u]=etot++;
}


void upd2(int l,int r,int x){
	if(l1<=l && r<=r1){
		int id;
		if(l==r)id=l;
		else id=x+110000;
		ae(V,id,W);
	}else{
		int mid=l+r>>1;
		if(l1<=mid)upd2(l,mid,x<<1);
		if(r1>mid)upd2(mid+1,r,x<<1|1);
	}
}
void upd3(int l,int r,int x){
	if(l1<=l && r<=r1){
		int id;
		if(l==r)id=l;
		else id=x+110000+400000;
		ae(id,V,W);
	}else{
		int mid=l+r>>1;
		if(l1<=mid)upd3(l,mid,x<<1);
		if(r1>mid)upd3(mid+1,r,x<<1|1);
	}
}
int build2(int l,int r,int x){
	int id;
	if(l==r)id=l;
	else id=x+110000;
	if(l!=r){
		int mid=l+r>>1;
		int lef=build2(l,mid,x<<1);
		int rig=build2(mid+1,r,x<<1|1);
		ae(id,lef,0);
		ae(id,rig,0);
	}
	return id;
}
int build3(int l,int r,int x){
	int id;
	if(l==r)id=l;
	else id=x+110000+400000;
	if(l!=r){
		int mid=l+r>>1;
		int lef=build3(l,mid,x<<1);
		int rig=build3(mid+1,r,x<<1|1);
		ae(lef,id,0);
		ae(rig,id,0);
	}
	return id;
}

ll d[N];

struct node{
	int u;
	ll d;
};
int operator<(const node&a,const node&b){
	return a.d>b.d;
}
priority_queue<node> qu;
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	fil(g,-1);
	gn(n);gn(q);gn(s);
	vtot=n;
	build2(1,n,1);
	build3(1,n,1);
	while(q--){
		int opt;gn(opt);
		if(opt==1){
			int u,v,w;
			gn(u);gn(v);gn(w);
			ae(u,v,w);
		}else if(opt==2){
			int u,l,r,w;
			gn(u);gn(l);gn(r);gn(w);
			l1=l;r1=r;
			V=u;W=w;
			upd2(1,n,1);
		}else{
			int u,l,r,w;
			gn(u);gn(l);gn(r);gn(w);
			l1=l;r1=r;
			V=u;W=w;
			upd3(1,n,1);
		}
	}

	fil(d,63);
	d[s]=0;
	qu.push((node){s,0});
	while(!qu.empty()){
		node tmp=qu.top();qu.pop();
		int u=tmp.u;

		if(d[u]!=tmp.d)continue;

		for (int i=g[u];~i;i=e[i].next)if(upmin(d[e[i].v],d[u]+e[i].w)){
			qu.push((node){e[i].v,d[e[i].v]});
		}
	}
	rep(i,1,n+1){
		ll x=d[i];
		if(x>=inf)x=-1;
		printf(lld" ",x);
	}

#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}