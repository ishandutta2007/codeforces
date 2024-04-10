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

const int INF = (int)1e9 + 7;

class FenwickTree {
private:
    int n;
    vector<int> v;

public:
    FenwickTree(int _n = 0) {
        n = _n;
        if (n > 0) v.assign(n + 7, INF);
    }

    void update(int x, int d) {
        for (; x <= n; x += x & -x) minimize(v[x], d);
    }

    int getMin(int x) const {
        int res = INF;
        for (; x >= 1; x &= x - 1) minimize(res, v[x]);
        return res;
    }
};

const char* YES = "yes";
const char* NO = "no";

#define MAX   100100
int a[MAX], x[MAX], y[MAX], n, mid;

void init(void) {
    scanf("%d%d", &n, &mid);
    x[0] = y[0] = 0;
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        x[i] = i;
        y[i] = y[i - 1] + (a[i] >= mid ? 1 : -1);
    }
}

void compress(vector<int> &v, int x[]) {
    FOR(i, 0, n) v.push_back(x[i]);
    sort(ALL(v));
    v.resize(unique(ALL(v)) - v.begin());
    FOR(i, 0, n) x[i] = lower_bound(ALL(v), x[i]) - v.begin() + 1;
}

bool process(void) {
    if (n == 1) return a[1] == mid;

    bool haveMid = false;
    FOR(i, 1, n) if (a[i] == mid) haveMid = true;
    if (!haveMid) return false;

    vector<int> vx, vy;
    compress(vx, x);
    compress(vy, y);

    FenwickTree bit(vx.size());
    int j = 0;
    FOR(i, 0, n) {
        while (j <= i - 2) {
            bit.update(x[j], y[j]);
            j++;
        }
        if (bit.getMin(x[i]) < y[i]) return true;
    }
    return false;
}

int main(void) {
    int t; scanf("%d", &t);
    REP(love, t) {
        init();
        printf("%s\n", process() ? YES : NO);
    }
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/