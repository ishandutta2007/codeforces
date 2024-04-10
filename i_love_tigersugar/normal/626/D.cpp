#include<bits/stdc++.h>
#define MAX   2020
#define MAXV   5050
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
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int a[MAX],n;
double cnt[2*MAXV+7],cntLess[2*MAXV+7];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) FOR(j,1,n) if (i!=j) cnt[a[i]-a[j]+MAXV]+=1.0;
    FOR(i,-MAXV,MAXV) {
        cnt[i+MAXV]/=n;
        cnt[i+MAXV]/=n-1;
    }
    FOR(i,-MAXV+1,MAXV) cntLess[i+MAXV]=cntLess[i-1+MAXV]+cnt[i-1+MAXV];
}
void process(void) {
    double numPair=0;
    double probPos=1.0-cntLess[1+MAXV];
    double probNeg=cntLess[MAXV];
    FOR(i,1,MAXV) FOR(j,1,MAXV) {
        int req=-i-j;
        if (req>MAXV) numPair+=1.0*cnt[i+MAXV]*cnt[j+MAXV];
        else if (req>-MAXV) numPair+=1.0*cnt[i+MAXV]*cnt[j+MAXV]*cntLess[-i-j+MAXV];
    }
    printf("%.9lf\n",numPair/probPos/probPos/probNeg);
}
int main(void) {
    init();
    process();
    return 0;
}