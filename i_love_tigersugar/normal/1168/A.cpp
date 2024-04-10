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

#define MAX   300300
int a[MAX], n, mod;

int value(int x, int step, int last) {
    if (x + step < mod) {
        return last > x + step ? -1 : max(x, last);
    }
    return last <= (x + step) % mod ? last : max(last, x);
}

bool ok(int t) {
    int last = 0;
    FOR(i, 1, n) {
        last = value(a[i], t, last);
        if (last < 0) return false;
    }
    return true;
}

int process(void) {
    scanf("%d%d", &n, &mod);
    FOR(i, 1, n) scanf("%d", &a[i]);

    int L = 0, R = MAX;
    while (true) {
        if (L == R) return L;
        if (R - L == 1) return ok(L) ? L : R;
        int M = (L + R) >> 1;
        if (ok(M)) R = M; else L = M + 1;
    }
}

int main(void) {
    printf("%d\n", process());
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/