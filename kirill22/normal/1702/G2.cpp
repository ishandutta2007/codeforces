#include<bits/stdc++.h>

using namespace std;

class LCA {
 public:
    int n, LG;
    vector<int> dist;
    vector<vector<int>> g, up;

    void dfs(int v, int pr, int d) {
        dist[v] = d;
        up[v].resize(LG);
        up[v][0] = pr;
        for (int j = 1; j < LG; j++) {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }
        for (auto x : g[v]) {
            if (x != pr) {
                dfs(x, v, d + 1);
            }
        }
    }

    LCA(vector<vector<int>>& _g, int st) {
        n = (int) _g.size();
        g = _g;
        LG = 0;
        while ((1ll << LG) <= n) LG++;
        up.resize(n);
        dist.resize(n);
        dfs(st, st, 0);
    }

    int lca(int x, int y) {
        if (dist[x] < dist[y]) swap(x, y);
        int z = dist[x] - dist[y];
        for (int j = 0; j < LG; j++) {
            if ((z & (1 << j)) > 0) {
                x = up[x][j];
            }
        }
        if (x == y) return x;
        for (int j = LG - 1; j >= 0; j--) {
            int X = up[x][j], Y = up[y][j];
            if (X != Y) {
                x = X, y = Y;
            }
        }
        return up[x][0];
    }
    int distance(int x, int y) {
        return dist[x] + dist[y] - 2 * dist[lca(x, y)];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i + 1 < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    LCA G(g, 0);
    int q;
    cin >> q;
    auto dist = G.dist;
    while (q--) {
        int k;
        cin >> k;
        vector<int> a(k);
        int v;
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            a[i]--;
            if (i == 0) {
                v = a[i];
            } else {
                v = G.lca(v, a[i]);
            }
        }
        sort(a.begin(), a.end(), [&] (int x, int y) { return dist[x] > dist[y]; });
        int u = a[0];
        vector<int> b;
        for (auto x : a) {
            if (G.lca(u, x) != x) {
                b.push_back(x);
            }
        }
        vector<int> c;
        if ((int) b.size()) {
            int u2 = u;
            sort(b.begin(), b.end(), [&] (int x, int y) { return dist[x] > dist[y]; });
            u = b[0];
            for (auto x : b) {
                if (G.lca(u, x) != x) {
                    c.push_back(x);
                }
            }
            if (G.lca(u, u2) != v) {
                c = {1};
            }
        }
        cout << ((int) c.size() > 0 ? "NO\n" : "YES\n");
    }
}