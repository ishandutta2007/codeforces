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

class FenwickTree {
private:
    vector<int> v;
    int n;

public:
    FenwickTree(int n = 0) {
        this->n = n;
        v.assign(n + 7, 0);
    }

    void update(int x, int d) {
        for (; x <= n; x += x & -x) maximize(v[x], d);
    }

    int get(int x) const {
        int res = 0;
        for (; x >= 1; x &= x - 1) maximize(res, v[x]);
        return res;
    }
};

#define MAX   100100

int cnt[MAX], lis[MAX], lds[MAX], delta[MAX];
int numSeg, range;
pair<int, int> segments[MAX];

void init(void) {
    scanf("%d%d", &numSeg, &range);
    FOR(i, 1, numSeg) scanf("%d%d", &segments[i].fi, &segments[i].se);
}

void process(void) {
    FOR(i, 1, numSeg) {
        delta[segments[i].fi]++;
        delta[segments[i].se + 1]--;
    }
    FOR(i, 1, range) cnt[i] = cnt[i - 1] + delta[i];
    FOR(i, 1, range) cnt[i]++;

    FenwickTree bit(numSeg + 1);
    FOR(i, 1, range) {
        lis[i] = bit.get(cnt[i]) + 1;
        bit.update(cnt[i], lis[i]);
    }

    bit = FenwickTree(range);
    FORD(i, range, 1) {
        lds[i] = bit.get(cnt[i]) + 1;
        bit.update(cnt[i], lds[i]);
    }

//    FOR(i, 1, range) printf("pos %d lis %d lds %d\n", i, lis[i], lds[i]);

    int res = 0;
    FOR(i, 1, range) maximize(res, lis[i] + lds[i] - 1);
    printf("%d\n", res);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/