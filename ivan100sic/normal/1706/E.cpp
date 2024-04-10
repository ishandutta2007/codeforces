// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T = int, class F = plus<T>>
struct sparse_table {
    vector<vector<T>> d;
    T e;
    F f;

    sparse_table(vector<T> a, T e = T(), F f = F()) : e(e), f(f) {
        d.push_back(a);
        int n = a.size();
        for (int h=1; h*2<=n; h<<=1) {
            int m = a.size() - h;
            vector<T> b(m);
            for (int i=0; i<m; i++)
                b[i] = f(a[i], a[i+h]);
            d.push_back(b);
            swap(a, b);
        }
    }

    T operator() (int l, int r) const {
        if (l >= r) return e;
        int i = 31 - __builtin_clz(r-l);
        return f(d[i][l], d[i][r-(1<<i)]);
    }
};

template<class T = int>
struct maxval {
    T x;
    maxval(T x = numeric_limits<T>::min()) : x(x) {}
    T operator() () const { return x; }
    maxval operator+ (const maxval& b) const { return max(x, b.x); }
    maxval& operator+= (const maxval& b) { x = max(x, b.x); return *this; }
};

using mvi = maxval<int>;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<list<int>> e(n);
        vector<int> col(n);

        for (int i : ra(0, n)) {
            e[i] = {i};
            col[i] = i;
        }

        vector<mvi> g(n-1);

        auto recolor = [&](int x, int c, int tick) {
            col[x] = c;
            if (x > 0 && col[x] == col[x-1] && g[x-1]() < 0) g[x-1] = {tick};
            if (x+1 < n && col[x] == col[x+1] && g[x]() < 0) g[x] = {tick};
        };

        for (int i : ra(0, m)) {
            int x, y;
            cin >> x >> y;
            x--, y--;

            int cx = col[x];
            int cy = col[y];
            if (cx == cy) continue;

            if (e[cx].size() > e[cy].size()) {
                swap(x, y);
                swap(cx, cy);
            }

            for (int u : e[cx]) {
                recolor(u, cy, i+1);
            }
            e[cy].splice(e[cy].end(), e[cx]);
        }

        sparse_table<maxval<int>> st(g);

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            if (l == r) {
                cout << "0 ";
                continue;
            }

            cout << st(l, r)() << " ";
        }
        cout << '\n';
    }
}