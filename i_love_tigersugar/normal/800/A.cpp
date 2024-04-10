#include<bits/stdc++.h>
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

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   100100
const double INF = 1e11;

int a[MAX], b[MAX], n, p;

void init(void) {
    scanf("%d%d", &n, &p);
    FOR(i, 1, n) scanf("%d%d", &a[i], &b[i]);
}

bool ok(double t) {
    double sum = 0;
    FOR(i, 1, n) {
        sum += max((t * a[i] - b[i]), 0.0) / p;
        if (sum > t) return false;
    }
    return true;
}

void process(void) {
    long long sum = 0;
    FOR(i, 1, n) sum += a[i];
    if (sum <= p) {
        printf("-1\n");
        return;
    }

    double L = 0;
    double R = INF;

    REP(love, 65) {
        double M = (L + R) / 2;
        if (ok(M)) L = M; else R = M;
    }

    printf("%.11lf\n", (L + R) / 2);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/