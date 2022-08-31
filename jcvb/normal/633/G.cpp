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
#define foreach(it,a) for(typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
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
int mo;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


////////////////////////////////////
const int MAXV=300000+5;
////////////////////////////////////
struct edge{int v,next;}e[MAXV*2];int g[MAXV],etot;
void ae(int u,int v){
	e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
int n,m;
int dfn[111111],rig[111111];int ind=0;
int seq[111111];
void dfs(int u,int pre=-1){
	dfn[u]=++ind;
	seq[ind]=u;
	for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre){
		dfs(e[i].v,u);
	}
	rig[u]=ind;
}

int ai[111111];

int bo[3333];
bitset<1024> mask;


bitset<1024> seg[333333];
int tag[333333];

void build(int l,int r,int x){
	if(l==r){
		seg[x][ai[seq[l]]]=1;
	}else{
		int mid=l+r>>1;
		build(l,mid,x<<1);
		build(mid+1,r,x<<1|1);
		seg[x]=seg[x<<1]|seg[x<<1|1];
	}
}
void rot(int x,int v){
	tag[x]=(tag[x]+v)%mo;
	seg[x]=(seg[x]<<(v))|(seg[x]>>(mo-v));
}
bitset<1024> v;
int l1,r1;
int del;

void pd(int x){
	if(tag[x]){
		rot(x<<1,tag[x]);
		rot(x<<1|1,tag[x]);
		tag[x]=0;
	}
}
void upd(int l,int r,int x){
	if(l1<=l && r<=r1){
		rot(x,del);
	}else{
		int mid=l+r>>1;
		pd(x);
		if(l1<=mid)upd(l,mid,x<<1);
		if(r1>mid)upd(mid+1,r,x<<1|1);
		seg[x]=seg[x<<1]|seg[x<<1|1];
	}
}
void que(int l,int r,int x){
	if(l1<=l && r<=r1){
		v|=seg[x];
	}else{
		int mid=l+r>>1;
		pd(x);
		if(l1<=mid)que(l,mid,x<<1);
		if(r1>mid)que(mid+1,r,x<<1|1);
	}
}

int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	bo[0]=bo[1]=1;
	rep(i,2,2000)if(!bo[i]){
		for (int j=i+i;j<=2000;j+=i)bo[j]=1;
	}
	gn(n);gn(mo);
	rep(i,0,mo)if(!bo[i]){
		mask[i]=1;
	}

	rep(i,1,n+1){
		gn(ai[i]);
		ai[i]%=mo;
	}

	etot=0;
	memset(g,-1,sizeof(g));
	for (int i=1;i<n;i++){
		int x,y;gn(x);gn(y);
		ae(x,y);ae(y,x);
	}
	dfs(1);

	build(1,n,1);

	int q;gn(q);
	while(q--){
		int opt;gn(opt);
		int u;gn(u);
		l1=dfn[u],r1=rig[u];
		if(opt==1){
			gn(del);
			del%=mo;
			upd(1,n,1);
		}else{
			v=0;
			que(1,n,1);
			v&=mask;
			printf("%d\n",v.count());
		}
	}
	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}