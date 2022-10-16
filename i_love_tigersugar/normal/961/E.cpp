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

    int get(int x) const {
        int res = 0;
        for (; x >= 1; x &= x - 1) res += v[x];
        return res;
    }

public:
    FenwickTree(int n = 0) {
        this->n = n;
        v.assign(n + 7, 0);
    }

    void update(int x, int d) {
        for (; x <= n; x += x & -x) v[x] += d;
    }

    int get(int l, int r) const {
        if (l > r) return 0;
        return l == 1 ? get(r) : get(r) - get(l - 1);
    }
};

#define MAX   200200
int a[MAX], n;

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) minimize(a[i], n);
}

bool compareValue(const int &x, const int &y) {
    return a[x] > a[y];
}
void process(void) {
    vector<int> indices;
    FOR(i, 1, n) indices.push_back(i);
    sort(ALL(indices), compareValue);

    long long res = 0;
    FenwickTree bit(n);
    int j = 0;
    FORD(i, n, 1) {
        while (j < indices.size() && a[indices[j]] >= i) {
            bit.update(indices[j], 1);
            j++;
        }
        res += bit.get(i + 1, a[i]);
    }

    cout << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/