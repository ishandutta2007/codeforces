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

#define MAX   100100

int n, range;
int a[MAX], t[MAX], sumReal[MAX], sumBest[MAX];

void init(void) {
    scanf("%d%d", &n, &range);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) scanf("%d", &t[i]);
}

int getSum(int sum[], int l, int r) {
    return l > r ? 0 : sum[r] - sum[l - 1];
}

void process(void) {
    FOR(i, 1, n) sumBest[i] = sumBest[i - 1] + a[i];
    FOR(i, 1, n) sumReal[i] = sumReal[i - 1] + a[i] * t[i];

    int res = 0;
    FOR(i, 1, n - range + 1) {
        int L = i, R = i + range - 1;
        int tmp = getSum(sumReal, 1, L - 1) + getSum(sumBest, L, R) + getSum(sumReal, R + 1, n);
        maximize(res, tmp);
    }

    cout << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/