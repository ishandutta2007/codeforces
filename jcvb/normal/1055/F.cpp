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
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	c=='-'?(sg=-1,x=0):(x=c-'0');
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
const int TREE_MAXV=1100000+5;
struct edge{int v,next;ll w;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
int qu[TREE_MAXV],pre[TREE_MAXV];
int n;
void ae(int u,int v,ll w){
	e[etot].v=v;
e[etot].w=w;
	e[etot].next=g[u];g[u]=etot++;
}

ll h[TREE_MAXV];
void bfs(int rt){
	int p=0,q=0;
	pre[rt]=0;
	qu[q++]=rt;
	h[rt]=0;
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
			pre[e[i].v]=u;
				h[e[i].v]=h[u]^e[i].w;
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
	for (int i=2;i<=n;i++){
		int x=i,y;
		gn(y);
		//y=1;
			ll w;
		gn(w);
		//w=rand();
		ae(x,y,w);ae(y,x,w);
	}
}


ll k;


ll ans;

ll so[1111111];
int lef[1111111],rig[1111111];
int fen[1111111];
void ffen(int b) {
	int laslef=0;
	ll lastag=-1;
	int change=-1;
	rep(i,1,n+2) {
		ll tag = so[i]>>(b+1);
		if(tag!=lastag) {
			if(change==-1)change = i;
			fen[laslef]=change;
			lastag = tag;
			change=-1;
			laslef = i;
		}

		ll bit = (so[i]>>b)&1;
		if(change==-1 && bit==1) {
			change = i;
		}
	}
}
int main()
{
	gn(n);
	gn(k);
	int origk=k;
	tree_init();
	readedge();
	bfs(1);

	sort(h+1,h+1+n);

	h[n+1] = pw(62);
	rep(i,1,n+2)so[i]=h[i];

	rep(i,1,n+1)lef[i]=1,rig[i]=n+1;
	for (int i=61;i>=0;i--) {
		ffen(i);
		ll sumleft=0;

		rep(u,1,n+1) {
			if(rig[u]<=lef[u])continue;
			ll bit = (so[u]>>i)&1;
			if(bit==0) {
				sumleft += fen[lef[u]] - lef[u];
			} else sumleft += rig[u] - fen[lef[u]];
		}
		if(k<=sumleft) {
			rep(u,1,n+1)if(lef[u]<rig[u]) {
				if((so[u]>>i)&1)lef[u]=fen[lef[u]];
				else rig[u] = fen[lef[u]];
			}
		} else {
			ans|=pw(i);
			k-=sumleft;
			rep(u,1,n+1)if(lef[u]<rig[u]){
				if((so[u]>>i)&1)rig[u] = fen[lef[u]];
				else lef[u]=fen[lef[u]];
			}
		}
	}


	/*vector<ll> f;
	rep(i,1,n+1)rep(j,1,n+1)f.pb(h[i]^h[j]);
	sort(all(f));
	ll rr = f[origk-1];*/

	//cout<<"force"<<rr<<endl;
	cout<<ans<<endl;
	return 0;
}