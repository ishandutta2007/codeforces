#include<bits/stdc++.h>
#define MAX   100100
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
double probMax[MAX],probMin[MAX],sumMax[MAX],sumMin[MAX];
int n;
double probA[MAX],probB[MAX];
void solve(double product,double sum,double &x,double &y) {
    double delta=max(sum*sum-4*product,0.0);
    x=(sum+sqrt(delta))/2;
    y=(sum-sqrt(delta))/2;
}
void process(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%lf",&probMax[i]);
    FOR(i,1,n) scanf("%lf",&probMin[i]);
    FOR(i,1,n) sumMax[i]=sumMax[i-1]+probMax[i];
    FORD(i,n,1) sumMin[i]=sumMin[i+1]+probMin[i];
    FOR(i,1,n) solve(sumMax[i],1+sumMax[i]-sumMin[i+1],probA[i],probB[i]);
    FOR(i,1,n) printf("%.9lf ",probA[i]-probA[i-1]); printf("\n");
    FOR(i,1,n) printf("%.9lf ",probB[i]-probB[i-1]); printf("\n");
}
int main(void) {
    process();
    return 0;
}