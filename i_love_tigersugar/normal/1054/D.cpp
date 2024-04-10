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

#define MAX   200200

int a[MAX], sum[MAX], n, k;
map<int, int> groups;

int getGroup(int x) {
    return min(1LL * x, x ^ (MASK(k) - 1));
}

void process(void) {
    scanf("%d%d", &n, &k);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) sum[i] = sum[i - 1] ^ a[i];

    FOR(i, 0, n) groups[getGroup(sum[i])]++;

    long long diffGroup = 0;
    FORE(it, groups) diffGroup += 1LL * it->se * (n + 1 - it->se);
    long long sameGroup = 0;
    FORE(it, groups) if (it->se > 1) {
        int x = it->se / 2;
        int y = it->se - x;
        sameGroup += 1LL * x * y;
    }
    cout << diffGroup / 2 + sameGroup << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/