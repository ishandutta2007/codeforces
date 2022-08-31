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

int n,m;
struct Q{
	char opt;
	int a,b;
	void rd(){
		while((opt=getchar())<'A'||opt>'Z');
		if(opt=='U' || opt=='M')gn(a),gn(b);
		else gn(a);
	}
}que[555555];



int tn;
namespace tre{
	// manually set n = number of vertices 
	// vertex index from 1 to n
	// first call tree_init();
	// ae(u,v) only one direction

	const int TREE_MAXV=1000000+5;
	struct edge{int v,next;}e[TREE_MAXV*2];int g[TREE_MAXV],etot;
	int n;
	void ae(int u,int v){
		e[etot].v=v;
		e[etot].next=g[u];g[u]=etot++;
	}
	int dfn[TREE_MAXV],rig[TREE_MAXV],pre[TREE_MAXV];
	int seq[TREE_MAXV*2];
	void dfs(int rt){
		static int stk[TREE_MAXV],cur[TREE_MAXV];
		int top=0,ind=0;
		pre[rt]=0;
		stk[++top]=rt;
		cur[top]=g[rt];
		while(top){
			int u=stk[top];
			if(cur[top]==g[u]){
				if(u<=tn){
					dfn[u]=++ind;
					seq[ind]=u;	// starts
				}else dfn[u]=ind+1;
			}
			if(cur[top]==-1){
				rig[u]=ind;	// ends
				//rig[u]=++ind;
				top--;
			}else{
				int v=e[cur[top]].v;cur[top]=e[cur[top]].next;
				if(v==pre[u])continue;
				pre[v]=u;
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
};
int rp[555555];
int ndtot;


struct anq{
	int qid;
	int ti;int vid;
	int sg;
}qa[1111111];int qatot=0;
ll ans[555555];
int qtot=0;
int caotot=0;
int cmpqa(const anq&a,const anq&b){
	return a.ti<b.ti;
}


int segma[1111111];
void put(int l,int r,int x,int l1,int r1,int v){
	if(l1<=l && r<=r1){
		segma[x]=v;
	}else{
		int mid=l+r>>1;
		if(l1<=mid)put(l,mid,x<<1,l1,r1,v);
		if(r1>mid)put(mid+1,r,x<<1|1,l1,r1,v);
	}
}
int sque(int l,int r,int x,int I){
	int an=segma[x];
	if(l!=r){
		int mid=l+r>>1;
		if(I<=mid)upmax(an,sque(l,mid,x<<1,I));
		else upmax(an,sque(mid+1,r,x<<1|1,I));
	}
	return an;
}

ll segsu[1111111];
void plu(int l,int r,int x,int l1,int r1,int v){
	if(l1<=l && r<=r1){
		segsu[x]+=v;
	}else{
		int mid=l+r>>1;
		if(l1<=mid)plu(l,mid,x<<1,l1,r1,v);
		if(r1>mid)plu(mid+1,r,x<<1|1,l1,r1,v);
	}
}
ll suque(int l,int r,int x,int I){
	ll an=segsu[x];
	if(l!=r){
		int mid=l+r>>1;
		if(I<=mid)an+=suque(l,mid,x<<1,I);
		else an+=suque(mid+1,r,x<<1|1,I);
	}
	return an;
}

int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);
	rep(i,1,m+1)que[i].rd();

	rep(i,1,n+1){
		rp[i]=i;
	}
	ndtot=n;
	tre::tree_init();
	rep(i,1,m+1){
		int a=que[i].a,b=que[i].b;
		if(que[i].opt=='M'){
			int f=++ndtot;
			tre::ae(f,rp[a]);
			tre::ae(f,rp[b]);
			rp[b]=0;
			rp[a]=f;
		}
	}
	int rt=++ndtot;
	rep(i,1,n+1)if(rp[i])tre::ae(rt,rp[i]);
	tre::n=rt;
	tn=n;
	tre::dfs(rt);

	rep(i,1,n+1){
		rp[i]=i;
	}
	ndtot=n;
	rep(i,1,m+1){
		int a=que[i].a,b=que[i].b;
		if(que[i].opt=='M'){
			int f=++ndtot;
			rp[b]=0;
			rp[a]=f;
		}else if(que[i].opt=='Q'){
			++qtot;
			qa[++qatot]=(anq){i,caotot,a,1};
			qa[++qatot]=(anq){i,sque(1,n,1,tre::dfn[a]),a,-1};
		}else if(que[i].opt=='Z'){
			put(1,n,1,tre::dfn[rp[a]],tre::rig[rp[a]],caotot);
		}else if(que[i].opt=='A'){
			caotot++;
		}
	}

	sort(qa+1,qa+1+qatot,cmpqa);



	rep(i,1,n+1){
		rp[i]=i;
	}
	ndtot=n;
	tre::tree_init();
	rep(i,1,m+1){
		int a=que[i].a,b=que[i].b;
		if(que[i].opt=='U'){
			int f=++ndtot;
			tre::ae(f,rp[a]);
			tre::ae(f,rp[b]);
			rp[b]=0;
			rp[a]=f;
		}
	}
	rt=++ndtot;
	rep(i,1,n+1)if(rp[i])tre::ae(rt,rp[i]);
	tre::n=rt;
	tn=n;
	tre::dfs(rt);

	rep(i,1,n+1){
		rp[i]=i;
	}
	ndtot=n;

	caotot=0;
	int curi=1;
	rep(i,0,m+1){
		if(i>=1){
			int a=que[i].a,b=que[i].b;
			if(que[i].opt=='U'){
				int f=++ndtot;
				rp[b]=0;
				rp[a]=f;
			}else if(que[i].opt=='A'){
				int su=tre::rig[rp[a]]-tre::dfn[rp[a]]+1;
				caotot++;
				plu(1,n,1,tre::dfn[rp[a]],tre::rig[rp[a]],su);
			}
		}
		while(curi<=qatot && qa[curi].ti==caotot){
			ans[qa[curi].qid]+=qa[curi].sg*suque(1,n,1,tre::dfn[qa[curi].vid]);
			curi++;
		}
	}
	rep(i,1,m+1)if(que[i].opt=='Q')printf(lld"\n",ans[i]);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}