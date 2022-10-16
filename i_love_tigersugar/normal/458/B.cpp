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

const long long INF = (long long)1e18 + 7LL;
long long product(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return INF / a < b ? INF : a * b;
}

#define MAX   300300
int a[MAX], b[MAX], m, n;
long long sumA[MAX], sumB[MAX];

void init(void) {
    scanf("%d%d", &m, &n);
    FOR(i, 1, m) scanf("%d", &a[i]);
    FOR(j, 1, n) scanf("%d", &b[j]);
    sort(a + 1, a + m + 1);
    sort(b + 1, b + n + 1);
    FOR(i, 1, m) sumA[i] = sumA[i - 1] + a[i];
    FOR(j, 1, n) sumB[j] = sumB[j - 1] + b[j];
}

void process(void) {
    bool bestA = false;
    int bestIndex = -1;
    long long res = INF;

    FOR(i, 1, m) if (minimize(res, product(sumB[n], i) + sumA[m - i])) {
        bestA = true; bestIndex = i;
    }
    FOR(j, 1, n) if (minimize(res, product(sumA[m], j) + sumB[n - j])) {
        bestA = false; bestIndex = j;
    }
    cout << res << endl;

    assert(bestIndex > 0);
    fprintf(stderr, "Best at %c, index = %d\n", bestA ? 'A' : 'B', bestIndex);
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("copy.inp", "r", stdin);
    freopen("copy.out", "w", stdout);
#endif // ONLINE_JUDGE

    init();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/