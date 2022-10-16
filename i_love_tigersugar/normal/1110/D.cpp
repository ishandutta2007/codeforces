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

#define MAX   1000100
const int LIM = 6;
int numCard, numType, cnt[MAX];
int dp[MAX][LIM + 1][LIM + 1];

void init(void) {
    scanf("%d%d", &numCard, &numType);
    REP(love, numCard) {
        int x; scanf("%d", &x); cnt[x]++;
    }

    if (numType == 1) {
        cout << cnt[1] / 3 << endl;
        exit(EXIT_SUCCESS);
    }
    if (numType == 2) {
        cout << cnt[1] / 3 + cnt[2] / 3 << endl;
        exit(EXIT_SUCCESS);
    }
}

void process(void) {
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 0;
    REP(i, numType - 2) REP(j, min(LIM, cnt[i + 1]) + 1) REP(k, min(LIM, cnt[i + 2]) + 1) if (dp[i][j][k] >= 0)
        REP(use, 3) {
            if (use + j > min(LIM, cnt[i + 1])) break;
            if (use + k > min(LIM, cnt[i + 2])) break;
            if (use > min(LIM, cnt[i + 3])) break;
            maximize(dp[i + 1][use + k][use], dp[i][j][k] + use + (cnt[i + 1] - use - j) / 3);
        }

    int res = 0;
    REP(j, min(LIM, cnt[numType - 1]) + 1) REP(k, min(LIM, cnt[numType]) + 1) if (dp[numType - 2][j][k] >= 0)
        maximize(res, dp[numType - 2][j][k] + (cnt[numType - 1] - j) / 3 + (cnt[numType] - k) / 3);
    cout << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/