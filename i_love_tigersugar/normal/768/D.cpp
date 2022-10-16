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

#define MAX_DAY   10100
#define MAX_N   1111

const double EPS = 1e-7;

double prob[MAX_DAY][MAX_N];
int n, q;

void prepare(void) {
    scanf("%d%d", &n, &q);
    prob[0][0] = 1.0;

    REP(i, MAX_DAY - 1) REP(j, n + 1) {
        prob[i + 1][j] += prob[i][j] * j / n;
        if (j < n) prob[i + 1][j + 1] += prob[i][j] * (n - j) / n;
    }
}

int solve(int p) {
    REP(i, MAX_DAY) if (prob[i][n] >= 1.0 * (p - EPS) / 2000) return i;
    assert(false);
}

void process(void) {
    REP(love, q) {
        int x; scanf("%d", &x);
        printf("%d\n", solve(x));
    }
}

int main(void) {
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/