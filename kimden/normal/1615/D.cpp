#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

struct dsu {
    int sz;
    vector<int> p;
    vector<int> xr;
    dsu(int sz = 5): sz(sz), p(sz, -1), xr(sz, 0) {}
    int find(int x) {
        if (p[x] < 0) {
            return x;
        }
        int o = find(p[x]);
        xr[x] ^= xr[p[x]];
        p[x] = o;
        return o;
    }
    int unite(int x, int y, int z = 0) {
        int u = find(x);
        int v = find(y);
        z ^= xr[x] ^ xr[y];
        if (u == v) {
            return 0;
        }
        if (p[u] > p[v]) {
            swap(u, v);
        }
        p[u] += p[v];
        p[v] = u;
        xr[v] = z;
        return 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n - 1), b(n - 1), c(n - 1), e(q), f(q), g(q);
        dsu d(2 * n);
        for (int i = 0; i < n - 1; ++i) {
            cin >> a[i] >> b[i] >> c[i];
            --a[i];
            --b[i];
            if (c[i] != -1) {
                if (__builtin_popcount(c[i]) % 2 == 0) {
                    d.unite(a[i] * 2, b[i] * 2, c[i]);
                    d.unite(a[i] * 2 + 1, b[i] * 2 + 1, c[i]);
                } else {
                    d.unite(a[i] * 2 + 1, b[i] * 2, c[i]);
                    d.unite(a[i] * 2, b[i] * 2 + 1, c[i]);
                }
            }
        }
        for (int i = 0; i < q; ++i) {
            cin >> e[i] >> f[i] >> g[i];
            --e[i];
            --f[i];
            if (g[i] == 0) {
                d.unite(e[i] * 2, f[i] * 2, g[i]);
                d.unite(e[i] * 2 + 1, f[i] * 2 + 1, g[i]);
            } else {
                d.unite(e[i] * 2 + 1, f[i] * 2, g[i]);
                d.unite(e[i] * 2, f[i] * 2 + 1, g[i]);
            }
        }
        bool fail = false;
        for (int i = 0; i < n; ++i) {
            if (d.find(2 * i) == d.find(2 * i + 1)) {
                fail = true;
                break;
            }
        }
        if (fail) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 1; i < n; ++i) {
            if (d.find(0) != d.find(2 * i) && d.find(0) != d.find(2 * i + 1)) {
                d.unite(0, 2 * i, 0);
                d.unite(1, 2 * i + 1, 0);
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            int x = a[i];
            int y = b[i];
            cout << (x + 1) << " " << (y + 1) << " ";
            for (int j = 0; j < 2; ++j) {
                if (d.find(x * 2) == d.find(y * 2 + j)) {
                    cout << (d.xr[x * 2] ^ d.xr[y * 2 + j]) << "\n";
                    break;
                }
            }
        }
    }
    
    
}