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

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1e5 + 10;

struct Vertex {
    int val, toPush, lc, rc;

    Vertex() {
        val = 0;
        toPush = -1;
    };
};

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
    }

    void push(int i, int sz) {
        if (a[i].toPush != -1) {
            if (a[i].lc != -1) {
                a[a[i].lc].toPush = a[i].toPush;
                a[a[i].rc].toPush = a[i].toPush;
            }
            a[i].val = a[i].toPush * sz;
            a[i].toPush = -1;
        }
    }

    void relax(int i, int lb, int rb) {
        if (a[i].lc == -1) return;
        int mid = (lb + rb) / 2;
        push(a[i].lc, mid - lb);
        push(a[i].rc, rb - mid);
        a[i].val = a[a[i].lc].val + a[a[i].rc].val;
    }

    int _get(int i, int l, int r, int lb, int rb) {
        push(i, rb - lb);
        l = max(l, lb);
        r = min(r, rb);
        if (l >= r) return 0;
        if (l == lb && r == rb)
            return a[i].val;
        int mid = (lb + rb) / 2;
        int rez =  _get(a[i].lc, l, r, lb, mid)
            + _get(a[i].rc, l, r, mid, rb);
        relax(i, lb, rb);
        return rez;
    }

    int get(int l, int r) {
        return _get(0, l, r, 0, n);
    }

    void _set(int i, int l, int r, int lb, int rb, int v) {
        push(i, rb - lb);
        l = max(l, lb);
        r = min(r, rb);
        if (l >= r) return;
        if (l == lb && r == rb) {
            a[i].toPush = v;
            return;
        }
        int mid = (lb + rb) / 2;
        _set(a[i].lc, l, r, lb, mid, v);
        _set(a[i].rc, l, r, mid, rb, v);
        relax(i, lb, rb);
    }

    void set(int l, int r, int v) {
        _set(0, l, r, 0, n, v);
    }
};

const int S = 26;
Vertex vs[S][2 * N];
SegmentTreeTopDown tree[S];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    forn(i, 0, S)
        tree[i] = SegmentTreeTopDown(n, vs[i]);
    forn(i, 0, n)
        tree[s[i] - 'a'].set(i, i + 1, 1);
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        --l;
        if (k == 1) {
            int x = l;
            forn(i, 0, S) {
                int cnt = tree[i].get(l, r);
                tree[i].set(l, x, 0);
                tree[i].set(x, x + cnt, 1);
                tree[i].set(x + cnt, r, 0);
                x += cnt;
            }
        } else {
            int x = l;
            ford(i, 0, S) {
                int cnt = tree[i].get(l, r);
                tree[i].set(l, x, 0);
                tree[i].set(x, x + cnt, 1);
                tree[i].set(x + cnt, r, 0);
                x += cnt;
            }
        }
    }
    forn(i, 0, n) {
        forn(j, 0, S)
            if (tree[j].get(i, i + 1))
                cout << char('a' + j);
    }
}