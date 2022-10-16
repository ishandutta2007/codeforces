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

#define MAX   300300
const int INF = (int)1e9 + 7;

int length[MAX], limit, res, n, q;

void init(void) {
    scanf("%d%d%d", &n, &q, &limit);
    FOR(i, 1, n) scanf("%d", &length[i]);
    FOR(i, 1, n) {
        bool cur = length[i] > limit;
        bool prev = length[i - 1] > limit;
        if (cur && !prev) res++;
    }
}

void process(void) {
    REP(love, q) {
        int t; scanf("%d", &t);
        if (t == 0) printf("%d\n", res);
        else {
            int p, d; scanf("%d%d", &p, &d);
            bool before = length[p] > limit;
            length[p] = min(length[p] + d, INF);
            bool after = length[p] > limit;
            if (after != before) {
                bool prev = length[p - 1] > limit;
                bool next = length[p + 1] > limit;
                if (next) res--;
                if (!prev) res++;
            }
        }
    }
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/