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


// manually set n = number of vertices 
// vertex index from 1 to n
// first call tree_init();
// ae(u,v) only one direction

const int TREE_MAXV=100000+5;
struct edge{int v,w,next;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
int qu[TREE_MAXV],pre[TREE_MAXV],sz[TREE_MAXV],ma[TREE_MAXV],bel[TREE_MAXV];
ll h[TREE_MAXV];
int tot;
int n;
void ae(int u,int v,int w){
	e[etot].v=v;e[etot].w=w;
	e[etot].next=g[u];g[u]=etot++;
}
void bfs(int rt){
	tot=0;
	int p=0,q=0;
	pre[rt]=0;
	qu[q++]=rt;
	h[rt]=0;
	bel[rt]=0;
	while(p!=q){
		int u=qu[p++];
		sz[u]=1;
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
			pre[e[i].v]=u;
			h[e[i].v]=h[u]+e[i].w;
			qu[q++]=e[i].v;
			if(bel[u]==0)bel[e[i].v]=++tot;
			else bel[e[i].v]=bel[u];
		}
	}
	bel[rt]=++tot;
	per(i,1,q)sz[pre[qu[i]]]+=sz[qu[i]];
	rep(u,1,n+1){
		ma[u]=n-sz[u];
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u])upmax(ma[u],sz[e[i].v]);
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
		int x,y,w;gn(x);gn(y);gn(w);
		ae(x,y,w);ae(y,x,w);
	}
}


vi cen;
int ou[111111];
int ans[111111];
void upans(){
	for (int i=1;i<=n;i++)if(ans[i]!=ou[i]){
		if(ans[i]>ou[i])return;
		else{
			rep(j,1,n+1)ou[j]=ans[j];
			return;
		}
	}
}
int cnt[111111];
set<int> se[111111];
set<int> big;
int curdel;
set<int> zer;
set<pii> du;


void link(int x,int y){
	int bx=bel[x],by=bel[y];
	assert(bx!=by);
	ans[x]=y;

	big.erase(y);
	se[by].erase(y);
	if(!se[by].empty())big.insert(*se[by].begin());

	du.erase(mp(cnt[bx],bx));
	du.erase(mp(cnt[by],by));
	cnt[bx]++;cnt[by]++;curdel++;
	du.insert(mp(cnt[bx],bx));
	du.insert(mp(cnt[by],by));

	foreach(it,du){
		if(it->fi!=curdel)break;
		if(zer.find(it->se)!=zer.end())continue;
		zer.insert(it->se);
	}
}
void work(){
	ans[1]=inf;
	if(n==0)return;
	if(tot<=1)return;
	cl(cnt);
	rep(i,1,n+1)se[i].clear();
	rep(i,1,n+1){
		cnt[bel[i]]++;
		se[bel[i]].insert(i);
	}
	curdel=0;
	zer.clear();
	du.clear();
	rep(i,1,tot+1){
		cnt[i]=n-cnt[i]-cnt[i];
		if(cnt[i]==0)zer.insert(i);
		du.insert(mp(cnt[i],i));
	}
	rep(i,1,tot+1)big.insert(*se[i].begin());

	rep(i,1,n+1){
		int b=bel[i];

		int to;
		if(siz(zer)>(curdel==cnt[b])){
			foreach(it,zer)if(*it!=b){
				to=*it;
				break;
			}
		}else{
			int x;
			foreach(it,big){
				if(bel[*it]!=b){
					x=*it;
					break;
				}
			}
			to=bel[x];
		}
		int ya=*se[to].begin();
		link(i,ya);
	}
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	tree_init();
	readedge();
	bfs(1);

	rep(i,1,n+1)if(ma[i]*2<=n)cen.pb(i);

	bfs(cen[0]);
	ll su=0;
	rep(i,1,n+1)su+=h[i];
	su<<=1;
	cout<<su<<endl;


	ou[1]=n+1;
	rep(i,0,siz(cen)){
		bfs(cen[i]);
		work();
		upans();

		int x=cen[i];
		if(ma[x]*2<n){
			for (int j=x+1;j<=n;j++)bel[j-1]=bel[j];
			tot--;
			n--;
			work();
			n++;
			for (int j=n;j>=x+1;j--)ans[j]=ans[j-1];
			rep(i,1,n+1)if(ans[i]>=x)ans[i]++;
			ans[x]=x;
			upans();
		}
	}
	rep(i,1,n+1)printf("%d ",ou[i]);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}