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
pair<int, int> points[MAX];
int n;

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d%d", &points[i].fi, &points[i].se);
    FORD(i, n, 1) {
        points[i].fi -= points[1].fi;
        points[i].se -= points[1].se;
    }

    int t = 0;
    FOR(i, 1, n) {
        t = __gcd(t, points[i].fi);
        t = __gcd(t, points[i].se);
    }

    FOR(i, 1, n) {
        points[i].fi /= t;
        points[i].se /= t;
    }

    bool haveOdd = false;
    FOR(i, 1, n) if ((points[i].fi + points[i].se) % 2 != 0) haveOdd = true;

    vector<int> indices;
    if (haveOdd) {
        FOR(i, 1, n) if ((points[i].fi + points[i].se) % 2 != 0) indices.push_back(i);
    } else {
        FOR(i, 1, n) if (points[i].fi % 2 != 0) indices.push_back(i);
    }

    printf("%d\n", (int)indices.size());
    FORE(it, indices) printf("%d ", *it); printf("\n");
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/