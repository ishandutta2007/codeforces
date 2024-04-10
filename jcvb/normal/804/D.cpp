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

// manually set n = number of vertices 
// vertex index from 1 to n
// first call tree_init();
// ae(u,v) only one direction

const int S = 400;
int fa[222222];
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
int consz[222222];//only defined for father

int zhijing[222222];

const int TREE_MAXV=200000+5;
struct edge{int v,next;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
int qu[TREE_MAXV],pre[TREE_MAXV],h[222222];
int n;
void ae(int u,int v){
	e[etot].v=v;
	e[etot].next=g[u];g[u]=etot++;
}
int zuiyuan[222222];//zuiyuan lujing
int p,q;
void bfs(int rt){
	p=0,q=0;
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
vector<ll> ele[222222],su[222222];// father   <=   list  not su
// size q+1 [0..q]
vi big;

map<pii,db> jiyi;

db workit(int rs,int rb){
	bfs(rs);
	db ans=0.0;

	int ns=ele[rs].size()-1;
	int nb=ele[rb].size()-1;

	int alr = max(zhijing[rs],zhijing[rb]);

	rep(j,0,q){
		int u=qu[j];
		int d1=zuiyuan[u];
		if(d1+1+zhijing[rb]<=alr){
			ans+=1.0*nb*alr;
		}else{
			int j=lower_bound(ele[rb].begin()+1,ele[rb].end(),alr-d1-1+1)-ele[rb].begin();
			ans+=1.0*(j-1)*alr;
			ans+=1.0*(su[rb][nb]-su[rb][j-1])+1.0*(d1+1)*(nb-j+1);
		}
	}
	return ans/ns/nb;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	int m,que;
	tree_init();
	gn(n);gn(m);gn(que);
	rep(i,1,n+1)fa[i]=i;
	for (int i=1;i<=m;i++){
		int x,y;gn(x);gn(y);
		ae(x,y);ae(y,x);
		fa[gf(x)]=gf(y);
	}

	rep(i,1,n+1)if(i==gf(i)){
		bfs(i);
		consz[i]=q;
		int u=i;
		rep(j,0,q){
			int v=qu[j];
			consz[v]=q;
			if(h[v]>h[u])u=v;
		}
		bfs(u);
		int w=u;
		rep(j,0,q){
			int v=qu[j];
			upmax(zuiyuan[v],h[v]);
			if(h[v]>h[w]){
				w=v;
			}
		}
		zhijing[i]=h[w];
		bfs(w);
		ele[i].pb(0);
		rep(j,0,q){
			int v=qu[j];
			zhijing[v]=zhijing[i];
			upmax(zuiyuan[v],h[v]);
			ele[i].pb(zuiyuan[v]);
		}
		sort(all(ele[i]));
		su[i].resize(q+1);
		su[i][0]=0;
		rep(j,1,q+1){
			su[i][j]=ele[i][j]+su[i][j-1];
		}
	}

	rep(i,1,n+1)if(gf(i)==i && consz[i]>S){
		big.pb(i);
	}
	rep(ii,0,siz(big))rep(jj,ii+1,siz(big)){
		int i=big[ii],j=big[jj];
		db ans = workit(i,j);
		jiyi[mp(i,j)]=jiyi[mp(j,i)]=ans;
	}

	while(que--){
		int u,v;
		gn(u);gn(v);
		u=gf(u);v=gf(v);
		if(gf(u)==gf(v)){
			printf("-1\n");
		}else{
			if(consz[u]>consz[v])swap(u,v);
			db an;
			if(jiyi.count(mp(u,v)))an=jiyi[mp(u,v)];
			else an=workit(u,v);
			printf("%.10lf\n",an);
		}
	}


#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}