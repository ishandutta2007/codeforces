#include<bits/stdc++.h>
#define MAX   2207
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define isNAN(x) (std::isnan(x))
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const int INF=(int)1e9+7;
int n,h,x[MAX],left[MAX],right[MAX];
double p,f[MAX][MAX][2][2];
void init(void) {
    scanf("%d%d%lf",&n,&h,&p);
    FOR(i,1,n) scanf("%d",&x[i]);
    sort(x+1,x+n+1);
    x[0]=-INF;x[n+1]=INF;
    left[0]=0;
    right[n+1]=n+1;
    FOR(i,1,n) left[i]=x[i]>=x[i-1]+h?i:left[i-1];
    FORD(i,n,1) right[i]=x[i]+h<=x[i+1]?i:right[i+1];
}
double expVal(int l,int r,bool sl,bool sr) {
    if (l>r) return (0);
    if (!isNAN(f[l][r][sl][sr])) return (f[l][r][sl][sr]);
    double &res=f[l][r][sl][sr];
    int L=sl?x[l-1]+h:x[l-1];
    int R=sr?x[r+1]-h:x[r+1];
    res=0;
    res+=0.5*p*(expVal(l+1,r,false,sr)+min(x[l]-L,h));
    res+=0.5*(1-p)*(expVal(l,r-1,sl,false)+min(R-x[r],h));
    int t=min(right[l],r);
    res+=0.5*(1-p)*(expVal(t+1,r,true,sr)+min(x[t]+h,R)-x[l]);
    t=max(left[r],l);
    res+=0.5*p*(expVal(l,t-1,sl,true)+x[r]-max(x[t]-h,L));
    return (res);
}
void process(void) {
    memset(f,-1,sizeof f);
    printf("%.9lf\n",expVal(1,n,false,false));
}
int main(void) {
    init();
    process();
    return 0;
}