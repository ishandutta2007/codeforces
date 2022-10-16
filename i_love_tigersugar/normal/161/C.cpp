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

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

int high(int x) {
    int res = 0;
    while (x % 2 == 0) {
        x /= 2; res++;
    }
    return res;
}

int leftChild(int x) {
    int t = high(x);
    return x - MASK(t - 1);
}
int rightChild(int x) {
    int t = high(x);
    return x + MASK(t - 1);
}

#define LEFT   0
#define RIGHT  1
int dir(int x, int t) {
    return (x - MASK(t)) % MASK(t + 2) == 0 ? LEFT : RIGHT;
}

int parent(int x) {
    int t = high(x);
    return dir(x, t) == LEFT ? x + MASK(t) : x - MASK(t);
}

int lca(int u, int v) {
    int hu = high(u), hv = high(v);
    REP(love, hv - hu) u = parent(u);
    REP(love, hu - hv) v = parent(v);

    while (u != v) {
        u = parent(u);
        v = parent(v);
    }
    return u;
}

bool isWholeTree(int l, int r) {
    int w = lca(l, r);
    int t = high(w);
    return (l + r == 2 * w && r - l + 1 == MASK(t + 1) - 1);
}

struct Query {
    int l, r, u, v;

    Query(int l = 0, int r = 0, int u = 0, int v = 0) {
        if (isWholeTree(l, r)) {
            r-= l - 1; l = 1;
        }
        if (isWholeTree(u, v)) {
            v -= u - 1; u = 1;
        }

        if (make_pair(l, r) > make_pair(u, v)) {
            swap(l, u); swap(r, v);
        }
        this->l = l; this->r = r; this->u = u; this->v = v;
    }

    bool operator < (const Query &q) const {
        if (l != q.l) return l < q.l;
        if (r != q.r) return r < q.r;
        if (u != q.u) return u < q.u;
        return v < q.v;
    }
};

map<Query, int> cache;

int lcs(int l, int r, int u, int v) {
    if (l > r || u > v) return 0;

    Query query(l, r, u, v);
    __typeof(cache.begin()) it = cache.find(query);
    if (it != cache.end()) return it->se;

    int& result = cache[query];

    int lr = lca(l, r), uv = lca(u, v);
    int hlr = high(lr), huv = high(uv);

    if (hlr > huv) return result = max(lcs(l, lr - 1, u, v), lcs(lr + 1, r, u, v));
    if (huv > hlr) return result = max(lcs(l, r, u, uv - 1), lcs(l, r, uv + 1, v));

    int left = min(uv - u, lr - l);
    int right = min(v - uv, r - lr);
    result = left + right + 1;
    REP(i, 2) REP(j, 2) {
        pair<int, int> a = i ? make_pair(l, lr - 1) : make_pair(lr + 1, r);
        pair<int, int> b = j ? make_pair(u, uv - 1) : make_pair(uv + 1, v);
        maximize(result, lcs(a.fi, a.se, b.fi, b.se));
    }
    return result;
}

int main(void) {
    int l, r, u, v;
    while (cin >> l >> r >> u >> v) cout << lcs(l, r, u, v) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/