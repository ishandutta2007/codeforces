#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

long long gcd(long long a, long long b) {
    while (true) {
        if (a == 0) return b;
        if (b == 0) return a;
        if (a > b) a %= b; else b %= a;
    }
}

long long intersect(long long l, long long r, long long u, long long v) {
    long long L = max(l, u);
    long long R = min(r, v);
    return L > R ? 0 : R - L + 1;
}

long long solve(long long la, long long ra, long long ta, long long lb, long long rb, long long tb) {
    long long da = ra - la + 1;
    long long db = rb - lb + 1;
    if (gcd(ta, tb) == 1) return min(da, db);

    long long res = 0;
    long long d = gcd(ta, tb);
    long long a = la % d;
    long long b = lb % d;
    FOR(i, -100, 100) FOR(j, -100, 100) {
        long long A = a + d * i;
        long long B = b + d * j;
        maximize(res, intersect(A, A + da - 1, B, B + db - 1));
    }
    return res;
}

int main(void) {
    long long la, ra, ta, lb, rb, tb;
    while (cin >> la >> ra >> ta >> lb >> rb >> tb) cout << solve(la, ra, ta, lb, rb, tb) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/