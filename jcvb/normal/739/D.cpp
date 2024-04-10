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


char str[111];
struct node{
	int pre,len,id;
	void read(){
		int tmp;

		scanf("%s",str);
		if(str[0]=='?')tmp=-1;
		else{
			int su=0;
			for (int i=0;str[i];i++)su=su*10+str[i]-'0';
			tmp=su;
		}
		pre=tmp;

		scanf("%s",str);
		if(str[0]=='?')tmp=-1;
		else{
			int su=0;
			for (int i=0;str[i];i++)su=su*10+str[i]-'0';
			tmp=su;
		}
		len=tmp;
	}
}a[333];
int n;

vi cyc[333];




// first call dinic_init();
// ae(u,v,capacity)
// v index from 1, e index from 0
// s=1,t=2 by default, need not set vtot manually

typedef int dinic_nu;
const dinic_nu dinic_inf=0x3f3f3f3f;
const int DINIC_MAXV=555555+5;
const int DINIC_MAXE=555555+5;

int s,t,vtot;
struct edge{int v,next;dinic_nu f;}e[DINIC_MAXE*2];int g[DINIC_MAXV],etot,eid;
int ae(int u,int v,dinic_nu f){
	upmax(vtot,u);upmax(vtot,v);
	e[etot].v=v;e[etot].f=f;e[etot].next=g[u];g[u]=etot++;
	e[etot].v=u;e[etot].f=0;e[etot].next=g[v];g[v]=etot++;
	return eid++;
}
int d[DINIC_MAXV];
bool lb(){
	for (int i=0;i<=vtot;i++)d[i]=0;
	static int qu[DINIC_MAXV];
	int p=0,q=0;
	qu[q++]=s,d[s]=1;
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].next)if(e[i].f && !d[e[i].v]){
			d[e[i].v]=d[u]+1;
			if(e[i].v==t)return 1;
			qu[q++]=e[i].v;
		}
	}return 0;
}
dinic_nu aug(int u,dinic_nu mi){
	if(u==t)return mi;
	dinic_nu su=0,del;
	for (int i=g[u];~i;i=e[i].next)if(e[i].f && d[e[i].v]==d[u]+1){
		del=aug(e[i].v,min(mi,e[i].f));
		e[i].f-=del;e[i^1].f+=del;
		mi-=del;su+=del;
		if(!mi)break;
	}
	if(!su)d[u]=-1;
	return su;
}
dinic_nu dinic(){
	dinic_nu su=0;
	while(lb())su+=aug(s,dinic_inf);
	return su;
}
void dinic_init(){
	static bool ini=0;
	if(!ini){
		ini=1;
		memset(g,-1,sizeof(g));
	}else{
		for (int i=0;i<=vtot;i++)g[i]=-1;
	}
	etot=eid=0;
	vtot=2,s=1,t=2;
}
//0 <= ei < (etot>>1)
inline dinic_nu capaof(int ei){return e[ei<<1].f+e[ei<<1^1].f;}
inline dinic_nu flowof(int ei){return e[ei<<1^1].f;}
inline dinic_nu resiof(int ei){return e[ei<<1].f;}
inline int uof(int ei){return e[ei<<1^1].v;}
inline int vof(int ei){return e[ei<<1].v;}

