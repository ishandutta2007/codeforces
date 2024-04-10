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
vi a[222222];
vi pos[422222];
int ok[222222];
int ans[222222];

struct edge{
	int v,w,next;
}e[444444];int etot=0;int g[222222];
void ae(int u,int v,int w){
	e[etot].v=v;e[etot].next=g[u];e[etot].w=w;g[u]=etot++;
}
int vv[222222];
int vis[222222];
int st;int okk;
void dfs(int u,int pr=-1){
	vv[u]=1;
	if(ok[u])okk=u;
	for (int i=g[u];~i;i=e[i].next)if(i!=pr){
		if(!vv[e[i].v]){
			dfs(e[i].v,i^1);
		}else if(vv[e[i].v]==1){
			st=e[i].v;
		}
	}
	vv[u]=2;
}

void dfs2(int u,int pr=-1){
	vis[u]=1;
	for (int i=g[u];~i;i=e[i].next)if(i!=pr){
		if(!vis[e[i].v]){
			if(e[i].w>0)ans[e[i].w]=1;
			else ans[-e[i].w]=0;
			dfs2(e[i].v,i^1);
		}else if(vis[e[i].v]==1){
			if(e[i].w>0)ans[e[i].w]=1;
			else ans[-e[i].w]=0;
		}
	}
	vis[u]=2;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	fil(g,-1);
	gn(n);gn(m);
	rep(i,1,n+1){
		int k;
		gn(k);
		while(k--){
			int x;gn(x);
			a[i].pb(x);
			pos[x+m].pb(i);
		}
	}
	fil(ans,-1);
	rep(i,1,m+1){
		int sz=siz(pos[-i+m])+siz(pos[i+m]);
		if(sz==0)continue;
		if(sz==1){
			if(siz(pos[-i+m])){
				ans[i]=0;
				ok[pos[-i+m][0]]=1;
			}else{
				ans[i]=1;
				ok[pos[i+m][0]]=1;
			}
		}else{
			if(!siz(pos[i+m])){
				ans[i]=0;
				ok[pos[-i+m][0]]=1;
				ok[pos[-i+m][1]]=1;
			}else if(!siz(pos[-i+m])){
				ans[i]=1;
				ok[pos[i+m][0]]=1;
				ok[pos[i+m][1]]=1;
			}else{
				ae(pos[i+m][0],pos[-i+m][0],-i);
				ae(pos[-i+m][0],pos[i+m][0],i);
			}
		}
	}
	rep(i,1,n+1)if(!vis[i]){
		okk=st=0;
		dfs(i);
		if(!okk && !st){
			printf("NO\n");
			return 0;
		}
		if(okk)dfs2(okk);
		else dfs2(st);
	}
	printf("YES\n");
	rep(i,1,m+1)printf("%d",max(ans[i],0));
	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}