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

#define MAX   11111
bool used[MAX];
int pairWith[MAX];
int n, numPair, value[MAX];
pair<int, int> pairs[MAX];

void init(void) {
    cin >> n >> numPair;
    FOR(i, 1, 2 * n) cin >> value[i];

    memset(pairWith, -1, sizeof pairWith);

    FOR(i, 1, numPair) {
        int u, v; cin >> u >> v;
        pairWith[u] = v;
        pairWith[v] = u;
        pairs[i] = make_pair(u, v);
    }
}

void playFirst(void) {
    FOR(i, 1, numPair) {
        int u = pairs[i].fi, v = pairs[i].se;
        int better = value[u] > value[v] ? u : v;
        cout << better << endl;
        int x; cin >> x;
        assert(x == (u ^ v ^ better));
        used[u] = true; used[v] = true;
    }

    priority_queue<pair<int, int>> items;
    FOR(i, 1, 2 * n) if (!used[i]) items.push(make_pair(value[i], i));
    REP(love, n - numPair) {
        while (!items.empty() && used[items.top().se]) items.pop();
        assert(!items.empty());
        int x = items.top().se; items.pop();
        cout << x << endl;
        int y; cin >> y;
        used[x] = true; used[y] = true;
    }
}

void playSecond(void) {
    priority_queue<pair<int, int>> items;
    FOR(i, 1, 2 * n) if (pairWith[i] < 1) items.push(make_pair(value[i], i));
    REP(love, n) {
        int x; cin >> x; used[x] = true;
        if (pairWith[x] > 0 && !used[pairWith[x]]) {
            int y = pairWith[x];
            cout << y << endl;
            used[x] = true;
            used[y] = true;
        } else {
            bool ok = false;
            FOR(i, 1, numPair) {
                int x = pairs[i].fi, y = pairs[i].se;
                if (used[x] && used[y]) continue;
                assert(!used[x] && !used[y]);
                int better = value[x] > value[y] ? x : y;
                cout << better << endl;
                used[x] = true; used[y] = true;
                ok = true;
                break;
            }
            if (!ok) {
                while (!items.empty() && used[items.top().se]) items.pop();
                assert(!items.empty());
                int x = items.top().se; items.pop();
                cout << x << endl;
                used[x] = true;
            }
        }
    }
}

int main(void) {
    init();
    int side; cin >> side;
    if (side == 1) playFirst(); else playSecond();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/