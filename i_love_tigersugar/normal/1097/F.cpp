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

bool isSquareFree(int x) {
    for (int i = 2; 1LL * i * i <= x; i++) if (x % (i * i) == 0) return false;
    return true;
}

const int MAX_VALUE = 7070;
typedef bitset<MAX_VALUE + 3> BitSet;

BitSet single[MAX_VALUE + 3], needCount[MAX_VALUE + 3];
vector<int> squarefree;

void prepare(void) {
    FOR(i, 1, MAX_VALUE) if (isSquareFree(i)) squarefree.push_back(i);
    FOR(i, 1, MAX_VALUE)
        for (int j = 1; j * j <= i; j++) if (i % j == 0) {
            single[i][j] = 1;
            if (j * j < i) single[i][i / j] = 1;
        }

    FOR(i, 1, MAX_VALUE) FORE(jt, squarefree) {
        if (i * (*jt) > MAX_VALUE) break;
        needCount[i][i * (*jt)] = 1;
    }
}

#define MAX   100100
BitSet sets[MAX];
int numSet, numQuery;

void process(void) {
    scanf("%d%d", &numSet, &numQuery);
    REP(love, numQuery) {
        int type, x, y; scanf("%d%d%d", &type, &x, &y);
        if (type == 1) {
            sets[x] = single[y];
        }
        if (type == 2) {
            int z; scanf("%d", &z);
            sets[x] = sets[y] ^ sets[z];
        }
        if (type == 3) {
            int z; scanf("%d", &z);
            sets[x] = sets[y] & sets[z];
        }
        if (type == 4) {
            printf("%d", int((sets[x] & needCount[y]).count() % 2));
        }
    }
    printf("\n");
}

int main(void) {
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/