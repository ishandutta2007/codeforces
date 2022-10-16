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

#define MAX   1000111
const int MOD = 998244353;

int inverse(int x) {
    int res = 1, mul = x, k = MOD - 2;
    while (k > 0) {
        if (k & 1) res = 1LL * res * mul % MOD;
        mul = 1LL * mul * mul % MOD;
        k >>= 1;
    }
    return res;
}

int frac[MAX], finv[MAX];

void prepare(void) {
    frac[0] = finv[0] = 1;
    FOR(i, 1, MAX - 1) {
        frac[i] = 1LL * frac[i - 1] * i % MOD;
        finv[i] = inverse(frac[i]);
        assert(1LL * frac[i] * finv[i] % MOD == 1);
    }
}

int cnt[MAX];
int solve(int n) {
    memset(cnt, 0, sizeof cnt);
    int res = 0;
    FOR(k, 1, n) cnt[k] = 1LL * frac[n] * finv[k] % MOD;
    FOR(k, 1, n - 1) {
        int numPerm = (cnt[k] - cnt[k + 1] + MOD) % MOD;
//        printf("for k = %d have %d perms\n", k, numPerm);
        int lcp = n - k - 1;
        res = (res + 1LL * numPerm * lcp) % MOD;
    }
    return (res + frac[n]) % MOD;
}

int main(void) {
    prepare();
    int n; while (cin >> n) cout << solve(n) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/