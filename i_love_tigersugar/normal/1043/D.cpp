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

#define MAX_PERM 13
#define MAX   100100

int numPerm, numValue;
int perm[MAX_PERM][MAX];
int pos[MAX_PERM][MAX];
bool ok[MAX];

void init(void) {
    scanf("%d%d", &numValue, &numPerm);
    FOR(i, 1, numPerm) FOR(j, 1, numValue) scanf("%d", &perm[i][j]);
    FOR(i, 1, numPerm) FOR(j, 1, numValue) pos[i][perm[i][j]] = j;
}

int getMax(set<int> &s) {
    assert(!s.empty());
    __typeof(s.begin()) it = s.end(); it--;
    return *it;
}

void process(void) {
    FOR(i, 1, numValue - 1) {
        int x = perm[1][i], y = perm[1][i + 1];
        ok[i] = true;
        FOR(j, 1, numPerm) ok[i] &= pos[j][y] - pos[j][x] == 1;
    }

    long long res = 0;
    int j = 1;
    FOR(i, 1, numValue) {
        if (j < i) j = i;
        while (j < numValue && ok[j]) j++;
        res += j - i + 1;
    }
    cout << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/