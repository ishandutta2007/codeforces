#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n) - 1; i >= (int)(a); --i)
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

template<typename T, typename S>
istream& operator>> (istream& in, pair<S, T>& p) {
    in >> p.fs >> p.sn;
    return in;
}
template<typename T, typename S>
ostream& operator<< (ostream& out, pair<S, T>& p) {
    out << p.fs << ' ' << p.sn << ' ';
    return out;
}

template<typename T>
istream& operator>> (istream& in, vector<T>& v) {
    for (T& x : v) in >> x;
    return in;
}
template<typename T>
ostream& operator<< (ostream& out, vector<T>& v) {
    for (T& x : v) out << x << ' ';
    return out;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 998244353;

const int N = 2e5 + 10;

struct Vertex {
    ll val, toAdd, toMult;
    int lc, rc;

    Vertex() {
        val = 0;
        toAdd = 0;
        toMult = 1;
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

    void _push(Vertex& from, Vertex& to) {
        to.toMult *= from.toMult;
        to.toMult %= MOD;

        to.toAdd *= from.toMult;
        to.toAdd += from.toAdd;
        to.toAdd %= MOD;
    }

    void push(int i, int sz) {
        if (a[i].lc != -1) _push(a[i], a[a[i].lc]);
        if (a[i].rc != -1) _push(a[i], a[a[i].rc]);

        a[i].val *= a[i].toMult;
        a[i].val += a[i].toAdd * sz;
        a[i].val %= MOD;

        a[i].toMult = 1;
        a[i].toAdd = 0;
    }

    void relax(int i, int lb, int rb) {
        if (a[i].lc == -1) return;
        int mid = (lb + rb) / 2;
        push(a[i].lc, mid - lb);
        push(a[i].rc, rb - mid);
        a[i].val = a[a[i].lc].val + a[a[i].rc].val;
        if (a[i].val >= MOD) a[i].val -= MOD;
    }

    ll _get(int i, int l, int r, int lb, int rb) {
        push(i, rb - lb);
        l = max(l, lb);
        r = min(r, rb);
        if (l >= r) return 0;
        if (l == lb && r == rb)
            return a[i].val;
        int mid = (lb + rb) / 2;
        ll rez =  _get(a[i].lc, l, r, lb, mid)
            + _get(a[i].rc, l, r, mid, rb);
        if (rez >= MOD) rez -= MOD;
        relax(i, lb, rb);
        return rez;
    }

    ll get(int l, int r) {
        return _get(0, l, r, 0, n);
    }

    void _mult(int i, int l, int r, int lb, int rb) {
        push(i, rb - lb);
        l = max(l, lb);
        r = min(r, rb);
        if (l >= r) return;
        if (l == lb && r == rb) {
            a[i].toMult *= 2;
            if (a[i].toMult >= MOD)
                a[i].toMult -= MOD;
            return;
        }
        int mid = (lb + rb) / 2;
        _mult(a[i].lc, l, r, lb, mid);
        _mult(a[i].rc, l, r, mid, rb);
        relax(i, lb, rb);
    }

    void mult(int l, int r) {
        //cerr << "mult: " << l << ' ' << r << '\n';
        _mult(0, l, r, 0, n);
    }

    void _add(int i, int l, int r, int lb, int rb) {
        push(i, rb - lb);
        l = max(l, lb);
        r = min(r, rb);
        if (l >= r) return;
        if (l == lb && r == rb) {
            a[i].toAdd += 1;
            if (a[i].toAdd == MOD)
                a[i].toAdd = 0;
            return;
        }
        int mid = (lb + rb) / 2;
        _add(a[i].lc, l, r, lb, mid);
        _add(a[i].rc, l, r, mid, rb);
        relax(i, lb, rb);
    }

    void add(int l, int r) {
        //cerr << "add: " << l << ' ' << r << '\n';
        _add(0, l, r, 0, n);
    }
};
Vertex a[2 * N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, q;
    cin >> n >> q;
    SegmentTreeTopDown tree(n, a);
    vector<set<pair<int, int>>> segs(n);
    while (q--) {
        int t;

        cin >> t;

        //t = 1 + rand() % 2;


        if (t == 1) {
            int l, r, x;

            cin >> l >> r >> x;
            --l, --x;

            //l = rand() % n;
            //r = rand() % n;
            //x = rand() % n;
            //if (l > r) swap(l, r);

            int l1 = l, r1 = r;
            vector<pair<int, int>> used;
            while (1) {
                auto it = segs[x].lower_bound({r, -1});
                if (it == segs[x].begin()) break;
                --it;
                if (it->sn < l) break;
                setmin(l1, it->fs);
                setmax(r1, it->sn);
                used.eb(*it);
                segs[x].erase(it);
            }
            segs[x].emplace(l1, r1);
            if (used.empty()) {
                tree.add(l, r);
                continue;
            }
            reverse(all(used));
            int sz = (int)used.size();
            for (auto& [_l, _r] : used) {
                tree.mult(max(_l, l), min(_r, r));
            }
            if (used[0].fs > l)
                tree.add(l, used[0].fs);
            forn(i, 1, sz)
                tree.add(used[i - 1].sn, used[i].fs);
            if (used.back().sn < r)
                tree.add(used.back().sn, r);
        } else {
            int l, r;

            cin >> l >> r;

            //l = rand() % n, r = rand() % n;
            //if (l > r) swap(l, r);
            //++l;

            cout << tree.get(--l, r) << '\n';
        }
    }
}