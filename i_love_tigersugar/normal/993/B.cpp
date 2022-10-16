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

#define MAX   111
int na, nb;
pair<int, int> a[MAX], b[MAX];

void init(void) {
    cin >> na >> nb;
    REP(i, na) cin >> a[i].fi >> a[i].se;
    REP(i, nb) cin >> b[i].fi >> b[i].se;

    REP(i, na) if (a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
    REP(i, nb) if (b[i].fi > b[i].se) swap(b[i].fi, b[i].se);
}

int sharedNumber(const pair<int, int> &a, const pair<int, int> &b) {
    REP(i, 2) REP(j, 2) {
        int x = i ? a.fi : a.se;
        int y = j ? b.fi : b.se;
        if (x == y) return x;
    }
    return -1;
}

int scenario(int x, int y) {
    int maskA = 0, maskB = 0;
    REP(i, nb) if (b[i] != a[x]) {
        int t = sharedNumber(a[x], b[i]);
        if (t >= 0) maskA |= MASK(t);
    }
    REP(i, na) if (a[i] != b[y]) {
        int t = sharedNumber(a[i], b[y]);
        if (t >= 0) maskB |= MASK(t);
    }
    if (__builtin_popcount(maskA) != 1) return -1;
    if (__builtin_popcount(maskB) != 1) return -1;
    return sharedNumber(a[x], b[y]);
}

void answer(int x) {
    cout << x << endl;
    exit(EXIT_SUCCESS);
}

void process(void) {
    REP(i, na) REP(j, nb) if (a[i] != b[j] && sharedNumber(a[i], b[j]) >= 0 && scenario(i, j) < 0) answer(-1);
    int mask = 0;
    REP(i, na) REP(j, nb) if (a[i] != b[j] && sharedNumber(a[i], b[j]) >= 0) mask |= MASK(scenario(i, j));
    if (__builtin_popcount(mask) != 1) answer(0);
    REP(i, 10) if (BIT(mask, i)) answer(i);
    assert(false);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/