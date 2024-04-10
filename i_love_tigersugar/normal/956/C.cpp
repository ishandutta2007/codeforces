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

#define MAX   200200
int n, a[MAX];
bool mark[MAX];

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) a[i]++;
}

void process(void) {
    int cnt = 0;
    stack<int> lv;
    FOR(i, 1, n) {
        lv.push(i);
        while (cnt < a[i]) {
            assert(!lv.empty());
            cnt++;
            mark[lv.top()] = true; lv.pop();
        }
    }

    cnt = 0;
    long long res = 0;
    FOR(i, 1, n) {
        if (mark[i]) cnt++;
        res += cnt - a[i];
    }
    cout << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/