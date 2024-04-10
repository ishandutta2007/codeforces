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
struct fen{
	pii p[66];
	int tot;
	void zuo(int a){
		tot=0;
		for (int i=2;i*i<=a;i++)if(a%i==0){
			p[++tot]=mp(i,0);
			while(a%i==0){
				p[tot].se++;a/=i;
			}
		}
		if(a>1){
			p[++tot]=mp(a,1);
		}
	}
	void add(int x){
		rep(i,1,tot+1)if(p[i].fi==x)return;
		p[++tot]=mp(x,0);
		sort(p+1,p+1+tot);
	}

};
bool pok(const fen&a,const fen&b){
	if(a.tot!=b.tot)return 0;
	rep(i,1,a.tot+1)if(a.p[i].fi!=b.p[i].fi)return 0;
	return 1;
}
struct node{
	int a,b;
	bool in(int x){
		if(b==1){
			return a==x;
		}
		ll u=a;
		while(u<=x){
			if(u==x)return 1;
			u*=b;
		}
		return 0;
	}
	fen pa,pb;
	void chuli(){
		rep(i,1,pb.tot+1)pa.add(pb.p[i].fi);
		rep(i,1,pa.tot+1)pb.add(pa.p[i].fi);
	}
}p[111];
int n;
int k;
struct ne{
	ll a[33],d[33];
}a[111];

ne jiao(ne u,ne v,int &ver){
	ver=1;
	ll a=0,b=0,c=0;
	int bo=0;

	rep(i,1,k+1){
		ll C=v.a[i]-u.a[i];
		ll A=u.d[i],B=-v.d[i];
		if(A==0 && B==0){
			if(C!=0){
				ver=0;
				return u;
			}else{
				continue;
			}
		}
		ll D=gcd(A,B);
		if(C%D!=0){
			ver=0;
			return u;
		}
		A/=D,B/=D,C/=D;
		if(A<0){
			A*=-1,B*=-1,C*=-1;
		}
		if(A==0 && B>0){
			B*=-1,C*=-1;
		}
		if(!bo){
			a=A,b=B;c=C;
			bo=1;
		}else{
			if(a==A && b==B){
				if(c!=C){
					ver=0;
					return u;
				}else{
					continue;
				}
			}else{
				//??
				ll det=a*B-b*A;
				ll dx=c*B-b*C,dy=a*C-c*A;
				if(dx%det!=0 || dy%det!=0){
					ver=0;
					return u;
				}
				ll x=dx/det,y=dy/det;
				rep(j,1,k+1){
					if(u.a[j]+x*u.d[j]!=v.a[j]+y*v.d[j]){
						ver=0;
						return u;
					}
				}
				ne ans;
				rep(j,1,k+1)ans.a[j]=u.a[j]+x*u.d[j],ans.d[j]=0;
				return ans;
			}
		}
	}
	if(bo==0)return u;

	if(a==0){
		ll y=c/b;
		if(y<0){
			ver=0;
			return u;
		}
		ne ans;
		rep(j,1,k+1)ans.a[j]=v.a[j]+y*v.d[j],ans.d[j]=0;
		return ans;
	}
	if(b==0){
		ll x=c/a;
		if(x<0){
			ver=0;
			return u;
		}
		ne ans;
		rep(j,1,k+1)ans.a[j]=u.a[j]+x*u.d[j],ans.d[j]=0;
		return ans;
	}
	ll x,y;
	for (x=0;;x++){
		if((c-a*x)%b==0){
			y=(c-a*x)/b;
			break;
		}
	}
	if(y<0){
		ll ned=cei(-y,a);
		y+=ned*a;
		x-=ned*b;
	}
	ne ans;
	rep(j,1,k+1)ans.a[j]=u.a[j]+x*u.d[j],ans.d[j]=-b*u.d[j];
	return ans;
}

int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	rep(i,1,n+1)gn(p[i].a),gn(p[i].b);
	rep(i,1,n+1)if(p[i].b==1){
		int bo=1;
		rep(j,1,n+1)bo&=p[j].in(p[i].a);
		if(bo)printf("%d\n",p[i].a);
		else printf("-1\n");
		return 0;
	}

	rep(i,1,n+1){
		int bo=1;
		rep(j,1,n+1)bo&=p[j].in(p[i].a);
		if(bo){
			printf("%d\n",p[i].a);
			return 0;
		}
	}
	rep(i,1,n+1){
		p[i].pa.zuo(p[i].a);
		p[i].pb.zuo(p[i].b);
		p[i].chuli();
	}
	int bo=1;
	rep(i,1,n+1){
		if(!pok(p[i].pa,p[1].pa))bo=0;
	}
	if(!bo){
		printf("-1\n");return 0;
	}
	::k=p[1].pa.tot;

	rep(i,1,n+1){
		rep(j,1,k+1){
			a[i].a[j]=p[i].pa.p[j].se;
			a[i].d[j]=p[i].pb.p[j].se;
		}
	}

	ne cur=a[1];

	rep(i,2,n+1){
		int ver;
		ne ne=jiao(cur,a[i],ver);
		if(ver==0){
			printf("-1\n");return 0;
		}
		cur=ne;
	}
	int ans=1;
	rep(i,1,k+1)ans=1ll*ans*qp(p[1].pa.p[i].fi,cur.a[i])%mo;
	printf("%d\n",ans);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}