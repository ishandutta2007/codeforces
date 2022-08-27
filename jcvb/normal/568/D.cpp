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
const int inf=0x3f3f3f3f;
const db eps=1e-12;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

int n,k;
struct lin{
	int a,b,c,id;
	void rd(){
		gn(a);gn(b);gn(c);
	}
}l[111111],tmp[111111];
struct pkt{
	db x,y;
	int i,j;
}pp[222222];
int operator<(const pkt&a,const pkt&b){
	if(fabs(a.x-b.x)<eps)return a.y+eps<b.y;
	return a.x+eps<b.x;
}
bool inter(lin p,lin q){
	return 1ll*p.a*q.b-1ll*q.a*p.b!=0;
}
pkt get(lin p,lin q){
	pkt a;
	a.x=db(1ll*p.c*q.b-1ll*p.b*q.c)/(1ll*p.a*q.b-1ll*q.a*p.b);
	a.y=db(1ll*p.a*q.c-1ll*p.c*q.a)/(1ll*p.a*q.b-1ll*q.a*p.b);
	return a;
}
bool inter(lin p,lin q,lin r){
	return inter(p,q) && (1ll*p.c*q.b-1ll*p.b*q.c)*r.a
		            +(1ll*p.a*q.c-1ll*p.c*q.a)*r.b
			    ==(1ll*p.a*q.b-1ll*p.b*q.a)*r.c;
}


vpii ans;
int work(int n,int k){
	if(n==0)return 1;
	if(k==0)return n==0;
	if(n>k*k){
		rep(_,0,40){
			int id=rand()%n+1;
			int ptot=0;
			rep(i,1,n+1)if(inter(l[i],l[id])){
				pp[++ptot]=get(l[i],l[id]);
				pp[ptot].i=i,pp[ptot].j=id;
			}
			sort(pp+1,pp+1+ptot);

			for (int i=1,j;i<=ptot;i=j){
				for(j=i;j<=ptot && !(pp[i]<pp[j]);j++);
				int de=j-i;
				if(de+1>k){
					ans.pb(mp(l[pp[i].i].id,l[pp[i].j].id));
					int tmptot=0;
					for (int t=1;t<=n;t++){
						if(t!=pp[i].j && t!=pp[i].i && !inter(l[pp[i].j],l[pp[i].i],l[t]))tmp[++tmptot]=l[t];
					}
					for (int t=1;t<=tmptot;t++)l[t]=tmp[t];
					int gg=work(tmptot,k-1);
					if(gg==1)return 1;
					else return 0;
				}
			}
		}
		return 0;
	}else{
		lin sto[33];
		rep(i,1,n+1)sto[i]=l[i];

		for (int i=1;i<=n;i++)for (int j=i;j<=n;j++)if(i==j || inter(l[i],l[j])){
			int deg=(i==j)?1:2;

			if(i!=j)for (int t=1;t<=n;t++)if(t!=i && t!=j && inter(l[i],l[j],l[t]))deg++;

			if(deg*k>=n){
				int tmptot=0;
				ans.pb(mp(l[i].id,l[j].id));
				if(i==j){
					for (int t=1;t<=n;t++)if(t!=i)tmp[++tmptot]=l[t];
				}else{
					for (int t=1;t<=n;t++)if(t!=i && t!=j && !inter(l[i],l[j],l[t]))tmp[++tmptot]=l[t];
				}
				rep(t,1,tmptot+1)l[t]=tmp[t];
				int gg=work(tmptot,k-1);
				if(gg==1)return 1;
				ans.pop_back();
				rep(t,1,n+1)l[t]=sto[t];
			}
		}
		return 0;
	}
}
int main()
{
	srand(2333);
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(k);
	rep(i,1,n+1)l[i].rd(),l[i].id=i;
	int g=work(n,k);
	if(!g)printf("NO\n");
	else {
		printf("YES\n");
		printf("%d\n",siz(ans));
		rep(i,0,siz(ans)){
			if(ans[i].fi==ans[i].se)printf("%d -1\n",ans[i].fi);
			else printf("%d %d\n",ans[i].fi,ans[i].se);
		}
	}
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}