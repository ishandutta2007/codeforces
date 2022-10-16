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

int n;

int ask(int l, int r) {
    cout << "1 " << r - l + 1 << " 1 ";
    FOR(i, l, r) cout << i << " ";
    cout << endl;
    int res; cin >> res;
    return res;
}

int getLeaf(void) {
    int goal = ask(2, n);
    int L = 2, R = n;
    while (true) {
        if (L == R) return R;
        if (R - L == 1) return ask(L, L) == goal ? L : R;
        int M = (L + R) >> 1;
        if (ask(L, M) == goal) R = M; else L = M + 1;
    }
}

void process(void) {
    cin >> n;
    int leaf = getLeaf();

    cout << 1 << " " << n - 1 << " " << leaf << " ";
    FOR(i, 1, n) if (i != leaf) cout << i << " ";
    cout << endl;
    int res; cin >> res;
    cout << "-1 " << res << endl;
}

int main(void) {
    int t; cin >> t;
    REP(love, t) process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/