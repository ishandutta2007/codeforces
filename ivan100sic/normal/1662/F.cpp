// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int inf = 1e9;

struct segtree {
    int maxn;
    vector<int> a;
    vector<multiset<int>> b;

    segtree(int n)  {
        maxn = 1;
        while (maxn < n)
            maxn <<= 1;
        a.assign(2*maxn, inf);
        b.resize(maxn);
    }

    void add(int p, int v) {
        b[p].insert(v);
        a[p + maxn] = *b[p].begin();
        p += maxn;
        for (p >>= 1; p; p >>= 1)
            a[p] = min(a[2*p], a[2*p+1]);
    }

    void rem(int p, int v) {
        b[p].erase(b[p].find(v));
        a[p + maxn] = b[p].size() ? *b[p].begin() : inf;
        p += maxn;
        for (p >>= 1; p; p >>= 1)
            a[p] = min(a[2*p], a[2*p+1]);
    }

    int get(int l, int r, int x, int xl, int xr) const {
        if (r <= xl || xr <= l)
            return inf;
        if (l <= xl && xr <= r)
            return a[x];
        int xm = (xl+xr) >> 1;
        return min(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm, xr));
    }

    int operator() (int l, int r) const {
        return get(l, r, 1, 0, maxn);
    }
};


int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        a--, b--;

        vector<int> p(n);
        for (int& x : p) cin >> x;

        vector<int> d(n, inf);
        d[a] = 0;

        while (1) {
            auto run = [&] {
                segtree st(n);
                vector<vector<pair<int, int>>> toe(n);
                for (int i : ra(0, n)) {
                    for (auto [key, val] : toe[i]) {
                        st.rem(key, val);
                    }

                    int z = min(d[i], st(i-p[i], i) + 1);

                    st.add(i, z);
                    d[i] = z;

                    int dest = i + p[i] + 1;
                    if (dest < n) {
                        toe[dest].emplace_back(i, z);
                    }
                }
            };
            
            auto old = d;
            run();
            R::reverse(d);
            R::reverse(p);
            run();
            R::reverse(d);
            R::reverse(p);
            
            if (d == old) {
                break;
            }
        }

        cout << d[b] << '\n';
    }
}