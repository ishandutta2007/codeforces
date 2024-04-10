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
const ll inf=1e18;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

struct edge{
	int v,next;
}e[422222];int g[222222];int etot=0;
void ae(int u,int v){
	e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
int n;
int m,q;
int qu[222222];int son[222222];int sz[222222],pre[222222];int idtot;
int h[222222];
int up[222222];
void bfs(int rt){
	sz[0]=0;
	int p=0,q=0;
	qu[q++]=rt;
	pre[rt]=0;
	while(p!=q){
		int u=qu[p++];
		sz[u]=1;
		son[u]=0;
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
			int v=e[i].v;
			pre[v]=u;
			h[v]=h[u]+1;
			qu[q++]=v;
		}
	}
	for (int i=q-1;i>=1;i--){
		sz[pre[qu[i]]]+=sz[qu[i]];
		if(sz[qu[i]]>sz[son[pre[qu[i]]]]){
			son[pre[qu[i]]]=qu[i];
		}
	}
	for (int i=q-1;i>=0;i--){
		int u=qu[i];
		if(son[u]==0){
			int v=u;
			while(son[pre[v]]==v)v=pre[v];
			int w=v;
			while(w){
				up[w]=v;
				w=son[w];
			}
		}
	}
}

void adjust(){
	for (int u=1;u<=n;u++)if(son[u]){
		int v=son[u],w=e[g[u]].v;
		if(w==pre[u]){
			int t=g[u];t=e[t].next;
			w=e[t].v;
		}
		int vi,wi;
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
			if(e[i].v==v)vi=i;
			if(e[i].v==w)wi=i;
		}
		swap(e[vi].v,e[wi].v);
	}
}
int cur[222222];
int dfn[222222],rig[222222];int ind=0;
int seq[222222];
void dfs(int rt){
	int top=0;
	qu[++top]=rt;
	cur[top]=g[rt];
	while(top){
		int u=qu[top];
		if(cur[top]==g[u]){
			seq[dfn[u]=++ind]=u;
		}
		if(cur[top]!=-1){
			int v=e[cur[top]].v;
			cur[top]=e[cur[top]].next;
			if(v!=pre[u]){
				qu[++top]=v;
				cur[top]=g[v];
			}
		}else{
			rig[u]=ind;
			top--;
		}
	}
}

int resi[222222];

deque<int> gir[222222];


struct node{
	ll wei;int resi;
};
int operator<(const node&a,const node&b){
	if(a.wei==b.wei)return a.resi<b.resi;
	return a.wei<b.wei;
}
int operator>(const node&a,const node&b){
	return b<a;
}

node seg[444444];
ll tag[444444];


int l1,r1,v;

void add(int x,ll v){
	seg[x].wei+=v;
	tag[x]+=v;
}
void pd(int x){
	if(tag[x]){
		add(x<<1,tag[x]);
		add(x<<1|1,tag[x]);
		tag[x]=0;
	}
}
void upd(int l,int r,int x){
	if(l1<=l && r<=r1){
		add(x,v);
	}else{
		pd(x);
		int mid=l+r>>1;
		if(l1<=mid)upd(l,mid,x<<1);
		if(r1>mid)upd(mid+1,r,x<<1|1);
		seg[x]=min(seg[x<<1],seg[x<<1|1]);
	}
}
int I;
ll udel;
void upd1(int l,int r,int x){
	if(l==r){
		int u=seq[l];
		ll kk;
		if(gir[u].empty())kk=inf;
		else kk=gir[u][0]+udel;
		seg[x]=(node){kk,u};
	}else{
		int mid=l+r>>1;
		pd(x);
		if(I<=mid)upd1(l,mid,x<<1);
		else upd1(mid+1,r,x<<1|1);
		seg[x]=min(seg[x<<1],seg[x<<1|1]);
	}
}
void ini(int l,int r,int x){
	if(l==r){
		int u=seq[l];
		ll kk;
		if(gir[u].empty())kk=inf;
		else kk=gir[u][0];
		seg[x]=(node){kk,u};
	}else{
		int mid=l+r>>1;
		ini(l,mid,x<<1);
		ini(mid+1,r,x<<1|1);
		seg[x]=min(seg[x<<1],seg[x<<1|1]);
	}
}
node tmp;
void que(int l,int r,int x){
	if(l1<=l && r<=r1){
		upmin(tmp,seg[x]);
	}else{
		pd(x);
		int mid=l+r>>1;
		if(l1<=mid)que(l,mid,x<<1);
		if(r1>mid)que(mid+1,r,x<<1|1);
	}
}



int tmpans[111111];int ttot=0;


node quer(int a,int b){
	tmp.wei=inf;
	while(up[a]!=up[b]){
		if(h[up[a]]<h[up[b]])swap(a,b);
		l1=dfn[up[a]],r1=dfn[a];
		que(1,n,1);
		a=pre[up[a]];
	}
	if(h[a]>h[b])swap(a,b);
	l1=dfn[a],r1=dfn[b];
	que(1,n,1);
	return tmp;
}
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
#endif
	memset(g,-1,sizeof(g));

	gn(n);gn(m);gn(q);
	for (int i=2;i<=n;i++){
		int x,y;gn(x);gn(y);
		ae(x,y);
		ae(y,x);
	}
	bfs(1);
	adjust();
	dfs(1);

	rep(i,1,m+1){
		gn(resi[i]);
		gir[resi[i]].pb(i);
	}

	ini(1,n,1);
	while(q--){
		int opt;gn(opt);
		if(opt==1){
			int u,v,k;
			gn(u);gn(v);gn(k);
			ttot=0;

			rep(i,1,k+1){
				node mi=quer(u,v);

				if(mi.wei>=inf){
					break;
				}else{
					int re=mi.resi;
					int id=gir[re][0];
					udel=mi.wei-id;
					tmpans[++ttot]=id;
					gir[re].pop_front();
					I=dfn[re];
					upd1(1,n,1);
				}
			}
			printf("%d",ttot);
			rep(i,1,ttot+1)printf(" %d",tmpans[i]);
			printf("\n");
		}else{
			int u,k;
			gn(u);gn(k);
			l1=dfn[u];
			r1=rig[u];
			v=k;
			upd(1,n,1);
		}
	}
	return 0;
}