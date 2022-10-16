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
int numValue, numSmall, numLarge, dist, threshold;
int small[MAX], large[MAX];
long long sumSmall[MAX], sumLarge[MAX];

void init(void) {
    scanf("%d%d%d", &numValue, &dist, &threshold);
    REP(love, numValue) {
        int x; scanf("%d", &x);
        if (x > threshold) large[++numLarge] = x; else small[++numSmall] = x;
    }
    sort(large + 1, large + numLarge + 1, greater<int>());
    sort(small + 1, small + numSmall + 1, greater<int>());
    FOR(i, 1, numLarge) sumLarge[i] = sumLarge[i - 1] + large[i];
    FOR(i, 1, numSmall) sumSmall[i] = sumSmall[i - 1] + small[i];
}

void process(void) {
    if (numLarge == 0) {
        cout << sumSmall[numSmall] << endl;
        return;
    }

    long long result = 0;
    FOR(i, 1, numLarge) {
        long long minDisabled = 1LL * dist * (i - 1);
        long long maxDisabled = 1LL * dist * i;
        long long minCandidate = numLarge - i;
        long long maxCandidate = numLarge - i + numSmall;
        if (max(minDisabled, minCandidate) > min(maxDisabled, maxCandidate)) continue;
        int numSmallDisabled = max(minDisabled, minCandidate) - minCandidate;
        maximize(result, sumLarge[i] + sumSmall[numSmall - numSmallDisabled]);
    }
    cout << result << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/