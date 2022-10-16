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

#define MAX   1111
int value[MAX], perm[MAX], pos[MAX], n;

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &value[i]);

    vector<pair<int, int>> v;
    FOR(i, 1, n) v.push_back(make_pair(value[i], i));
    sort(ALL(v));

    REP(i, n) perm[v[i].se] = i + 1;
    FOR(i, 1, n) pos[perm[i]] = i;

    queue<int> q;
    FOR(i, 1, n - 1) if (pos[i] > pos[i + 1]) q.push(i);

    vector<pair<int, int>> res;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (pos[x] < pos[x + 1]) continue;

        int l = min(pos[x], pos[x + 1]);
        int r = max(pos[x], pos[x + 1]);
        res.push_back(make_pair(l, r));

        swap(pos[x], pos[x + 1]);
        perm[pos[x]] = x;
        perm[pos[x + 1]] = x + 1;

        if (x > 1 && pos[x - 1] > pos[x]) q.push(x - 1);
        if (x + 1 < n && pos[x + 1] > pos[x + 2]) q.push(x + 1);
    }

    printf("%d\n", (int)res.size());
    FORE(it, res) printf("%d %d\n", it->fi, it->se);
}

int main(void) {
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/