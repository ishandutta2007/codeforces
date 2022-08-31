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
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


// manually set n = number of vertices 
// vertex index from 1 to n
// first call tree_init();
// ae(u,v) only one direction
// call lca_build()

const int TREE_MAXV=1000000+5;
struct edge{int v,next;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
int n;
void ae(int u,int v){
	e[etot].v=v;
	e[etot].next=g[u];g[u]=etot++;
}
int dfn[TREE_MAXV],rig[TREE_MAXV],pre[TREE_MAXV],h[TREE_MAXV];
int seq[TREE_MAXV*2],eulerseq[TREE_MAXV*2],eulerfirst[TREE_MAXV];
int pr[33][TREE_MAXV];
void dfs(int rt){
	static int stk[TREE_MAXV],cur[TREE_MAXV];
	int top=0,ind=0,eulerind=0;
	pre[rt]=0;
	h[rt]=0;
	stk[++top]=rt;
	cur[top]=g[rt];
	while(top){
		int u=stk[top];
		if(cur[top]==g[u]){
			dfn[u]=++ind;
			seq[ind]=u;	// starts

			eulerseq[++eulerind]=u;
			eulerfirst[u]=eulerind;
		}
		if(cur[top]==-1){
			rig[u]=ind;	// ends
			//rig[u]=++ind;		

			if(u!=rt)eulerseq[++eulerind]=pre[u];

			top--;
		}else{
			int v=e[cur[top]].v;cur[top]=e[cur[top]].next;
			if(v==pre[u])continue;
			pre[v]=u;
			h[v]=h[u]+1;
			stk[++top]=v;
			cur[top]=g[v];
					// new node information
		}
	}
	rep(i,1,n+1)pr[0][i]=pre[i];
	rep(j,1,20)
		rep(u,1,n+1)pr[j][u]=pr[j-1][pr[j-1][u]];
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
/*const int ST_UP=20;
int pr[ST_UP][TREE_MAXV*2];
inline int getmin(int a,int b){return h[a]<h[b]?a:b;}
int st[ST_UP][TREE_MAXV*2];
int st_l2[TREE_MAXV*2];
void lca_build(){
	st_l2[1]=0;rep(i,2,2*n)st_l2[i]=st_l2[i-1]+(i&(i-1)?0:1);
	rep(i,1,2*n)st[0][i]=eulerseq[i];
	rep(k,1,ST_UP)
		for (int i=1;i+(1<<k)-1<=2*n-1;i++)
			st[k][i]=getmin(st[k-1][i],st[k-1][i+(1<<(k-1))]); 
}
int lca(int u,int v){
	int l=eulerfirst[u],r=eulerfirst[v];
	if(l>r)swap(l,r);
	int k=st_l2[r-l+1];
	return getmin(st[k][l],st[k][r-(1<<k)+1]);				
}
*/


// range update, range query
// index 1..n
// first call seginit(n)

struct seg_nu{
	int mi;
	int minum;
};
seg_nu operator+(const seg_nu &a,int b) {
	return (seg_nu){a.mi+b,a.minum};
}
seg_nu operator+(const seg_nu &a,const seg_nu &b){
	if(a.mi<b.mi)return a;
	else if (a.mi>b.mi)return b;
	else return (seg_nu){a.mi,a.minum+b.minum};
}
typedef int seg_tag;
const int SEG_MAXN=1000000+5;

int seglen[SEG_MAXN*4];
seg_nu seg[SEG_MAXN*4];
seg_tag tag[SEG_MAXN*4];
seg_tag tag0 = 0;						
inline void segadd(int x,seg_tag v){
	seg[x]=seg[x]+v;				
	tag[x]=tag[x]+v;				
}
inline void segpd(int x){
	if(tag[x]!=tag0){
		segadd(x<<1,tag[x]);
		segadd(x<<1|1,tag[x]);
		tag[x]=tag0;					
	}
}
inline void segpu(int x){
	seg[x]=seg[x<<1]+seg[x<<1|1];				
}
void seginit_in(int l,int r,int x){
	tag[x]=tag0;						
	seglen[x]=r-l+1;
	if(l==r){
		//seg[x]=a[l];
		seg[x]=(seg_nu){0,1};					
	}else{
		int mid=l+r>>1;
		seginit_in(l,mid,x<<1);
		seginit_in(mid+1,r,x<<1|1);
		segpu(x);
	}
}
int l1,r1;
seg_nu sans; bool ans_bo;
seg_tag stag;
void segupd_in(int l,int r,int x){
	//if(l1>r1)return;
	if(l1<=l && r<=r1){
		segadd(x,stag);
	}else{
		int mid=l+r>>1;
		segpd(x);
		if(l1<=mid)segupd_in(l,mid,x<<1);
		if(r1>mid)segupd_in(mid+1,r,x<<1|1);
		segpu(x);
	}
}
int segn;
void segupd(int l,int r,seg_tag v){
	if(l>r)return;
	stag=v,l1=l,r1=r;
	segupd_in(1,segn,1);
}
/*seg_nu segque(int l,int r){
	if(l>r)return 0;					//modify
	ans_bo=0,l1=l,r1=r;
	segque_in(1,segn,1);
	return sans;
}
*/
void seginit(int n){
	segn=n;
	seginit_in(1,segn,1);
}
map<pair<int,int>,int> ma;

void gao(int u,int v,int del) {
	if(dfn[u]>=dfn[v] && rig[u]<=rig[v]) {
		swap(u,v);
	}
	if(dfn[v]>=dfn[u] && rig[v]<=rig[u]) {
		int x=v;
		int need  =h[v]-h[u]-1;
		for(int i=0;need;i++)if(pw(i)&need) {
			need^=pw(i);
			x=pr[i][x];
		}
		segupd(dfn[x],rig[x],del);
		segupd(dfn[v],rig[v],-del);
	}else {
		if(rig[v]<=dfn[u])swap(u,v);
		segupd(1,dfn[u]-1,del);
		segupd(rig[u]+1,dfn[v]-1,del);
		segupd(rig[v]+1,n,del);
	}
}
int main()
{
	int q;
	gn(n);gn(q);
	tree_init();
	readedge();
	dfs(1);
	seginit(n);
	while(q--){
		int u,v;
		gn(u);gn(v);
		if(u>v)swap(u,v);
		int opt = (ma[mp(u,v)]^=1);
		if(opt==0)opt=-1;
		gao(u,v,opt);
		printf("%d\n",seg[1].mi==0?seg[1].minum:0);
	}
	return 0;


}