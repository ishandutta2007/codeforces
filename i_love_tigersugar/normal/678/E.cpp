#include<bits/stdc++.h>
#define MAX   19
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
double prob[MAX][MAX];
double f[MAX][MASK(MAX)+7];
int n;
void init(void) {
    scanf("%d",&n);
    REP(i,n) REP(j,n) scanf("%lf",&prob[i][j]);
}
void process(void) {
    REP(mask,MASK(n)) REP(cur,n) if (!BIT(mask,cur)) {
        if (mask==0) {
            f[cur][mask]=cur==0?1.0:0.0;
            continue;
        }
        f[cur][mask]=-1.0;
        REP(next,n) if (BIT(mask,next)) {
            double tmp=prob[cur][next]*f[cur][mask^MASK(next)]
                +prob[next][cur]*f[next][mask^MASK(next)];
            maximize(f[cur][mask],tmp);
        }
    }
    double res=-1.0;
    REP(i,n) maximize(res,f[i][(MASK(n)-1)^MASK(i)]);
    printf("%.9lf\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}