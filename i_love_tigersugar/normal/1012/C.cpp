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

#define MAX   5050
const int INF = (int)1e9 + 7;

int n, height[MAX];
int f[MAX][MAX][3];
int res[MAX];

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &height[i]);
}

#define NOTHING   0
#define CHOSEN   1
#define DECREASED   2

int getCost(int cur, int target) {
    return cur < target ? 0 : cur - (target - 1);
}

void optimize(void) {
    memset(f, 0x3f, sizeof f);
    f[1][0][NOTHING] = 0;
    f[1][1][CHOSEN] = 0;

    FOR(i, 1, n - 1) REP(j, i + 1) {
        REP(stt, 3) if (stt != CHOSEN && f[i][j][stt] < INF) {
            minimize(f[i + 1][j][NOTHING], f[i][j][stt]);
            int curHeight = stt == NOTHING ? height[i] : min(height[i], height[i - 1] - 1);
            minimize(f[i + 1][j + 1][CHOSEN], f[i][j][stt] + getCost(curHeight, height[i + 1]));
        }
        if (f[i][j][CHOSEN] < INF)
            minimize(f[i + 1][j][DECREASED], f[i][j][CHOSEN] + getCost(height[i + 1], height[i]));
    }

    memset(res, 0x3f, sizeof res);
    REP(i, n + 1) REP(j, 3) minimize(res[i], f[n][i][j]);
    FORD(i, n - 1, 0) minimize(res[i], res[i + 1]);

    FOR(i, 1, n) if (res[i] < INF) printf("%d ", res[i]); printf("\n");
}

int main(void) {
    init();
    optimize();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/