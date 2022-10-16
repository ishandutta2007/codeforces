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
    void minimize(X &x, const Y &y) {
        if (x > y) x = y;
    }
template<class X, class Y>
    void maximize(X &x, const Y &y) {
        if (x < y) x = y;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   2020
int a[MAX], n;
int cnt[3][MAX];
int bestRev[MAX][MAX];

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) FOR(j, 1, 2) cnt[j][i] = cnt[j][i - 1] + (a[i] == j);
}

int getCount(int l, int r, int v) {
    return l > r ? 0 : cnt[v][r] - cnt[v][l - 1];
}

void process(void) {
    FOR(l, 1, n) {
        bestRev[l][l] = 1;
        FOR(r, l + 1, n) {
            if (a[r] == 1) bestRev[l][r] = bestRev[l][r - 1] + 1;
            else {
                bestRev[l][r] = bestRev[l][r - 1];
                maximize(bestRev[l][r], getCount(l, r, 2));
            }
        }
    }

    int res = max(cnt[1][n], cnt[2][n]);
    FOR(i, 1, n - 1) maximize(res, getCount(1, i, 1) + getCount(i + 1, n, 2));
    FOR(l, 1, n) FOR(r, l, n) maximize(res, getCount(1, l - 1, 1) + bestRev[l][r] + getCount(r + 1, n, 2));
    printf("%d\n", res);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/