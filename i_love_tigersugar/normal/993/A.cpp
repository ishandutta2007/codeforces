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

const string YES = "YES";
const string NO = "NO";

void answer(const string &s) {
    cout << s << endl;
    exit(EXIT_SUCCESS);
}

const int INF = (int)1e9 + 7;
int minX, maxX, minY, maxY;
int minAdd, maxAdd, minSub, maxSub;

void process(void) {
    minX = minY = INF;
    maxX = maxY = -INF;
    REP(love, 4) {
        int x, y; assert(cin >> x >> y); x *= 2; y *= 2;
        minimize(minX, x);
        minimize(minY, y);
        maximize(maxX, x);
        maximize(maxY, y);
    }

    minAdd = minSub = INF;
    maxAdd = maxSub = -INF;
    REP(love, 4) {
        int x, y; assert(cin >> x >> y); x *= 2; y *= 2;
        minimize(minAdd, x + y);
        minimize(minSub, x - y);
        maximize(maxAdd, x + y);
        maximize(maxSub, x - y);
    }

    FOR(y, minY, maxY) {
        int L = minX, R = maxX;
        maximize(L, minAdd - y); minimize(R, maxAdd - y);
        maximize(L, minSub + y); minimize(R, maxSub + y);
        if (L <= R) answer(YES);
    }
    answer(NO);
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/