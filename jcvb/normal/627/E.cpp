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

int r,c,n,k;
struct pkt{
	int x,y;
}p[3333];
int cmp(const pkt&a,const pkt&b){
	return a.y<b.y;
}
int lef[3333],rig[3333];
int cnt[3333];
int far[3333],cuu[3333];
ll su;

inline ll calc(int l1,int l2,int r1){
	return 1ll*(l2-l1)*(r+1-r1);
}
void ini(){
	su=0;
	rep(i,0,r+1)lef[i]=rig[i]=0;
	int las=0;
	cnt[r+1]=k;
	rep(i,1,r+2)if(cnt[i]){
		lef[i]=las;
		rig[las]=i;
		las=i;
	}

	int cu=0;
	int le=rig[0],ri=rig[0];
	cu=cnt[le];

	while(le!=r+1){
		while(cu<k){
			ri=rig[ri];
			cu+=cnt[ri];
		}
		cuu[le]=cu;
		far[le]=ri;
		su+=calc(lef[le],le,far[le]);
		cu-=cnt[le];
		le=rig[le];
	}
}
void rem(int i){
	cnt[i]--;

	int u=i;
	while(u && far[u]>=i){
		su-=calc(lef[u],u,far[u]);
		cuu[u]--;
		while(cuu[u]<k){
			far[u]=rig[far[u]];
			cuu[u]+=cnt[far[u]];
		}
		su+=calc(lef[u],u,far[u]);

		u=lef[u];
	}

	if(cnt[i]==0){
		rig[lef[i]]=rig[i];
		lef[rig[i]]=lef[i];
	}
}
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(r);gn(c);gn(n);gn(k);
	rep(i,1,n+1)gn(p[i].x),gn(p[i].y);
	sort(p+1,p+1+n,cmp);

	ll ans=0;

	rep(le,1,c+1){
		rep(i,1,r+1)cnt[i]=0;
		rep(i,1,n+1)if(p[i].y>=le)cnt[p[i].x]++;
		ini();
		int cur=n;
		per(ri,le,c+1){
			ans+=su;
			while(cur>=1 && p[cur].y==ri){
				rem(p[cur].x);
				cur--;
			}
		}
	}
	cout<<ans<<endl;
	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}