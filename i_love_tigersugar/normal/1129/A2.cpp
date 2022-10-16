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

#define MAX   100100

int cnt[MAX], minDist[MAX], n, m;

int distan(int fr, int to) {
    return fr <= to ? to - fr : to - fr + n;
}

void init(void) {
    scanf("%d%d", &n, &m);
    REP(love, m) {
        int a, b; scanf("%d%d", &a, &b);
        if (cnt[a] == 0) minDist[a] = distan(a, b); else minimize(minDist[a], distan(a, b));
        cnt[a]++;
    }
}

long long solve(int start) {
    long long res = 0;
    FOR(i, 1, n) {
        long long preDist = 1LL * (cnt[i] - 1) * n + distan(start, i) + minDist[i];
        maximize(res, preDist);
    }
    return res;
}

void process(void) {
    FOR(i, 1, n) cout << solve(i) << " "; cout << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/