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

#define MAX   100100

int goal[MAX], order[MAX], n;
pair<int, int> pos[MAX];

bool Compare(const int &x, const int &y) {
    return pos[x].fi + pos[x].se < pos[y].fi + pos[y].se;
}

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, 2 * n) {
        int x; scanf("%d", &x);
        if (pos[x].fi < 1) pos[x].fi = i; else pos[x].se = i;
    }

    FOR(i, 1, n) order[i] = i;
    sort(order + 1, order + n + 1, Compare);

    int tmp = 0;
    FOR(i, 1, n) {
        int j = order[i];
        goal[++tmp] = pos[j].fi;
        goal[++tmp] = pos[j].se;
    }

    int res = 0;
    FOR(i, 1, 2 * n) FOR(j, i + 1, 2 * n) if (goal[i] > goal[j]) res++;
    cout << res << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/