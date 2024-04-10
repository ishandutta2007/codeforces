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

struct FenwickTree {
    vector<ll> bit;
    int n;

    FenwickTree () {};
    FenwickTree (int _n) {
        n = _n;
        bit.resize(n);
    }

    ll get(int r) {
        ll ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ans += bit[r];
        return ans;
    }

    void add(int pos, int val) {
        for (; pos < n; pos |= (pos + 1))
            bit[pos] += val;
    }
};

const int N = 1 << 17;
FenwickTree T[2 * N];
vector<int> ys[2 * N];

void fakeAdd(int x, int y) {
    x += N;
    while (x) {
        ys[x].eb(y);
        x /= 2;
    }
}

void prepare() {
    forn(i, 1, 2 * N) {
        sort(all(ys[i]));
        ys[i].resize(unique(all(ys[i])) - ys[i].begin());
        T[i] = FenwickTree(ys[i].size());
    }
}

ll _get(int x, int yl, int yr) {
    int posl = lower_bound(all(ys[x]), yl) - ys[x].begin();
    int posr = lower_bound(all(ys[x]), yr) - ys[x].begin();
    return T[x].get(posr - 1) - T[x].get(posl - 1);
}

ll get(int xl, int xr, int yl, int yr) {
    ll ans = 0;
    xl += N, xr += N;
    while (xl < xr) {
        if (xl % 2)
            ans += _get(xl++, yl, yr);
        if (xr % 2)
            ans += _get(--xr, yl, yr);
        xl /= 2;
        xr /= 2;
    }
    return ans;
}

void _add(int x, int y, int val) {
    int pos = lower_bound(all(ys[x]), y) - ys[x].begin();
    assert(ys[x][pos] == y);
    T[x].add(pos, val);
}

void add(int x, int y, int val) {
    x += N;
    while (x) {
        _add(x, y, val);
        x /= 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    forn(i, 0, n) {
        cin >> a[i];
        --a[i];
    }
    vector<int> t(m), x(m), y(m);
    forn(i, 0, m) {
        cin >> t[i] >> x[i] >> y[i];
        --t[i], --x[i];
        if (t[i] == 0) --y[i];
    }
    vector<int> _a = a;
    vector<set<int>> colors(n);
    forn(i, 0, n) colors[a[i]].insert(i);
    forn(i, 0, n) {
        int prv = -1;
        for (int p : colors[i]) {
            if (prv != -1) fakeAdd(p, prv);
            prv = p;
        }
    }
    forn(i, 0, m) if (t[i] == 0) {
        int pos = x[i], col = y[i], oldcol = a[pos];
        if (oldcol == col) continue;
        colors[oldcol].erase(pos);
        auto it2 = colors[oldcol].lower_bound(pos);
        if (it2 != colors[oldcol].end()) {
            fakeAdd(*it2, pos);
        }
        if (it2 != colors[oldcol].begin()) {
            auto it1 = it2;
            --it1;
            fakeAdd(pos, *it1);
            if (it2 != colors[oldcol].end())
                fakeAdd(*it2, *it1);
        }

        it2 = colors[col].lower_bound(pos);
        if (it2 != colors[col].end()) {
            fakeAdd(*it2, pos);
        }
        if (it2 != colors[col].begin()) {
            auto it1 = it2;
            --it1;
            fakeAdd(pos, *it1);
            if (it2 != colors[col].end())
                fakeAdd(*it2, *it1);
        }
        colors[col].insert(pos);
        a[pos] = col;
    }
    prepare();
    forn(i, 0, n) colors[i].clear();
    a = _a;
    forn(i, 0, n) colors[a[i]].insert(i);
    forn(i, 0, n) {
        int prv = -1;
        for (int p : colors[i]) {
            if (prv != -1) add(p, prv, p - prv);
            prv = p;
        }
    }
    forn(i, 0, m) {
        if (t[i]) {
            cout << get(x[i], y[i], x[i], y[i]) << '\n';
        } else {
            int pos = x[i], col = y[i], oldcol = a[pos];
            if (oldcol == col) continue;
            colors[oldcol].erase(pos);
            auto it2 = colors[oldcol].lower_bound(pos);
            if (it2 != colors[oldcol].end()) {
                add(*it2, pos, pos - *it2);
            }
            if (it2 != colors[oldcol].begin()) {
                auto it1 = it2;
                --it1;
                add(pos, *it1, *it1 - pos);
                if (it2 != colors[oldcol].end())
                    add(*it2, *it1, *it2 - *it1);
            }

            it2 = colors[col].lower_bound(pos);
            if (it2 != colors[col].end()) {
                add(*it2, pos, *it2 - pos);
            }
            if (it2 != colors[col].begin()) {
                auto it1 = it2;
                --it1;
                add(pos, *it1, pos - *it1);
                if (it2 != colors[col].end())
                    add(*it2, *it1, *it1 - *it2);
            }
            colors[col].insert(pos);
            a[pos] = col;
        }
    }
}