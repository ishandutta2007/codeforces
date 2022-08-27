#include<cstdio>
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
int inf=0x3f3f3f3f;
db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
int n,m;
char str[111][111];

int id[111][111];
int ndtot;

int fa[11111];
int gf(int x){return x==fa[x]?x:fa[x]=gf(fa[x]);}
pii e[11111];
int un(int a,int b){
	if(gf(a)==gf(b))return 0;
	fa[gf(a)]=gf(b);
	return 1;
}
map<int,int>maa;

int a[666][666];
int gauss(int n){
	int ans=1;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			while(a[j][i]){
				int t=a[i][i]/a[j][i];
				for (int k=i;k<=n;k++)upmo(a[i][k],-1LL*a[j][k]*t);
				for (int k=1;k<=n;k++)swap(a[i][k],a[j][k]);
				ans*=-1;
			}
		}
		ans=1ll*ans*a[i][i]%mo;
	}
	return (ans+mo)%mo;
}

int work(int st){
	int etot=0;
	cl(id);
	ndtot=0;
	for (int i=1;i<=n+1;i++)
		for (int j=1+(st^(i&1));j<=m+1;j+=2)id[i][j]=++ndtot;
	rep(i,1,ndtot+1)fa[i]=i;

	rep(i,1,n+1)rep(j,1,m+1){
		int a=id[i][j],b=id[i][j+1],c=id[i+1][j],d=id[i+1][j+1];
		if(str[i][j]=='*'){
			if(a && d)e[++etot]=mp(a,d);
			else e[++etot]=mp(b,c);
		}else{
			int ret=1;
			if(a && d && str[i][j]=='\\')ret=un(a,d);
			else if(b && c && str[i][j]=='/')ret=un(b,c);
			if(!ret)return 0;
		}
	}
	maa.clear();
	rep(i,1,ndtot+1)maa[gf(i)];
	int vtot=0;
	foreach(it,maa)it->second=++vtot;
	cl(a);
	rep(i,1,etot+1){
		int u=maa[gf(e[i].fi)];
		int v=maa[gf(e[i].se)];
		a[u][u]++;
		a[v][v]++;
		a[u][v]--;
		a[v][u]--;
	}
	return gauss(vtot-1);
}

int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);gn(mo);
	rep(i,1,n+1)scanf("%s",str[i]+1);

	int ans=(work(0)+work(1))%mo;
	printf("%d\n",ans);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}