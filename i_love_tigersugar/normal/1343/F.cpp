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

#define MAX   222
typedef bitset<MAX> Bitset;

int n;
vector<int> segments[MAX];
Bitset suffix[MAX], sets[MAX];
int perm[MAX];

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n - 1) {
        segments[i].clear();
        sets[i].reset();
        int k; scanf("%d", &k);
        REP(love, k) {
            int x; scanf("%d", &x);
            segments[i].push_back(x);
            sets[i].set(x);
        }
    }
}

bool trySomethingFunny(int x, int y) {
//    printf("Trying %d %d\n", x, y);

    FOR(i, 1, n) suffix[i].reset();
    memset(perm, -1, sizeof perm);

    perm[1] = x; perm[2] = y;

    suffix[1].set(x); suffix[1].set(y);
    suffix[2].set(y);

    FOR(i, 3, n) {
        FOR(j, 1, n - 1) {
            Bitset joint = suffix[1] & sets[j];
            Bitset other = sets[j] & ~joint;

            if (other.count() == 0) continue;
            if (joint != suffix[i - joint.count()]) return false;

            if (other.count() == 1) {
                FOR(k, 1, n) if (other[k]) {
//                    printf("Found perm[%d] = %d\n", i, k);
                    if (perm[i] > 0 && perm[i] != k) return false;
                    perm[i] = k;
                }
            }
        }

        if (perm[i] < 0) return false;
        FOR(j, 1, i) suffix[j].set(perm[i]);
    }

    return true;
}

void process(void) {
    FOR(i, 1, n - 1) if (segments[i].size() == 2) {
        if (trySomethingFunny(segments[i][0], segments[i][1])) {
            FOR(j, 1, n) printf("%d ", perm[j]); printf("\n");
            return;
        }
        if (trySomethingFunny(segments[i][1], segments[i][0])) {
            FOR(j, 1, n) printf("%d ", perm[j]); printf("\n");
            return;
        }
    }

    assert(false);
}

int main(void) {
    int t; scanf("%d", &t);
    REP(love, t) {
        init();
        process();
    }

    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/