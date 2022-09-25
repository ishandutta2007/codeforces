#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1), S(n + 1);
    for (int i = 0, u, v; i < m; i += 1) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> par(n + 1), dep(n + 1), w(n + 1), d(n + 1);
    function<void(int)> DFS = [&](int u) {
        for (int v : G[u]) if (not par[v]) {
            par[v] = u;
            dep[v] = dep[u] + 1;
            DFS(v);
        }
    };
    par[1] = -1;
    DFS(1);
    //for (int i = 1; i <= n; i += 1) cout << par[i] << " "; cout << endl;
    int q;
    vector<vector<int>> paths;
    for (cin >> q; q; q -= 1) {
        int a, b;
        cin >> a >> b;
        int pa = a, pb = b;
        while (pa != pb) {
            if (dep[pa] < dep[pb]) swap(pa, pb);
            w[pa] ^= 1;
            pa = par[pa];
        }
        vector<int> path;
        for (int p = a; p != pa; p = par[p]) path.push_back(p);
        path.push_back(pa);
        int t = path.size();
        for (int p = b; p != pb; p = par[p]) path.push_back(p);
        reverse(path.begin() + t, path.end());
        paths.push_back(path);
    }
    int ok = 1;
    for (int i = 1; i <= n; i += 1) if (w[i]) ok = 0;
    if (ok) {
        cout << "YES\n";
        for (auto p : paths) {
            cout << p.size() << "\n";
            for (int x : p) cout << x << " ";
            cout << "\n";
        }
    }
    else {
        int ans = 0;
        for (int i = 2; i <= n; i += 1)
            if (w[i]) {
                d[i] ^= 1;
                d[par[i]] ^= 1;
            }
        for (int i = 1; i <= n; i += 1) ans += d[i];
        cout << "NO\n" << ans / 2;
    }
    return 0;
}