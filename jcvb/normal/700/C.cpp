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


// edge bcc
// manually set n = number of vertices 
// vertex index from 1 to n
// first call bcc_init();
// ae(u,v) : bidirectional
// call bcc() after reading edges
// recursive
// bccid[]: 1 ~ bcctot 

const int BCC_MAXV=300000+5;
const int BCC_MAXE=300000+5;
struct edge{int v,next,w,id;}e[BCC_MAXE*2];int g[BCC_MAXV],etot;
int n;
void ae(int u,int v,int w=0,int id=0){
	e[etot].v=v;e[etot].id=id;e[etot].w=w;e[etot].next=g[u];g[u]=etot++;
	e[etot].v=u;e[etot].id=id;e[etot].w=w;e[etot].next=g[v];g[v]=etot++;
}
int dfn[BCC_MAXV],low[BCC_MAXV],stk[BCC_MAXV];bool inst[BCC_MAXV];int ind,top;
int bcctot,bccid[BCC_MAXV];
void dfs(int u,int pr){
	dfn[u]=low[u]=++ind;
	inst[stk[++top]=u]=1;
	for (int i=g[u];~i;i=e[i].next)if(i!=pr){
		if(!dfn[e[i].v]){
			dfs(e[i].v,i^1);
			low[u]=min(low[u],low[e[i].v]);
		}else if(inst[e[i].v])
			low[u]=min(low[u],dfn[e[i].v]);
	}
	if(low[u]==dfn[u]){
		++bcctot;
		while(1){
			bool bo=stk[top]==u;
			bccid[stk[top]]=bcctot;
			inst[stk[top--]]=0;
			if(bo)break;
		}
	}
}
void bcc(){
	rep(i,1,n+1)if(!dfn[i])dfs(i,-1);
}
void bcc_init(){
	static bool ini=0;
	if(!ini){
		ini=1;
		memset(g,-1,sizeof(g));
	}else{
		for (int i=0;i<=n;i++)g[i]=-1,dfn[i]=low[i]=bccid[i]=0;
	}
	etot=bcctot=ind=0;
}


int m;
struct ed{
	int i,u,v,w;
	void read(){
		gn(u);gn(v);gn(w);
	}
}arr[33333];

vector<ed>lu,ru;
//int olu[33333],oru[33333];
void gaolu(){
	bcc_init();
	rep(i,0,siz(lu)){
		ae(lu[i].u,lu[i].v);
	}
	bcc();
}
void gaoru(){
	bcc_init();
	rep(i,0,siz(ru)){
		ae(ru[i].u,ru[i].v);
	}
	bcc();
}

int s,t;

int fa[1111];
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}

pii bfs(int rt){
	static int qu[1111];
	static pii mi[1111];
	int vis[1111];
	rep(i,1,n+1)vis[i]=0;
	int p=0,q=0;
	qu[q++]=rt;
	vis[rt]=0;
	mi[rt]=mp(int(2.1e9),0);
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].next)if(!vis[e[i].v]){
			vis[e[i].v]=1;
			mi[e[i].v]=min(mi[u],(bccid[u]==bccid[e[i].v]?mp(int(2.1e9),0):mp(e[i].w,e[i].id)));
			qu[q++]=e[i].v;
		}
	}
	return mi[t];
}

int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);
	rep(i,1,n+1)fa[i]=i;
	gn(s);gn(t);
	rep(i,1,m+1){
		arr[i].i=i;
		arr[i].read();
		fa[gf(arr[i].u)]=gf(arr[i].v);
	}

	if(gf(s)!=gf(t)){
		printf("0\n0\n");
		return 0;
	}
	gaolu();
	rep(i,1,m+1){
		if(bccid[arr[i].u]!=bccid[arr[i].v]){
			lu.pb(arr[i]);
			gaolu();
			//olu[i]=1;
		}
	}
	gaoru();
	per(i,1,m+1){
		if(bccid[arr[i].u]!=bccid[arr[i].v]){
			ru.pb(arr[i]);
			gaoru();
			//oru[i]=1;
		}
	}

	ll mi=int(2.1e9);

	int k,uu,vv;
	rep(i,0,siz(ru)){
		bcc_init();
		rep(j,1,n+1)fa[j]=j;
		rep(j,0,siz(lu))if(lu[j].i<ru[i].i)ae(lu[j].u,lu[j].v,lu[j].w,lu[j].i),fa[gf(lu[j].u)]=gf(lu[j].v);
		rep(j,0,siz(ru))if(ru[j].i>ru[i].i)ae(ru[j].u,ru[j].v,ru[j].w,ru[j].i),fa[gf(ru[j].u)]=gf(ru[j].v);
		if(gf(s)!=gf(t)){
			if(upmin(mi,ru[i].w)){
				k=1;uu=ru[i].i;
			}
			continue;
		}
		bcc();

		pii an=bfs(s);
		if(upmin(mi,0ll+an.fi+ru[i].w)){
			k=2;uu=ru[i].i;vv=an.se;
		}
	}

	if(mi>2.05e9){
		printf("-1\n");
		return 0;
	}printf("%d\n%d\n",int(mi),k);
	if(k==1)printf("%d\n",uu);
	else printf("%d %d\n",uu,vv);







#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}