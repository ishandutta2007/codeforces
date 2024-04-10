#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

struct dsu {
    vector<int> v;
    dsu(int sz): v(sz, -1) {}
    int find(int x) {
        if (v[x] < 0)
            return x;
        return v[x] = find(v[x]);
    }
    int unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return 0;
        if (v[x] > v[y])
            swap(x, y);
        v[x] += v[y];
        v[y] = x;
        return 1;
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<int> x(d), y(d);
    for (int i = 0; i < d; ++i) {
        cin >> x[i] >> y[i];
        --x[i];
        --y[i];
    }
    for (int cnt = 1; cnt <= d; ++cnt) {
        dsu u(n);
        int extra = 0;
        for (int j = 0; j < cnt; ++j) {
            extra += 1 - u.unite(x[j], y[j]);
        }
        vector<int> sz;
        for (int j = 0; j < n; ++j) {
            if (u.v[j] < 0) {
                sz.push_back(-u.v[j]);
            }
        }
        sort(sz.rbegin(), sz.rend());
        int ans = 0;
        for (int i = 0; i < sz.size() && i <= extra; ++i) {
            ans += sz[i];
        }
        --ans;
        cout << ans << '\n';
    }
    
}