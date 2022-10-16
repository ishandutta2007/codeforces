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

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

#define MAX   500500
#define NUM_BIT   61
const int MOD = (int)1e9 + 7;

long long a[MAX];
int n;
int cntBit[NUM_BIT];

void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void process(void) {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    memset(cntBit, 0, sizeof cntBit);
    FOR(i, 1, n) REP(j, NUM_BIT) if (BIT(a[i], j)) cntBit[j]++;

    int res = 0;
    FOR(i, 1, n) {
        int sumAnd = 0, sumOr = 0;
        REP(j, NUM_BIT) if (BIT(a[i], j)) add(sumAnd, MASK(j) % MOD * cntBit[j] % MOD);
        REP(j, NUM_BIT) add(sumOr, MASK(j) % MOD * (BIT(a[i], j) ? n : cntBit[j]) % MOD);
        add(res, 1LL * sumAnd * sumOr % MOD);
    }
    printf("%d\n", res);
}

int main(void) {
    ios::sync_with_stdio(false);

    int t; cin >> t;
    FOR(i, 1, t) process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/