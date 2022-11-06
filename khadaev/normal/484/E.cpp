#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

struct T {
    int pref, suff, full, len;

    T () {
        pref = suff = full = len = 0;
    }

    T (int p, int s, int f, int l) : pref(p), suff(s), full(f), len(l) {}
};

const T DEFAULT = T();
const T ON =  T(1, 1, 1, 1);
const T OFF = T(0, 0, 0, 1);

T combine(T x, T y) {
    return T(x.full == x.len ? x.full + y.pref : x.pref,
             y.full == y.len ? y.full + x.suff : y.suff,
             max(max(x.full, y.full), x.suff + y.pref),
             x.len + y.len);
}

struct Vertex {
    T val;
    int lc, rc;

    Vertex() {
        val = OFF;
    };
};

const int N = 1e5 + 10;
const int LOG = 17;
const int SZ = N * LOG * 4;
Vertex a[SZ];

struct SegmentTreeTopDown {
    Vertex* a;
    int ix, n;

    SegmentTreeTopDown () {};

    SegmentTreeTopDown (int _n, Vertex* _a) {
        a = _a;
        ix = 0;
        n = _n;
        build(0, 0, n);
    }

    void relax(int i) {
        if (a[i].lc == -1) return;
        a[i].val = combine(a[a[i].lc].val, a[a[i].rc].val);
    }

    void build(int i, int lb, int rb) {
        if (lb + 1 == rb) {
            a[i].lc = a[i].rc = -1;
            return;
        }
        int mid = (lb + rb) / 2;
        a[i].lc = ++ix;
        build(ix, lb, mid);
        a[i].rc = ++ix;
        build(ix, mid, rb);
        relax(i);
    }

    T _get(int i, int l, int r, int lb, int rb) {
        l = max(l, lb);
        r = min(r, rb);
        if (l >= r) return DEFAULT;
        if (l == lb && r == rb)
            return a[i].val;
        int mid = (lb + rb) / 2;
        return  combine(_get(a[i].lc, l, r, lb, mid),
            _get(a[i].rc, l, r, mid, rb));
    }

    T get(int i, int l, int r) {
        return _get(i, l, r, 0, n);
    }

    void _set(int i, int pos, int lb, int rb, T value) {
        if (lb + 1 == rb) {
            if (lb == pos) a[i].val = value;
            else assert(false);
            return;
        }
        int mid = (lb + rb) / 2;
        if (pos < mid) {
            int u = ++ix;
            a[u] = a[a[i].lc];
            a[i].lc = u;
            _set(u, pos, lb, mid, value);
        } else {
            int u = ++ix;
            a[u] = a[a[i].rc];
            a[i].rc = u;
            _set(u, pos, mid, rb, value);
        }
        relax(i);
    }

    int set(int i, int pos, T v) {
        int u = ++ix;
        a[u] = a[i];
        _set(u, pos, 0, n, v);
        return u;
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    SegmentTreeTopDown tree(n, a);
    vector<int> h(n);
    forn(i, 0, n) cin >> h[i];
    vector<pair<int, int>> order(n);
    forn(i, 0, n) order[i] = {h[i], i};
    sort(all(order));
    vector<int> root(n + 1);
    root[n] = 0;
    ford(i, 0, n) root[i] = tree.set(root[i + 1], order[i].sn, ON);
    int q;
    cin >> q;
    while (q--) {
        int lft, rgt, wdh;
        cin >> lft >> rgt >> wdh;
        --lft;
        int l = 0, r = n;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (tree.get(root[mid], lft, rgt).full >= wdh)
                l = mid;
            else
                r = mid;
        }
        cout << order[l].fs << '\n';
        //fore(i, 0, n) cout << tree.get(root[i], lft, rgt).full <<  ' ';
        //cout << '\n';
    }
}