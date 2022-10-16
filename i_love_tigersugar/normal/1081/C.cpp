#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
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

#define MAX   2222
const int MOD = 998244353;

int comb[MAX][MAX];

void prepare(void) {
    REP(i, MAX) {
        comb[0][i] = 1;
        comb[i][0] = 0;
    }
    comb[0][0] = 1;

    FOR(i, 1, MAX - 1) FOR(j, 1, MAX - 1) {
        if (i > j) comb[i][j] = 0;
        if (i == j) comb[i][j] = 1;
        if (i < j) comb[i][j] = (comb[i][j - 1] + comb[i - 1][j - 1]) % MOD;
    }
}

int solve(int n, int m, int k) {
    int res = comb[k][n - 1];
    res = 1LL * res * m % MOD;
    REP(love, k) res = 1LL * res * (m - 1) % MOD;
    return res;
}

int main(void) {
    prepare();
    int n, m, k; while (cin >> n >> m >> k) cout << solve(n, m, k) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/