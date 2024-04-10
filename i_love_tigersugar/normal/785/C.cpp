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

const long long INF = (long long)2e18 + 7LL;

long long product(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return INF / a <= b ? INF : a * b;
}
bool ok(long long x, long long n, long long m) {
    return product(x - m, x - m + 1) + 2 * m >= 2 * n;
}

long long solve(long long n, long long m) {
    if (m >= n) return n;

    long long L = m + 1;
    long long R = n;

    while (true) {
        if (L == R) return L;
        if (R - L == 1) return ok(L, n, m) ? L : R;
        long long M = (L + R) >> 1;
        if (ok(M, n, m)) R = M; else L = M + 1;
    }
}

int main(void) {
    long long n, m;
    while (cin >> n >> m) cout << solve(n, m) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/