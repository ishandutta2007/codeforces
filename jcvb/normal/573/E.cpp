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
typedef long double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
const ll inf=4e18;
const db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

int n;
int a[111111];
int off[111111];
ll k[111111],b[111111];
ll dek[555],deb[555];
int li[555],ri[555];

int lis[555][555];

bool posi(ll a,ll b,ll c,ll d){
	if(fabs(db(a)*c-db(b)*d)>1e18)return db(a)*c-db(b)*d>0;
	return a*c-b*d>0;
}
#define val(x) ((k[x]+dek[ii])*a[x]+b[x]+deb[ii])
struct queu{
	int qu[555];
	int p,q;
	int ii;

	void ini(){
		p=q=0;
	}
	void pb(int ne){
		while(p!=q && val(ne)>=val(qu[q-1]))q--;
		if(p!=q && a[qu[q-1]]==a[ne])return;
		while(q-p>=2 && posi(a[qu[q-1]]-a[qu[q-2]],val(qu[q-1])-val(qu[q-2]),a[ne]-a[qu[q-1]],val(ne)-val(qu[q-1])))q--;
		qu[q++]=ne;
	}
	void mov(){
		while(q-p>1 && val(qu[p])<val(qu[p+1]))p++;
	}
}qu[555];
int id[111111];int maid;
int sz=333;

void chushi(int ii){
	rep(j,li[ii],ri[ii]+1)k[j]+=dek[ii],b[j]+=deb[ii];
	dek[ii]=deb[ii]=0;
}

void build(int ii){
	chushi(ii);
	qu[ii].ini();
	rep(j,1,ri[ii]-li[ii]+2)if(!off[lis[ii][j]])qu[ii].pb(lis[ii][j]);
}
void na(int i){
	off[i]=1;
	int ii=id[i];
	chushi(ii);
	rep(j,i+1,ri[ii]+1)k[j]++;
	rep(j,li[ii],i)b[j]+=a[i];
	build(ii);
	rep(j,1,ii)deb[j]+=a[i];
	rep(j,ii+1,maid+1){
		dek[j]++;
		qu[j].mov();
	}
}
int cmp(int i,int j){
	return a[i]<a[j];
}
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	rep(i,1,n+1)gn(a[i]),k[i]=1;
	
	for (int i=1,ii=1;i<=n;i+=sz,ii++){
		li[ii]=i;
		ri[ii]=min(n,i+sz-1);
		rep(j,li[ii],ri[ii]+1)id[j]=ii;
		qu[ii].ii=ii;
	}
	maid=id[n];
	
	rep(i,1,maid+1){
		int to=0;
		rep(j,li[i],ri[i]+1)lis[i][++to]=j;
		sort(lis[i]+1,lis[i]+1+to,cmp);
	}

	rep(i,1,maid+1)build(i);

	ll cur=0,ma=0;

	rep(i,1,n+1){
		int ij;ll del=-inf;
		rep(ii,1,maid+1)if(qu[ii].p!=qu[ii].q){
			ll dd=val(qu[ii].qu[qu[ii].p]);
			if(dd>del){
				del=dd;
				ij=qu[ii].qu[qu[ii].p];
			}
		}
		debug("%d %lld\n",ij,del);
		cur+=del;
		upmax(ma,cur);
		na(ij);
	}
	
	cout<<ma<<endl;


	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}