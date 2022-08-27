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
const int inf=0x3f3f3f3f;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
const int mo=1;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
int n;

vpii fr,to;
vpii ans;
void addans(int u,int v){
	ans.pb(mp(u,v));
}
void output(){
	printf("%d\n",siz(ans));
	rep(i,0,siz(ans))printf("%d %d\n",ans[i].fi,ans[i].se);
}
map<pii,bool>ma;
void work(vi no,vpii fr,vpii to){
	if(siz(no)<=3)return;
	ma.clear();

	rep(i,0,siz(no))ma[mp(no[i],no[(i+1)%siz(no)])]=1;
	rep(i,0,siz(fr))ma[fr[i]]=1;

	int mar[1111];
	int bel[1111];
	rep(i,0,siz(no))mar[no[i]]=i;
	int nee=0,maa=0;
	rep(i,0,siz(to)){
		int u=to[i].fi,v=to[i].se;
		u=mar[u],v=mar[v];
		int di=abs(u-v);
		di=min(di,siz(no)-di);
		if(di>maa){
			maa=di;
			nee=i;
		}
	}


	int u=to[nee].fi,v=to[nee].se;

	for (int i=(mar[u]+1)%siz(no);i!=mar[v];i=(i+1)%siz(no))bel[i]=1;
	for (int i=(mar[v]+1)%siz(no);i!=mar[u];i=(i+1)%siz(no))bel[i]=2;
	bel[mar[u]]=bel[mar[v]]=0;

	vpii ne;
	rep(i,0,siz(fr)){
		int uu=fr[i].fi,vv=fr[i].se;
		if(bel[mar[uu]] && bel[mar[vv]] && bel[mar[uu]]!=bel[mar[vv]]){
			if(bel[mar[uu]]==2)swap(uu,vv);
			int dis1=(mar[uu]-mar[u]+siz(no))%siz(no);
			int dis2=(mar[u]-mar[vv]+siz(no))%siz(no);
			ne.pb(mp(dis1+dis2,i));
		}
	}
	sort(all(ne));

	rep(i,0,siz(ne)){
		int uu=fr[ne[i].se].fi,vv=fr[ne[i].se].se;
		int dd;
		rep(j,0,siz(no))if(no[j]!=u && (ma[mp(no[j],uu)]||ma[mp(uu,no[j])]) && (ma[mp(no[j],vv)]||ma[mp(vv,no[j])]) ){
			dd=no[j];
			break;
		}
		ma[mp(uu,vv)]=0;
		ma[mp(u,dd)]=1;
		addans(uu,vv);
		fr.pb(mp(u,dd));
	}
	vi lefno,rigno;
	vpii leffr,lefto;
	vpii rigfr,rigto;

	rep(i,0,siz(no)){
		if(bel[i]!=1)lefno.pb(no[i]);
		if(bel[i]!=2)rigno.pb(no[i]);
	}
	rep(i,0,siz(to)){
		if(bel[mar[to[i].fi]]==1 || bel[mar[to[i].se]]==1)rigto.pb(to[i]);
		if(bel[mar[to[i].fi]]==2 || bel[mar[to[i].se]]==2)lefto.pb(to[i]);
	}
	rep(i,0,siz(fr)){
		if(ma[mp(fr[i].fi,fr[i].se)] || ma[mp(fr[i].se,fr[i].fi)]){
			if(bel[mar[fr[i].fi]]==1 || bel[mar[fr[i].se]]==1)rigfr.pb(fr[i]);
			if(bel[mar[fr[i].fi]]==2 || bel[mar[fr[i].se]]==2)leffr.pb(fr[i]);
		}
	}

	work(lefno,leffr,lefto);
	work(rigno,rigfr,rigto);
}
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	for (int i=1;i<=n-3;i++){
		int x,y;
		gn(x);gn(y);
		fr.pb(mp(x,y));
	}
	for (int i=1;i<=n-3;i++){
		int x,y;
		gn(x);gn(y);
		to.pb(mp(x,y));
	}
	vi no;
	rep(i,1,n+1)no.pb(i);
	work(no,fr,to);

	output();
	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}