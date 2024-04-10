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

#define SZ 35
struct bi{
	unsigned int a[SZ];
	int count(){
		int an=0;
		rep(i,0,SZ)an+=buli(a[i]);
		return an;
	}
	void set(int x,int g=1){
		unsigned int xx=((unsigned int)1)<<(x&31);
		a[x>>5]&=~xx;
		if(g)a[x>>5]|=xx;
	}
	int get(int x){
		int q=a[x>>5];
		return (q>>(x&31))&1;
	}
	int las(){
		rep(i,0,SZ)if(a[i]){
			return __builtin_ctz(a[i])+i*32;
		}
		return -1;
	}
};
bi operator&(const bi&a,const bi&b){
	bi c;
	rep(i,0,SZ)c.a[i]=a.a[i]&b.a[i];
	return c;
}
int operator==(const bi&a,const bi&b){
	rep(i,0,SZ)if(a.a[i]!=b.a[i])return 0;
	return 1;
}

int n;
bi a[1111];int sz[1111];
int ji[1111][1111];
bi a12[1111],a3[1111];
int bian[1111][1111];


int biaoshi[1111];
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	rep(i,1,n+1){
		int k;
		gn(k);
		while(k--){
			int x;gn(x);
			a[i].set(x,1);
			sz[i]++;
		}
	}

	if(n==2){
		printf("%d %d\n",1,2);
		return 0;
	}

	int bo=1;
	rep(i,1,n+1)if(sz[i]!=n)bo=0;
	if(bo==1){
		rep(i,2,n+1)printf("%d %d\n",1,i);
		return 0;
	}

	int mi=1111;
	rep(i,1,n+1){
		ji[i][i]=sz[i];
		rep(j,i+1,n+1){
			ji[i][j]=ji[j][i]=(a[i]&a[j]).count();
			upmin(mi,ji[i][j]);
		}
	}
	rep(i,1,n+1)
		rep(j,1,n+1)if(j!=i){
			if(ji[i][j]==2)a3[i].set(j);
			else if(ji[i][j]>=3)a12[i].set(j);
		}

	if(mi==2){
		int u,v;
		rep(i,1,n+1)rep(j,i+1,n+1)if(sz[i]!=n && sz[j]!=n && !(a[i]==a[j])){
			bi tmp=a[i]&a[j];
			rep(k,1,n+1)if(tmp.get(k))u=k;
			per(k,1,n+1)if(tmp.get(k))v=k;
		}
		static int bo[1111]={0};

		int x;
		rep(i,1,n+1)if(sz[i]!=n){
			x=i;break;
		}
		rep(i,1,n+1)if(a[x].get(i) && i!=u && i!=v){
			bo[i]=1;
			printf("%d %d\n",i,u);
		}
		printf("%d %d\n",u,v);
		rep(i,1,n+1)if(!bo[i] && i!=u && i!=v){
			printf("%d %d\n",i,v);
		}
		return 0;
	}

	int u,v,w;
	rep(i,1,n+1)rep(j,i+1,n+1)if(ji[i][j]==1){
		u=(a12[i]&a3[j]).las();
		v=(a12[i]&a12[j]).las();
		w=(a3[i]&a12[j]).las();
		bian[i][u]=bian[u][i]=bian[u][v]=bian[v][u]=bian[v][w]=bian[w][v]=bian[w][j]=bian[j][w]=1;
		biaoshi[v]=(a[i]&a[j]).las();
		bi tmp=a[i]&a[w];
		tmp.set(biaoshi[v],0);
		biaoshi[u]=tmp.las();
		tmp=a[j]&a[u];
		tmp.set(biaoshi[v],0);
		biaoshi[w]=tmp.las();
	}
	static bool con[1111]={0};
	rep(i,1,n+1)rep(j,1,n+1)if(bian[i][j])con[i]=con[j]=1;

	rep(i,1,n+1)if(!con[i]){
		bian[v][i]=bian[i][v]=1;
	}	
	static bool biaoshied[1111]={0};
	rep(i,1,n+1)if(biaoshi[i])biaoshied[biaoshi[i]]=1;
	rep(i,1,n+1)if(!biaoshi[i]){
		rep(j,1,n+1)if(a[i].get(j) && !biaoshied[j]){
			biaoshi[i]=j;
			biaoshied[j]=1;
			break;
		}
	}
	rep(i,1,n+1)rep(j,i+1,n+1)if(bian[i][j])printf("%d %d\n",biaoshi[i],biaoshi[j]);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}