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

const char YES[] = "Shi";
const char NO[] = "Fou";

#define MAX   300300
#define NUM_BIT   19
int firstPos[NUM_BIT + 1];
int firstReach[MAX][NUM_BIT + 1];
int value[MAX], n, q;

void prepare(void) {
    scanf("%d%d", &n, &q);
    FOR(i, 1, n) scanf("%d", &value[i]);
    REP(j, NUM_BIT) firstPos[j] = n + 1;
    memset(firstReach, 0x3f, sizeof firstReach);
    FORD(i, n, 1) {
        REP(j, NUM_BIT) {
            if (!BIT(value[i], j)) {
                REP(k, NUM_BIT) if (BIT(value[i], k) && firstPos[k] <= n)
                    minimize(firstReach[i][j], firstReach[firstPos[k]][j]);
            }
        }
        REP(j, NUM_BIT) if (BIT(value[i], j)) {
            firstPos[j] = i;
            firstReach[i][j] = i;
        }
    }
}

bool query(int x, int y) {
    if (x > y) return false;
    if ((value[x] & value[y]) > 0) return true;
    REP(i, NUM_BIT) if (BIT(value[y], i) && firstReach[x][i] <= y) return true;
    return false;
}

void process(void) {
    REP(love, q) {
        int x, y; scanf("%d%d", &x, &y);
        printf("%s\n", query(x, y) ? YES : NO);
    }
}

int main(void) {
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/