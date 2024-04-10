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

map<int, int> a, b;

void process(void) {
    int n; scanf("%d", &n);
    REP(love, n) {
        int x, y; scanf("%d%d", &x, &y);
        a[x] = y;
    }
    scanf("%d", &n);
    REP(love, n) {
        int x, y; scanf("%d%d", &x, &y);
        b[x] = y;
    }

    set<int> values;
    FORE(it, a) values.insert(it->fi);
    FORE(it, b) values.insert(it->fi);

    long long res = 0;
    FORE(it, values) res += max(a[*it], b[*it]);
    cout << res << endl;
}

int main(void) {
    process();
    return 0;
}


/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/