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
const int mo=1;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}



// variables index from 1 to vtot (without negative nodes)
// need not manually set vtot
// first call sat_init();
// make(i,v) ans[i]==v
// makeand(i,j,v) (ans[i]&ans[j])==v
// makeor(i,j,v) (ans[i]|ans[j])==v
// makexor(i,j,v) (ans[i]^ans[j])==v
// makenot(i,v,j,w) ((ans[i]==v) && (ans[j]==w))==false
// call sat(), return 1 has solution / 0 no solution 
// then call getsol(), ans[i]= 0 / 1
// recursive scc

const int SAT_MAXV=300000+5;
const int SAT_MAXE=400000+5;
struct edge{int v,next;}e[SAT_MAXE*4];int g[SAT_MAXV*2],etot;
int vtot;
void ae(int u,int v){
	e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
	upmax(vtot,(max(u,v)+1)>>1);
}
int dfn[SAT_MAXV*2],low[SAT_MAXV*2],stk[SAT_MAXV*2];bool inst[SAT_MAXV*2];int ind,top,scctot,sccid[SAT_MAXV*2],seq[SAT_MAXV*2],seqtot;
int tmpans[SAT_MAXV*2],ans[SAT_MAXV];
void dfs(int u){
	dfn[u]=low[u]=++ind;
	inst[stk[++top]=u]=1;
	for (int i=g[u];~i;i=e[i].next)
		if(!dfn[e[i].v]){
			dfs(e[i].v);
			low[u]=min(low[u],low[e[i].v]);
		}else if(inst[e[i].v])
			low[u]=min(low[u],dfn[e[i].v]);
	if(low[u]==dfn[u]){
		++scctot;
		while(1){
			bool bo=stk[top]==u;
			seq[++seqtot]=stk[top];
			sccid[stk[top]]=scctot;
			inst[stk[top--]]=0;
			if(bo)break;
		}
	}
}
void dfs2(int u){
	tmpans[u]=1;
	for (int i=g[u];~i;i=e[i].next)if(!~tmpans[e[i].v])dfs2(e[i].v);
}
bool sat(){
	rep(i,1,2*vtot+1)if(!dfn[i])dfs(i);
	rep(i,1,vtot+1)if(sccid[2*i-1]==sccid[2*i])return 0;
	return 1;
}
void getsol(){
	rep(i,1,2*vtot+1)tmpans[i]=-1;
	per(i,1,2*vtot+1){
		int u=seq[i];
		if(!~tmpans[u]){
			tmpans[u]=0;
			if(u&1)u++;
			else u--;
			dfs2(u);
		}
	}
	rep(i,1,vtot+1)ans[i]=tmpans[i*2-1];
}
void make(int i,bool v){
	if(v)ae(i*2,i*2-1);
	else ae(i*2-1,i*2);
}
void makenot(int i,bool v,int j,bool w){
	ae(i*2-v,j*2-(!w)),ae(j*2-w,i*2-(!v));
}
void makeand(int i,int j,bool v){
	if(v)make(i,1),make(j,1);
	else makenot(i,1,j,1);
}
void makeor(int i,int j,bool v){
	if(!v)make(i,0),make(j,0);
	else makenot(i,0,j,0);
}
void makexor(int i,int j,bool v){
	if(v)makenot(i,0,j,0),makenot(i,1,j,1);
	else makenot(i,1,j,0),makenot(i,0,j,1);
}
void sat_init(){
	static bool ini=0;
	if(!ini){
		ini=1;
		memset(g,-1,sizeof(g));
	}else{
		for (int i=0;i<=2*vtot;i++)g[i]=-1,dfn[i]=low[i]=sccid[i]=0;
	}
	vtot=etot=scctot=ind=seqtot=0;
}


int n,a,b;
int p[111111];
map<int,int>ma;
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	sat_init();
	gn(n);gn(a);gn(b);

	rep(i,1,n+1){
		gn(p[i]);
		ma[p[i]]=i;
	}
	rep(i,1,n+1){
		int t=p[i];
		if(!ma.count(a-t)){
			make(i,1);
		}else{
			makenot(i,0,ma[a-t],1);
		}
		if(!ma.count(b-t)){
			make(i,0);
		}else{
			makenot(i,1,ma[b-t],0);
		}
	}
	if(!sat()){
		printf("NO\n");
	}else{
		printf("YES\n");
		getsol();
		rep(i,1,n+1)printf("%d ",ans[i]);
	}





	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}