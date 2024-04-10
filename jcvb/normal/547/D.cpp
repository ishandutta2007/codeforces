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
int n;
pii p[444444];
map<int,int>mx,my;
int xtot=0,ytot=0;
int ui[444444],vi[444444];



int del[444444]={0};
namespace tree{
	// manually set n = number of vertices 
	// vertex index from 1 to n
	// first call tree_init();
	// ae(u,v) only one direction

	const int TREE_MAXV=400000+5;
	struct edge{int v,next,id;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
	int qu[TREE_MAXV],pre[TREE_MAXV],vis[TREE_MAXV],upe[TREE_MAXV];
	int n;
	int deg[TREE_MAXV];
	void ae(int u,int v,int id){
		deg[u]++;deg[v]++;
		e[etot].v=v;e[etot].id=id;
		e[etot].next=g[u];g[u]=etot++;
		e[etot].v=u;e[etot].id=id;
		e[etot].next=g[v];g[v]=etot++;
	}
	void bfs(int rt){
		int p=0,q=0;
		pre[rt]=0;
		vis[rt]=1;
		qu[q++]=rt;
		while(p!=q){
			int u=qu[p++];
			for (int i=g[u];~i;i=e[i].next)if(!vis[e[i].v]){
				pre[e[i].v]=u;
				vis[e[i].v]=1;
				upe[e[i].v]=e[i].id;
				qu[q++]=e[i].v;
			}
		}
		per(i,1,q){
			int u=qu[i];
			if(deg[u]&1){
				deg[u]--;
				deg[pre[u]]--;
				del[upe[u]]=1;
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
		cl(vis);
		cl(deg);
		etot=0;
	}
};
int ans[555555];
namespace tr{

	// manually set n = number of vertices 
	// vertex index from 1 to n
	// first call tree_init();
	// ae(u,v) only one direction

	const int TREE_MAXV=400000+5;
	struct edge{int v,id,next;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
	int qu[TREE_MAXV],pre[TREE_MAXV],vis[444444];
	int cur[444444];
	int n;
	void ae(int u,int v,int id){
		e[etot].v=v;e[etot].id=id;
		e[etot].next=g[u];g[u]=etot++;
	}
	void bfs(int rt){
		int p=0,q=0;
		pre[rt]=0;
		qu[q++]=rt;
		vis[rt]=1;
		while(p!=q){
			int u=qu[p++];
			for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
				ans[e[i].id]=cur[u];
				cur[u]^=1;
				pre[e[i].v]=u;
				cur[e[i].v]=cur[u];
				vis[e[i].v]=1;
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
		cl(vis);
	}
}

namespace eu{
	struct edge{int v,id,vis,next;}e[888888];int g[444444],etot;
	int vis[444444];
	int ans[1000005];int anslen=0;
	int stk[888888],ine[888888];
	void ae(int u,int v,int id){
		e[etot].v=v;e[etot].id=id;
		e[etot].next=g[u];g[u]=etot++;
		e[etot].v=u;e[etot].id=id;
		e[etot].next=g[v];g[v]=etot++;
	}
	void dfs(int rt){
	    int top=0;
	    stk[++top]=rt;ine[top]=-1;
	    vis[rt]=1;
	    while(top){
		int u=stk[top];
		vis[u]=1;
		while(~g[u] && (e[g[u]].vis||e[g[u]^1].vis))g[u]=e[g[u]].next;
		if(~g[u]){
		    e[g[u]].vis=e[g[u]^1].vis=1;
		    int v=e[g[u]].v;
		    ine[top+1]=e[g[u]].id;
		    g[u]=e[g[u]].next;
		    stk[++top]=v;
		}else{
		    if(~ine[top]){
			ans[++anslen]=ine[top];
		    }
		    top--;
		}
	    }
	}
	void ini(){
		fil(g,-1);
		etot=0;
	}
};
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	rep(i,1,n+1){
		gn(p[i].fi);gn(p[i].se);
		mx[p[i].fi];
		my[p[i].se];
	}
	foreach(it,mx){
		it->se=++xtot;
	}
	foreach(it,my){
		it->se=++ytot;
	}

	tree::tree_init();
	tree::n=xtot+ytot;
	rep(i,1,n+1)tree::ae(ui[i]=mx[p[i].fi],vi[i]=my[p[i].se]+xtot,i);
	rep(i,1,xtot+ytot+1)if(!tree::vis[i])tree::bfs(i);

	tr::tree_init();
	rep(i,1,n+1)if(del[i]){
		tr::ae(ui[i],vi[i],i);
		tr::ae(vi[i],ui[i],i);
	}
	rep(i,1,xtot+ytot+1)if(!tr::vis[i])tr::bfs(i);

	eu::ini();
	rep(i,1,n+1)if(!del[i]){
		eu::ae(ui[i],vi[i],i);
	}
	rep(i,1,xtot+ytot+1)if(!eu::vis[i]){
		eu::dfs(i);
		rep(j,1,eu::anslen+1)ans[eu::ans[j]]=j&1;
	}

	rep(i,1,n+1)putchar(ans[i]?'r':'b');






#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}