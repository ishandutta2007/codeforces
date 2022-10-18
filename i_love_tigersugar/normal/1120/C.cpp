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

#define MAX   5050

int lcp[MAX][MAX];
int lcpWithPrev[MAX][MAX];
char s[MAX];
int n, addCost, copyCost;
int minCost[MAX];

void init(void) {
    scanf("%d%d%d", &n, &addCost, &copyCost);
    scanf("%s", s + 1);
}

bool ok(int l, int r) {
    int limit = l - 1 - (r - l + 1) + 1;
    if (limit < 1) return false;
    return lcpWithPrev[l][limit] >= r - l + 1;
}

void optimize(void) {
    FORD(i, n, 1) FORD(j, n, 1) lcp[i][j] = s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0;
    FOR(i, 1, n) FOR(j, 1, n - 1) lcpWithPrev[i][j] = max(lcpWithPrev[i][j - 1], lcp[i][j]);

    FOR(i, 1, n) {
        minCost[i] = minCost[i - 1] + addCost;
        FOR(j, 1, i) if (ok(j, i)) minimize(minCost[i], minCost[j - 1] + copyCost);
    }
    cout << minCost[n] << endl;
}

int main(void) {
    init();
    optimize();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/