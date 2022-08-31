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
typedef long double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
int inf=0x3f3f3f3f;
db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
int n,m;
db ox,oy;
db ai[55555],bi[55555];

struct node{
	int id;
	db t;
}a[111111];int tot;
int cmp(const node&a,const node&b){
	return a.t<b.t;
}
int bit[111111];
void bitupd(int x,int del){
	for(;x<=tot;x+=x&-x)bit[x]+=del;
}
int bitque(int x){
	int ans=0;for(;x;x-=x&-x)ans+=bit[x];return ans;
}
int pre[51111],cnt[111111];

void build(db r){
	tot=0;
	rep(i,1,n+1){
		db del=sqrf(2*ai[i]*bi[i])-4*(1+ai[i]*ai[i])*(bi[i]*bi[i]-r*r);
		if(del<=0)continue;
		del=sqrt(del);
		db x1=(-2*ai[i]*bi[i]+del)/2/(1+ai[i]*ai[i]);
		db x2=(-2*ai[i]*bi[i]-del)/2/(1+ai[i]*ai[i]);
		db y1=ai[i]*x1+bi[i];
		db y2=ai[i]*x2+bi[i];
		a[++tot]=(node){i,atan2(y1,x1)};
		a[++tot]=(node){i,atan2(y2,x2)};
	}
	cl(bit);
	sort(a+1,a+1+tot,cmp);
}

ll getnum(db r){
	build(r);
	ll ans=0;
	rep(i,1,tot+1){
		if(!pre[a[i].id])pre[a[i].id]=i,cnt[i]=cnt[i-1];
		else{
			ans+=bitque(pre[a[i].id]);
			bitupd(pre[a[i].id],1);
			cnt[i]=cnt[i-1]+1;
		}
	}
	per(i,1,tot+1){
		if(pre[a[i].id])pre[a[i].id]=0;
		else{
			ans-=cnt[i-1];
		}
	}
	return ans;
}
int lef[111111],rig[111111];
int len[111111];
int li[111111],ri[111111];
int ord[111111];
int cmpt(int i,int j){
	return len[i]<len[j];
}
db suan(int i,int j){
	db x=(bi[j]-bi[i])/(ai[i]-ai[j]);
	db y=ai[i]*x+bi[i];
	return sqrt(sqrf(x)+sqrf(y));
}
db calc(db r){
	build(r);
	int tt=0;
	rep(i,1,tot+1){
		if(!li[a[i].id])li[a[i].id]=i,ord[++tt]=a[i].id;
		else ri[a[i].id]=i,len[a[i].id]=ri[a[i].id]-li[a[i].id];
	}
	int las=0;
	rep(i,1,tot+1){
		int cu;
		if(i==ri[a[i].id])cu=a[i].id+n;
		else cu=a[i].id;
		rig[las]=cu;
		lef[cu]=las;
		las=cu;
	}
	db ret=0;
	sort(ord+1,ord+1+tt,cmpt);
	int nu=0;
	rep(j,1,tt+1){
		int i=ord[j];
		int u=rig[i];
		while(u!=i+n){
			ret+=suan(i,u>n?u-n:u);
			nu++;
			u=rig[u];
		}
		lef[rig[i]]=lef[i];
		rig[lef[i]]=rig[i];

		lef[rig[i+n]]=lef[i+n];
		rig[lef[i+n]]=rig[i+n];
	}
	ret+=(m-nu)*r;
	return ret;
}
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	gn(ox);gn(oy);gn(m);
	ox/=1000,oy/=1000;
	rep(i,1,n+1){
		gn(ai[i]);gn(bi[i]);
		ai[i]/=1000;
		bi[i]/=1000;
		bi[i]=ai[i]*ox+bi[i]-oy;
	}

	db l=0.0,r=1e20,mid;
	rep(_,0,200){
		mid=(l+r)*0.5;
		ll nu=getnum(mid);
		if(nu>=m)r=mid;
		else l=mid;
	}

	db ans=calc(l);
	printf("%.10lf\n",double(ans));

	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}