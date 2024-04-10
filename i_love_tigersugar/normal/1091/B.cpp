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

#define MAX   1111
pair<int, int> points[MAX], dirs[MAX];
map<pair<int, int>, int> score;
int numPoint;

pair<int, int> operator + (const pair<int, int> &a, const pair<int, int> &b) {
    return make_pair(a.fi + b.fi, a.se + b.se);
}

void process(void) {
    cin >> numPoint;
    FOR(i, 1, numPoint) cin >> points[i].fi >> points[i].se;
    FOR(i, 1, numPoint) cin >> dirs[i].fi >> dirs[i].se;

    FOR(i, 1, numPoint) FOR(j, 1, numPoint)
        score[points[i] + dirs[j]]++;

    FORE(it, score) if (it->se == numPoint) {
        cout << (it->fi).fi << " " << (it->fi).se << endl;
        return;
    }
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/