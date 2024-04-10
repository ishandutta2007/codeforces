#include<bits/stdc++.h>
using namespace std;
namespace io{
    const int l=1<<20;
    char buf[l],*s,*t,c;
    inline void gc(){
        if(s==t){
            t=(s=buf)+fread(buf,1,l,stdin);
            c=s==t?EOF:*s++;
        }else c=*s++;
    }
    template<class IT>inline void gi(IT &x){
        x=0;gc();while(c<'0'||c>'9')gc();
        while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);gc();}
    }
    char buf0[20];int a;
    template<class IT>inline void pi(IT x){
        if(x<0){putchar('-');x=-x;}
        do buf0[++a]=x%10+48;while(x/=10);
        while(a)putchar(buf0[a--]);
        putchar('\n');
    }
};
using io::gi;
using io::pi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,ll > pil;
typedef pair<ll ,int> pli;
typedef pair<ll ,ll > pll;
#define pque priority_queue
#define rep(i,l,r) for(i=(l);i<=(r);++i)
#define per(i,l,r) for(i=(l);i>=(r);--i)
#define REP(i,l,r) for(i=(l);i< (r);++i)
#define PER(i,l,r) for(i=(l);i> (r);--i)
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define fi first
#define se second
template<class IT>inline void cmax(IT &a,IT b){if(a<b)a=b;}
template<class IT>inline void cmin(IT &a,IT b){if(b<a)a=b;}
const ll inf=1000000000000000ll;
const int N=5005;
pair<pll,pll>a[N];
ll d[N],p[N];
int x[N];
int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n,s,e,i,j,b;ll t;pair<pll,pll>A;
    scanf("%d%d%d",&n,&s,&e);
    rep(i,1,n) scanf("%d",&x[i]);
	rep(i,1,n){scanf("%d",&b);a[i].fi.fi=b+x[i];}
	rep(i,1,n){scanf("%d",&b);a[i].fi.se=b-x[i];}
	rep(i,1,n){scanf("%d",&b);a[i].se.fi=b+x[i];}
	rep(i,1,n){scanf("%d",&b);a[i].se.se=b-x[i];}
	rep(i,1,n)d[i]=inf;b=0;
	rep(j,1,n){
		rep(i,0,n)p[i]=inf;
		A=a[j];
		//printf("a=%d b=%d c=%d d=%d\n",A.fi.fi,A.fi.se,A.se.fi,A.se.se);
		if(j==s){
			if(b){
				t=A.se.fi;rep(i,0,n)cmin(p[i  ],d[i]+t);
				t=A.se.se;rep(i,0,n)cmin(p[i+1],d[i]+t);
				b=0;
			}else{
				t=A.se.fi;rep(i,1,n)cmin(p[i-1],d[i]+t);
				t=A.se.se;rep(i,0,n)cmin(p[i  ],d[i]+t);
				b=2;
			}
		}else if(j==e){
			if(b){
				t=A.fi.fi;rep(i,0,n)cmin(p[i  ],d[i]+t);
				t=A.fi.se;rep(i,0,n)cmin(p[i+1],d[i]+t);
				b=0;
			}else{
				t=A.fi.fi;rep(i,1,n)cmin(p[i-1],d[i]+t);
				t=A.fi.se;rep(i,0,n)cmin(p[i  ],d[i]+t);
				b=1;
			}
		}else{
			t=A.fi.fi+A.se.fi;rep(i,   1,n)cmin(p[i-1],d[i]+t);
			t=A.fi.se+A.se.se;rep(i,   0,n)cmin(p[i+1],d[i]+t);
			t=A.fi.fi+A.se.se;rep(i,b!=2,n)cmin(p[i  ],d[i]+t);
			t=A.fi.se+A.se.fi;rep(i,b!=1,n)cmin(p[i  ],d[i]+t);
		}
		if(!b&&j!=n)p[0]=inf;
		rep(i,0,n)d[i]=p[i];
		//rep(i,0,n)printf("%lld ",d[i]);printf("b=%d\n",b);
	}
	printf("%lld",d[0]);
    return 0;
}