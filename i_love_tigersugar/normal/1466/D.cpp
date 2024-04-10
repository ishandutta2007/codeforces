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

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

#define MAX   200200
int numNode;
int deg[MAX], value[MAX];

void process(void) {
    scanf("%d", &numNode);
    FOR(i, 1, numNode) scanf("%d", &value[i]);

    memset(deg, 0, (numNode + 1) * sizeof (int));
    REP(love, numNode - 1) {
        int u, v; scanf("%d%d", &u, &v);
        deg[u]++; deg[v]++;
    }

    long long sum = 0;
    FOR(i, 1, numNode) sum += value[i];

    priority_queue<int> candidates;
    FOR(i, 1, numNode) REP(love, deg[i] - 1) candidates.push(value[i]);

    printf("%lld ", sum);
    while (!candidates.empty()) {
        int u = candidates.top(); candidates.pop();
        sum += u;
        printf("%lld ", sum);
    }
    printf("\n");
}

int main(void) {
    int t; scanf("%d", &t);
    REP(love, t) process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/