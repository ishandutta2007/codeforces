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

#define MAX   10001000
const long long INF = (long long)1e18 + 7LL;

pair<int, int> indices[MAX];
int n, value[MAX];

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &value[i]);
}

void update(pair<int, int> &a, int b) {
    if (a.fi == 0) a.fi = b;
    else if (a.se == 0) a.se = b;
}

void process(void) {
    FOR(i, 1, n) update(indices[value[i]], i);
    long long res = INF;
    pair<int, int> best, cur;
    FOR(i, 1, MAX - 1) {
        cur.fi = cur.se = 0;
        for (int j = i; j < MAX; j += i) {
            if (cur.se > 0) break;
            if (indices[j].fi > 0) update(cur, indices[j].fi);
            if (indices[j].se > 0) update(cur, indices[j].se);
        }
        if (cur.se > 0 && minimize(res, 1LL * value[cur.fi] * value[cur.se] / i)) best = cur;
    }
    if (best.fi > best.se) swap(best.fi, best.se);
    cout << best.fi << " " << best.se << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/