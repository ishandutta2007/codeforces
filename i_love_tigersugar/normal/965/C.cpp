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

const long long INF = (long long)1e18 + 7LL;

long long product(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return INF / a < b ? INF : a * b;
}

long long floor(long long a, long long b) {
    assert(b > 0);
    return a / b;
}
long long ceil(long long a, long long b) {
    assert(b > 0);
    return a / b + (a % b > 0);
}

long long equalTurn(long long n, long long k, long long m, int p) {
    long long R = min(floor(n, product(p, k)), m);
    long long L = ceil(n + 1, product(p, k) + 1);
    return L <= R ? R : -1;
}

long long extraTurn(long long n, long long k, long long m, int p) {
    long long R = min(floor(n, product(p, k) + 1), m);
    long long L = ceil(n + 1, product(p + 1, k));
    return L <= R ? R : -1;
}

long long solve(long long n, long long k, long long m, int d) {
    long long res = 0;
    FOR(p, 1, d) maximize(res, equalTurn(n, k, m, p) * p);
    REP(p, d) maximize(res, extraTurn(n, k, m, p) * (p + 1));
    return res;
}

int main(void) {
    long long n, k, m; int d;
    while (cin >> n >> k >> m >> d)
        cout << solve(n, k, m, d) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/