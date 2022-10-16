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

#define MAX   150
const int INF = (int)1e9 + 7;

int val[MAX], n, f[MAX][MAX][MAX][2];

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &val[i]);

    int numEven = n / 2;
    int numOdd = n - numEven;

    memset(f, 0x3f, sizeof f);
    REP(t, 2) if (val[1] == 0 || (val[1] - t) % 2 == 0) {
        int ne = t == 0, no = t == 1;
        if (ne <= numEven && no <= numOdd) minimize(f[1][ne][no][t], 0);
    }

    FOR(i, 1, n - 1) REP(ce, numEven + 1) REP(co, numOdd + 1) REP(last, 2) if (f[i][ce][co][last] < INF) {
        REP(t, 2) if (val[i + 1] == 0 || (val[i + 1] - t) % 2 == 0) {
            int ne = ce + (t == 0);
            int no = co + (t == 1);
            if (ne <= numEven && no <= numOdd) minimize(f[i + 1][ne][no][t], f[i][ce][co][last] + (last != t));
        }
    }

    cout << min(f[n][numEven][numOdd][0], f[n][numEven][numOdd][1]) << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/