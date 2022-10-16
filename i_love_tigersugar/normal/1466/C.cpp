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

#define MAX   100100
const int INF = (int)1e9 + 7;

char a[MAX];
int n;
int f[MAX][2][2];

int process(void) {
    scanf("%s", a + 1);
    n = strlen(a + 1);
    memset(f, 0x3f, (n + 1) * sizeof f[0]);

    if (n == 1) return 0;

    REP(i, 2) REP(j, 2) if (a[1] != a[2] || i || j) f[2][i][j] = i + j;
    FOR(i, 2, n - 1) REP(j, 2) REP(k, 2) if (f[i][j][k] < INF) REP(l, 2) {
        if (!j && !l && a[i + 1] == a[i - 1]) continue;
        if (!k && !l && a[i + 1] == a[i]) continue;
        minimize(f[i + 1][k][l], f[i][j][k] + l);
    }
    int res = INF;
    REP(i, 2) REP(j, 2) if (a[n] != a[n - 1] || i || j) minimize(res, f[n][i][j]);
    return res;
}

int main(void) {
    int t; scanf("%d", &t);
    REP(love, t) printf("%d\n", process());
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/