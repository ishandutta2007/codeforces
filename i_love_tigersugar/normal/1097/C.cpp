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

#define OPEN   '('
#define CLOSE   ')'

pair<int, int> getInfo(const string &s) {
    int deg = 0, minDeg = 0;
    FORE(it, s) {
        if (*it == OPEN) deg++; else deg--;
        minimize(minDeg, deg);
    }
    return make_pair(minDeg, deg);
}

void process(void) {
    int n; cin >> n;

    map<int, int> pos, neg;
    int zero = 0;

    REP(love, n) {
        string s; cin >> s;
        pair<int, int> info = getInfo(s);
        if (info.se == 0) {
            if (info.fi >= 0) zero++;
        }
        if (info.se > 0) {
            if (info.fi >= 0) pos[info.se]++;
        }
        if (info.se < 0) {
            if (info.fi == info.se) neg[-info.se]++;
        }
    }

    int res = zero / 2;
    FORE(it, pos) res += min(it->se, neg[it->fi]);
    cout << res << endl;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/