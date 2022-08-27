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

int n;
struct pkt{int x,y;}p[111111],lef[111111],rig[111111];
int ltot=0,rtot=0;
int upr[111111],dor[111111];
int upl[111111],dol[111111];

int cmpx(const pkt&a,const pkt&b){
	return a.x<b.x;
}
bool check(ll m){
	int x=1;
	rep(i,1,rtot+1){
		while(x<ltot && (sqr(rig[i].x-lef[x].x)>m || -lef[x].x>rig[i].x))x++;
		while(x>1 && sqr(rig[i].x-lef[x-1].x)<=m && -lef[x-1].x<=rig[i].x)x--;
		int up=max(upr[i],upl[x]);
		int dow=min(dor[i],dol[x]);

		if(-lef[x].x<=rig[i].x && sqr(rig[i].x-lef[x].x)<=m && sqr(up-dow)<=m && sqr(rig[i].x)+sqr(max(up,-dow))<=m)return 1;
	}
	return 0;
}

ll work(){
	ltot=rtot=0;
	rep(i,1,n+1){
		if(p[i].x>=0)rig[++rtot]=p[i];
		if(p[i].x<=0)lef[++ltot]=p[i];
	}

	sort(rig+1,rig+1+rtot,cmpx);
	sort(lef+1,lef+1+ltot,cmpx);
	cl(upr);
	cl(upl);
	cl(dol);
	cl(dor);

	for (int i=rtot-1;i>=1;i--){
		upr[i]=max(upr[i+1],rig[i+1].y);
		dor[i]=min(dor[i+1],rig[i+1].y);
	}
	for (int i=2;i<=ltot;i++){
		upl[i]=max(upl[i-1],lef[i-1].y);
		dol[i]=min(dol[i-1],lef[i-1].y);
	}
	ll l=0,r=1e18,mid;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	ll an=6e18;
	int lx=1e9,ly=1e9,rx=-1e9,ry=-1e9;
	rep(i,1,n+1){
		gn(p[i].x),gn(p[i].y);
		upmin(lx,p[i].x);
		upmin(ly,p[i].y);
		upmax(rx,p[i].x);
		upmax(ry,p[i].y);
	}
	upmin(an,sqr(lx-rx));
	upmin(an,sqr(ry-ly));

	p[++n]=(pkt){0,0};
	//sort(p+1,p+1+n,cmpx);
	

	upmin(an,work());
	rep(i,1,n+1)p[i].x*=-1;
	upmin(an,work());
	cout<<an<<endl;
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}