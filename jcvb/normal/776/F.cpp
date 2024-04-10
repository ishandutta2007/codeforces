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

vi verlist[111111];
int ord[111111],pos[111111];
int regtot=0;

int cmp(int i,int j){
	for (int k=0;;k++){
		int iv=k<verlist[i].size()?verlist[i][k]:-1;
		int jv=k<verlist[j].size()?verlist[j][k]:-1;
		if(iv!=jv){
			return iv<jv;
		}
	}
}
vi adjlist[111111];
int n,m;

int getnex(int u,int v){
	int i=lower_bound(all(adjlist[u]),v)-adjlist[u].begin();
	if(i==0)return adjlist[u].back();
	else return adjlist[u][i-1];
}

map<pii,int>vis;//fi -> se





const int TREE_MAXV=300000+5;
struct edge{int v,next;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
int qu[TREE_MAXV],pre[TREE_MAXV];
void ae(int u,int v){
	if(u>v)return;
	e[etot].v=v; e[etot].next=g[u];g[u]=etot++;
	e[etot].v=u; e[etot].next=g[v];g[v]=etot++;
}
void bfs(int rt){
	int p=0,q=0;
	pre[rt]=0;
	qu[q++]=rt;
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
			pre[e[i].v]=u;
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

int f[333333];
int ret[333333];
void work(int u){
	int gg=0,tmp=0;
	for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
		gg|=f[e[i].v]&tmp;
		tmp|=f[e[i].v];
	}
	if(gg>0){
		while(gg&(gg-1))gg&=gg-1;
		tmp|=gg|(gg-1);
	}

	f[u]=tmp+1;
	ret[u]=bul2(f[u]&-f[u]);
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);

	rep(i,1,m+1){
		int a,b;
		gn(a);gn(b);
		a--,b--;
		adjlist[a].pb(b);
		adjlist[b].pb(a);
	}
	rep(i,0,n){
		int a=i,b=(i+1)%n;
		adjlist[a].pb(b);
		adjlist[b].pb(a);
		vis[mp(b,a)]=-1;
	}

	rep(i,0,n){
		sort(all(adjlist[i]));
	}

	rep(u,0,n){
		rep(j,0,siz(adjlist[u])){
			int v=adjlist[u][j];
			if(!vis[mp(u,v)]){
				regtot++;
				int curu=u;
				int curv=v;
				while(1){
					int nex=getnex(curv,curu);
					vis[mp(curu,curv)]=regtot;
					verlist[regtot].pb(curu);
					if(curv==u)break;
					curu=curv;
					curv=nex;
				}
			}
		}
	}

	rep(r,1,regtot+1){
		ord[r]=r;
		sort(all(verlist[r]));
		reverse(all(verlist[r]));
	}
	sort(ord+1,ord+1+regtot,cmp);

	rep(i,1,regtot+1)pos[ord[i]]=i;

	tree_init();

	for (auto it=vis.begin();it!=vis.end();it++){
		int a=it->fi.fi,b=it->fi.se;
		int to=vis[mp(b,a)];
		if(it->se==-1 || to==-1)continue;
		ae(pos[to],pos[it->se]);
	}

	n=regtot;

	bfs(1);

	for(int i=n-1;i>=0;i--)work(qu[i]);
	int ma=0;
	rep(i,1,n+1)upmax(ma,ret[i]);
	rep(i,1,n+1) printf("%d ",ma+1-ret[i]);


#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}