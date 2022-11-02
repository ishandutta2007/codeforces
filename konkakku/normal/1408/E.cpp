#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int m, n, a[N], b[N], k, u;
long long ans = 0;
vector<array<int, 3>> ed;

struct dsu {
    int dsu[N];

    void init() {
        fill(dsu + 1, dsu + N, -1);
    }

    int trace(int u) {
        return dsu[u] < 0 ? u : dsu[u] = trace(dsu[u]);
    }

    bool connect(int u, int v) {
        if ((u = trace(u)) == (v = trace(v))) {
            return false;
        }
        if (dsu[u] > dsu[v]) {
            swap(u, v);
        }
        dsu[u] += dsu[v];
        dsu[v] = u;
        return true;
    }
} dsu;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dsu.init();
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> u;
            ed.push_back({a[i] + b[u], i, u + m});
            ans += a[i] + b[u];
        }
    }
    sort(ed.begin(), ed.end(), greater<array<int, 3>>());
    for (auto [w, u, v] : ed) {
        if (dsu.connect(u, v)) {
            ans -= w;
        }
    }
    cout << ans;
}