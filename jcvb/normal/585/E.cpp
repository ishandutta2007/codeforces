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

#define M 10000000
int n;
int a[555555];
int cnt[M+100];
int se2[M+100];
int mip[M+100],jmp[M+100];
short int mu[M+100];


int p[M/10+10];
bool bo[M+10]={0};
int tot=0;
void sieve(int n){
	mu[1]=1;
    for (int i=2;i<=n;i++){
        if(!bo[i]){
		p[tot++]=i;
		mip[i]=i;
		mu[i]=-1;
		jmp[i]=1;
	}
        for (int j=0;j<tot && i*p[j]<=n;j++){
            bo[i*p[j]]=1;
	    mip[i*p[j]]=p[j];
            if(i%p[j]==0){
		    jmp[i*p[j]]=jmp[i];
		    mu[i*p[j]]=0;
		    break;
	    }else{
		    jmp[i*p[j]]=i;
		    mu[i*p[j]]=-mu[i];
	    }
        }
    }
}
int pi[50];
int tt;
int ptot;
void dfs(int i,int pro,int sg){
	if(i==ptot+1)upmo(tt,cnt[pro]*sg);
	else{
		dfs(i+1,pro*pi[i],-sg);
		dfs(i+1,pro,sg);
	}
}
int gao(int x){
	ptot=0;
	while(x>1){
		pi[++ptot]=mip[x];
		x=jmp[x];
	}
	tt=0;
	dfs(1,1,1);
	return tt;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	sieve(M);
	gn(n);
	rep(i,1,n+1)gn(a[i]),cnt[a[i]]++;

	se2[0]=0;
	rep(i,1,M+1){
		se2[i]=(2*se2[i-1]+1)%mo;
	}
	rep(i,1,M+1)
		for (int j=i+i;j<=M;j+=i)cnt[i]+=cnt[j];
	rep(i,1,M+1)cnt[i]=se2[cnt[i]];

	int x1=0;
	rep(i,1,M+1)upmo(x1,mu[i]*cnt[i]);
	int ans=0;
	for (int i=1;i<=n;i++){
		upmo(ans,gao(a[i])-x1);
	}
	printf("%d\n",ans);
	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}