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

void oneRow(int row, int numCol) {
    for (int i = 1, j = numCol; i <= j; i++, j--) {
        printf("%d %d\n", row, i);
        if (i < j) printf("%d %d\n", row, j);
    }
}

void twoRows(int r, int s, int numCol) {
    if (r > s) swap(r, s);
    if (r == s) return oneRow(r, numCol);
    FOR(i, 1, numCol) {
        printf("%d %d\n", r, i);
        printf("%d %d\n", s, numCol - i + 1);
    }
}

void solve(int m, int n) {
    for (int i = 1, j = m; i <= j; i++, j--) twoRows(i, j, n);
}

int main(void) {
    int m, n; while (cin >> m >> n) solve(m, n);
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/