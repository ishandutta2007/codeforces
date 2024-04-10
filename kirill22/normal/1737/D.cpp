#include "bits/stdc++.h"

using namespace std;

vector<long long> dijkstra(vector<vector<pair<int, long long>>>& g, int start) {
    int n = g.size();
    vector<long long> dist(n, 1e18);
    dist[start] = 0;
    set<pair<long long, int>> st;
    st.insert({0, start});
    while (st.size() > 0) {
        auto el = *st.begin();
        st.erase(el);
        int v = el.second, d = el.first;
        for (auto r : g[v]) {
            int x = r.first, d2 = r.second;
            if (d + d2 < dist[x]) {
                st.erase({dist[x], x});
                dist[x] = d + d2;
                st.insert({dist[x], x});
            }
        }
    }
    return dist;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int> (n, (int) 1e9));
    vector<vector<pair<int, long long>>> g2(n);
    vector<array<int, 3>> st;
    for (int i = 0; i < n; i++) g[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int v, u;
        long long w;
        cin >> v >> u >> w;
        v--, u--;
        g[v][u] = g[u][v] = 1;
        g2[v].push_back({u, 1});
        g2[u].push_back({v, 1});
        st.push_back({v, u, (int) w});
        st.push_back({u, v, (int) w});
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    auto A = dijkstra(g2, 0);
    auto B = dijkstra(g2, n - 1);
    long long ans = (long long) 1e18;
    vector<int> opt(n, (int) 1e9);
    for (int v = 0; v < n; v++) {
        for (int u = 0; u < n; u++) {
            opt[v] = min(opt[v], g[v][u] + g[u][0] + g[u][n - 1]);
        }
    }
    for (auto arr : st) {
        int v = arr[0], u = arr[1], w = arr[2];
        ans = min(ans, w * 1ll * (A[v] + 1 + B[u]));
        ans = min(ans, w * 1ll * (opt[v] + 2));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}