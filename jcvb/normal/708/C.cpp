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


// manually set n = number of vertices 
// vertex index from 1 to n
// first call tree_init();
// ae(u,v) only one direction
// call lca_build()

const int TREE_MAXV=400000+5;
struct edge{int v,next;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
int n;
void ae(int u,int v){
	e[etot].v=v;
	e[etot].next=g[u];g[u]=etot++;
}
int dfn[TREE_MAXV],rig[TREE_MAXV],pre[TREE_MAXV],h[TREE_MAXV];
int seq[TREE_MAXV*2],eulerseq[TREE_MAXV*2],eulerfirst[TREE_MAXV];

int sz[444444];
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
			sz[u]=1;

			eulerseq[++eulerind]=u;
			eulerfirst[u]=eulerind;
		}
		if(cur[top]==-1){
			rig[u]=ind;	// ends
			sz[pre[u]]+=sz[u];
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
const int ST_UP=20;
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



struct seg{
	int l,r,v;
}t[444444*40];int ndtot=0;
int head[444444];
int add(int x,int l,int r,int i){
	int y=++ndtot;
	t[y]=t[x];
	t[y].v++;
	if(l!=r){
		int mid=l+r>>1;
		if(i<=mid)t[y].l=add(t[x].l,l,mid,i);
		else t[y].r=add(t[x].r,mid+1,r,i);
	}
	return y;
}
int an=0;
int l1,r1;
void quer(int x1,int x2,int l,int r){
	if(l1<=l && r<=r1){
		an+=t[x2].v-t[x1].v;
	}else{
		int mid=l+r>>1;
		if(l1<=mid)quer(t[x1].l,t[x2].l,l,mid);
		if(r1>mid)quer(t[x1].r,t[x2].r,mid+1,r);
	}
}
int check(int l,int r,int lv,int rv){
	if(l>r || lv>rv)return 0;
	l1=lv,r1=rv;
	an=0;
	quer(head[l-1],head[r],1,n);
	return an;
}

int ret[444444];
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	tree_init();
	gn(n);
	readedge();
	dfs(1);

	rep(i,1,n+1){
		head[i]=add(head[i-1],1,n,sz[seq[i]]);
	}

	rep(i,1,n+1)pr[0][i]=pre[i];
	rep(i,1,20)rep(u,1,n+1)pr[i][u]=pr[i-1][pr[i-1][u]];

	rep(u,1,n+1){
		int mi=0;
		int ma=-1;
		int chh=-1;
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
			if(upmax(ma,sz[e[i].v])){
				chh=e[i].v;
			}
		}
		if(u!=1){
			if(upmax(ma,n-sz[u]))chh=pre[u];
		}

		if(ma*2<=n){
			ret[u]=1;
			continue;
		}
		int leas=ma-n/2;
		int nomo=n/2-mi;
		if(leas>nomo)continue;
		if(chh!=pre[u]){
			if(check(dfn[chh],rig[chh],leas,nomo))ret[u]=1;
		}else{
			int v=pre[u];
			for (int i=19;i>=0;i--){
				if(pr[i][v]){
					if(sz[pr[i][v]]<leas)v=pr[i][v];
				}
			}
			if(sz[v]<leas && v!=1)v=pre[v];
			int kk=0;
			if(sz[v]>=leas && sz[v]<=nomo){
				kk++;
				for (int i=19;i>=0;i--){
					if(pr[i][v]){
						if(sz[pr[i][v]]<=nomo){
							v=pr[i][v];
							kk+=1<<i;
						}
					}
				}
			}
			
			if(check(1,dfn[u]-1,leas,nomo)>kk)ret[u]=1;
			else if(check(rig[u]+1,n,leas,nomo))ret[u]=1;
			else{
				leas=n-leas;
				nomo=n-nomo;
				swap(leas,nomo);
				int v=u;
				for (int i=19;i>=0;i--){
					if(pr[i][v]){
						if(sz[pr[i][v]]<leas)v=pr[i][v];
					}
				}
				if(v!=1)v=pre[v];
				if(sz[v]>=leas && sz[v]<=nomo)ret[u]=1;
			}

		}



	}
	rep(i,1,n+1){
		if(i>1)printf(" ");
		printf("%d",ret[i]);
	}

#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}