int have[333][333];
int cycex[333];
int cycnd[333];
int cychi[333];
int fix[333];
int reqcyc[1111],reqpre[1111];
int ndtot;
int addid[333][1111];
int goes[333];
int ans[333];
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	int totmaxhi=0;
	gn(n);
	int boo=0;
	rep(i,1,n+1){
		a[i].read();
		a[i].id=i;
		if(a[i].len!=-1 && a[i].pre!=-1)fix[i]=1;
		if(a[i].len!=-1)cycex[a[i].len]=1;
		upmax(totmaxhi,a[i].pre);
		if(a[i].len!=-1)boo=1;
	}

	if(!boo){
		cycex[1]=1;
	}
	rep(i,1,n+1){
		if(a[i].pre==0 && a[i].len!=-1)
			cyc[a[i].len].pb(i);
	}

	rep(i,1,n+1)if(cycex[i]){
		if(!cyc[i].empty()){
			int x=cyc[i].size();
			cycnd[i]=cei(x,i)*i-x;
		}else{
			cycnd[i]=i;
		}
		int mhi=0;
		rep(j,1,n+1)if(a[j].len==i && a[j].pre>=1){
			upmax(mhi,a[j].pre);
			have[i][a[j].pre]=j;
		}
		cychi[i]=mhi;
	}
	
	/*if(totmaxhi>=1){
		int bo=0;
		int curmax=0;
		rep(i,1,n+1)if(cycex[i])
			upmax(curmax,cychi[i]);
		if(totmaxhi>curmax){
			rep(j,1,n+1)if(cycex[j] && cychi[j]==curmax){
				cychi[j]=totmaxhi;
				break;
			}
		}
	}*/

	static int ori[333];
	rep(i,1,n+1)ori[i]=cychi[i];
	rep(qq,1,n+1)if(cycex[qq]){
		rep(j,1,n+1)cychi[j]=ori[j];
		cychi[qq]=totmaxhi;

		int totned=0;
		rep(i,1,n+1)totned+=cycnd[i];

		rep(i,1,n+1)if(cycex[i]){
			rep(j,1,cychi[i]+1)if(!have[i][j])totned++;
		}
		int frenum=0;
		rep(i,1,n+1)if(!fix[i])frenum++;
		if(frenum<totned){
			continue;
		}
		fil(addid,-1);
		dinic_init();
		ndtot=n+n;
		rep(i,1,n+1)if(cycex[i]){
			rep(j,1,cychi[i]+1)if(!have[i][j]){
				++ndtot;
				reqcyc[ndtot]=i;
				reqpre[ndtot]=j;
			}
		}
		s=ndtot+1;
		t=ndtot+2;
		rep(i,1,n+1)if(!fix[i]){
			ae(s,i,1);
			if(a[i].pre<=0){
				if(a[i].len==-1)rep(j,n+1,n+n+1)addid[i][j]=ae(i,j,inf);
				else addid[i][n+a[i].len]=ae(i,n+a[i].len,inf);
			}
			rep(j,n+n+1,ndtot+1){
				if(a[i].len!=-1 && a[i].len!=reqcyc[j])continue;
				if(a[i].pre!=-1 && a[i].pre!=reqpre[j])continue;
				addid[i][j]=ae(i,j,inf);
			}
		}
		rep(i,n+n+1,ndtot+1)ae(i,t,1);
		rep(i,1,n+1)if(cycex[i])ae(n+i,t,cycnd[i]);
		if(dinic()!=totned){
			continue;
		}

		rep(i,1,n+1)if(!fix[i]){
			rep(j,n+1,ndtot+1)if(~addid[i][j] && flowof(addid[i][j])){
				goes[i]=j;
				break;
			}
		}

		rep(i,1,n+1)if(!fix[i] && goes[i]){
			if(goes[i]<=n+n){
				cyc[goes[i]-n].pb(i);
			}else{
				have[reqcyc[goes[i]]][reqpre[goes[i]]]=i;
			}
		}


		rep(i,1,n+1)
			if(cycex[i]){
				rep(j,0,cyc[i].size()){
					if(j%i==0)ans[cyc[i][j]]=cyc[i][j+i-1];
					else ans[cyc[i][j]]=cyc[i][j-1];
				}
				have[i][0]=cyc[i][0];
				rep(j,1,cychi[i]+1){
					ans[have[i][j]]=have[i][j-1];
					assert(have[i][j]!=0);
				}
			}

		rep(i,1,n+1)if(ans[i]==0){
			if(fix[i]){
				ans[i]=have[a[i].len][a[i].pre-1];
			}else if(a[i].len==-1 && a[i].pre==-1){
				ans[i]=i;
			}else if(a[i].len==-1){
				rep(j,1,n+1)if(cycex[j] && cychi[j]>=a[i].pre){
					ans[i]=have[j][a[i].pre-1];
					break;
				}
				if(!ans[i])ans[i]=i;
			}else{
				ans[i]=have[a[i].len][0];
			}
		}
		rep(i,1,n+1){
			printf("%d ",ans[i]);
		}
		return 0;
	}
	printf("-1\n");

#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}