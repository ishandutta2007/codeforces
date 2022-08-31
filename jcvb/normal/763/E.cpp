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

int n,k;

vi g[111111];

int fa[111111];
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
int cnt;
void un(int x,int y){
	x=gf(x);y=gf(y);
	if(x!=y){
		cnt--;
		fa[x]=y;
	}
}
void initfa(int l,int r){
	rep(i,l,r+1)fa[i]=i;
	cnt=r-l+1;
}
struct quer{
	int l,r;
	int id;
	void read(){
		gn(l);gn(r);
	}
}que[111111];

int ans[111111];
int q;

int force(int l,int r){
	initfa(l,r);
	rep(u,l,r+1){
		for (int i=0;i<siz(g[u]);i++)if(g[u][i]>=l && g[u][i]<=r)un(u,g[u][i]);
	}
	return cnt;
}

quer tmpl[111111],tmpr[111111],curq[111111];

int rig[111111][15],lef[111111][15];
int rigcnt[111111],lefcnt[111111];

int now[15];int guanlian;
int del;
void toit(){
	static int vis[111111]={0};
	static int faa[111111]={0};
	static int tms=0;
	rep(i,0,10){
		int u=i+del;
		now[i]=gf(u);
	}
	tms++;
	//guanlian=0;
	rep(i,0,10){
		if(vis[now[i]]!=tms){
			//guanlian++;
			faa[now[i]]=i;
			vis[now[i]]=tms;
			now[i]=i;
		}else{
			now[i]=faa[now[i]];
		}
	}
}
const int magic=13;
void work(int l,int r,int ql,int qr){
	if(ql>qr)return;
	if(r-l<=magic){
		rep(t,ql,qr+1)ans[que[t].id]=force(que[t].l,que[t].r);
	}else{
		int mid=l+r>>1;

		int ctot=0,ltot=0,rtot=0;
		rep(t,ql,qr+1){
			if(que[t].r<=mid)tmpl[++ltot]=que[t];
			else if(que[t].l>=mid+1)tmpr[++rtot]=que[t];
			else curq[++ctot]=que[t];
		}


		del=mid-4;
		initfa(mid-4,r);
		int ori=cnt;
		rep(u,mid+1,r+1){
			rep(i,0,siz(g[u])){
				if(g[u][i]>u)continue;
				if(g[u][i]<=mid)continue;
				un(u,g[u][i]);
			}
			toit();
			rep(i,0,10)rig[u][i]=now[i];
			rigcnt[u]=ori-cnt;//hebing cishu
		}


		initfa(l,mid+5);
		ori=cnt;
		per(u,l,mid+1){
			rep(i,0,siz(g[u])){
				if(g[u][i]>mid)continue;
				if(g[u][i]<u)continue;
				un(u,g[u][i]);
			}
			toit();
			rep(i,0,10)lef[u][i]=now[i];
			lefcnt[u]=ori-cnt;
		}
		//
		//
		rep(t,1,ctot+1){
			if(curq[t].r-curq[t].l<=magic)ans[curq[t].id]=force(curq[t].l,curq[t].r);
			else{
				int l=curq[t].l;
				int r=curq[t].r;
				for (int j=0;j<=4;j++)fa[j]=lef[l][j];
				for (int j=5;j<=9;j++)fa[j]=rig[r][j];
				int alr=lefcnt[l]+rigcnt[r];

				int ori=cnt;

				rep(j,0,10){
					int u=del+j;
					if(u<l || u>r)continue;
					rep(i,0,siz(g[u])){
						int v=g[u][i];
						if(v<l || v>r)continue;
						if(v<mid-4 || v>mid+5)continue;
						un(j,v-del);
					}
				}
				alr+=ori-cnt;
				ans[curq[t].id]=r-l+1 - alr;
			}
		}
		int t=ql;
		rep(i,1,ltot+1){
			que[t++]=tmpl[i];
		}
		int lef=t;
		rep(i,1,rtot+1){
			que[t++]=tmpr[i];
		}
		work(l,mid,ql,lef-1);
		work(mid+1,r,lef,t-1);
	}
}
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(k);
	int m;gn(m);
	while(m--){
		int u,v;
		gn(u);gn(v);
		g[u].pb(v);
		g[v].pb(u);
	}
	gn(q);
	rep(i,1,q+1){
		que[i].read();
		que[i].id=i;
	}

	work(1,n,1,q);
	rep(i,1,q+1)printf("%d\n",ans[i]);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}