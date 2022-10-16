#include<bits/stdc++.h>
#define MAX   155
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
using namespace std;
const int INF=(int)1e9+7;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int n,m,s,a[MAX];
int f[2][MAX][MAX*MAX];
void init(void) {
    scanf("%d%d%d",&n,&m,&s);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void process(void) {
    memset(f,0x3f,sizeof f);
    f[0][0][0]=0;
    REP(i,n) REP(j,min(i,m)+1) if (i-j<=n-m)
        REP(k,n*(n-1)/2+1) if (f[i%2][j][k]<INF) {
            if (j+1<=m) minimize(f[(i+1)%2][j+1][k],f[i%2][j][k]+a[i+1]);
            if (i+1-j<=n-m && k+m-j<=s) minimize(f[(i+1)%2][j][k+m-j],f[i%2][j][k]);
            f[i%2][j][k]=INF;
        }
    int res=INF;
    REP(i,min(s,n*(n-1)/2)+1) minimize(res,f[n%2][m][i]);
    printf("%d\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}