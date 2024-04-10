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
int a[MAX], n, orLeft[MAX], orRight[MAX];

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);

    FOR(i, 1, n) orLeft[i] = orLeft[i - 1] | a[i];
    FORD(i, n, 1) orRight[i] = orRight[i + 1] | a[i];

    int best = -1, index = -1;
    FOR(i, 1, n) {
        int tmp = a[i] & ~(orLeft[i - 1] | orRight[i + 1]);
        if (maximize(best, tmp)) index = i;
    }

    printf("%d", a[index]);
    FOR(i, 1, n) if (i != index) printf(" %d", a[i]);
    printf("\n");
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/