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
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
const int inf=0x3f3f3f3f;
const db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


// manually set n = number of vertices 
// vertex index from 1 to n
// first call tree_init();
// ae(u,v) only one direction

const int TREE_MAXV=200000+5;
struct edge{int v,next;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
int qu[TREE_MAXV],pre[TREE_MAXV],h[TREE_MAXV];
int n;
void ae(int u,int v){
	e[etot].v=v;
	e[etot].next=g[u];g[u]=etot++;
}
void bfs(int rt){
	int p=0,q=0;
	pre[rt]=0;
	h[rt]=0;
	qu[q++]=rt;
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
			pre[e[i].v]=u;
			h[e[i].v]=h[u]+1;
			qu[q++]=e[i].v;
		}
	}
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
int ai[222222],bi[222222];
int a0,b0;
int aii[222222];

int dif[222222];
int des[222222];

int lis[222222];int ltot=0;

int s1[422222],s2[422222];

int on[222222];

int disb,disa;
int lcapos;



ll gao(int ia,int ib,int ia0,int ib0,int ltot){
	ll t=0;
	ia--,ib--,ia0--,ib0--;

	while(ia0!=ib0){
		if((ia0+1)%ltot==ia)ia=ia0;
		ia0=(ia0+1)%ltot;
		t++;
	}
	while(ia!=ib){
		t+=ltot;
		ia=(ia+ltot-1)%ltot;
		if(ia==ia0)
			ia=(ia+ltot-1)%ltot;
	}
	return t;
}
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif

	tree_init();

	gn(n);
	rep(i,1,n+1){
		gn(ai[i]);
		if(ai[i]==0)a0=i;
		aii[i]=ai[i];
	}
	rep(i,1,n+1){
		gn(bi[i]);
		if(bi[i]==0)b0=i;
	}
	readedge();
	bfs(b0);

	int u=a0;
	int hi=0;
	while(u!=b0){
		hi++;
		swap(aii[u],aii[pre[u]]);
		u=pre[u];
	}

	int bo=0;
	rep(i,1,n+1)if(aii[i]!=bi[i])bo++,dif[i]=1;

	if(bo==0){
		printf("%d %d\n",0,hi);
		return 0;
	}

	rep(i,1,n+1)if(dif[i]){
		u=i;
		break;
	}
	rep(i,1,n+1)if(dif[i] && h[i]>h[u])u=i;

	int w=u;
	while(w){
		des[w]^=1;
		w=pre[w];
	}
	int v;
	rep(i,1,n+1)if(dif[i]!=des[i]){
		v=i;
		break;
	}
	rep(i,1,n+1)if(dif[i]!=des[i] && h[i]>h[v]){
		v=i;
	}
	
	w=v;
	while(w){
		des[w]^=1;
		w=pre[w];
	}
	rep(i,1,n+1)if(dif[i]!=des[i]){
		printf("-1\n");
		return 0;
	}


	bfs(u);
	w=v;
	int lca;
	while(w){
		if(dif[w])lis[++ltot]=w;
		else lca=w,lcapos=ltot;
		w=pre[w];
	}
	bfs(b0);
	disb=h[lca];
	w=u;
	while(w){
		des[w]^=1;
		w=pre[w];
	}
	w=v;
	while(w){
		des[w]^=1;
		w=pre[w];
	}

	rep(i,1,ltot+1){
		s1[i]=aii[lis[i]];
		s2[i]=bi[lis[i]];
	}

	int st=0;
	rep(i,1,ltot+1)if(s1[i]==s2[1]){
		st=i;
		break;
	}
	if(!st){
		printf("-1\n");
		return 0;
	}
	s1[0]=s1[ltot];
	rep(i,1,ltot+1)if(s1[(st-1+i)%ltot]!=s2[i]){
		printf("-1\n");
		return 0;
	}
	rep(i,1,ltot+1){
		on[lis[i]]=1;
	}
	on[lca]=1;

	bfs(a0);
	int au=lca;
	rep(i,1,n+1)if(on[i] && h[i]<h[au])au=i;

	disa=h[au];

	for (int i=ltot;i>lcapos;i--)lis[i+1]=lis[i];
	lis[lcapos+1]=lca;
	ltot++;

	rep(i,1,ltot+1)s1[i]=lis[i]==au?0:ai[lis[i]],s2[i]=lis[i]==lca?0:bi[lis[i]];
	ll ans=disa+disb;

	int c,ia,ib;
	int ia0,ib0;
	rep(i,1,ltot+1)if(s1[i]){
		c=s1[i];
		ia=i;
		break;
	}
	rep(i,1,ltot+1)if(s2[i]==c){
		ib=i;
		break;
	}
	rep(i,1,ltot+1){
		if(s1[i]==0)ia0=i;
		if(s2[i]==0)ib0=i;
	}

	ans+=min(gao(ia,ib,ia0,ib0,ltot),gao(ltot-ia+1,ltot-ib+1,ltot-ia0+1,ltot-ib0+1,ltot));
	cout<<min(u,v)<<" "<<max(u,v)<<" "<<ans<<endl;

#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}