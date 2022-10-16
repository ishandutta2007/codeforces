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
    void minimize(X &x, const Y &y) {
        if (x > y) x = y;
    }
template<class X, class Y>
    void maximize(X &x, const Y &y) {
        if (x < y) x = y;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   2207
#define SQR(x) (1LL * (x) * (x))

int n, limit, a[MAX], b[MAX], diff[MAX];

void init(void) {
    int x, y; scanf("%d%d%d", &n, &x, &y);
    limit = x + y;

    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) scanf("%d", &b[i]);
    FOR(i, 1, n) diff[i] = Abs(a[i] - b[i]);
}

void process(void) {
    priority_queue<pair<int, int>> q;
    FOR(i, 1, n) q.push(make_pair(diff[i], i));

    REP(love, limit) {
        int id = q.top().se; q.pop();
        if (diff[id] > 0) diff[id]--; else diff[id]++;
        q.push(make_pair(diff[id], id));
    }

    long long res = 0;
    FOR(i, 1, n) res += SQR(diff[i]);
    cout << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/