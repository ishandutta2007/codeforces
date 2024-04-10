#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n), g2(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        g[x].push_back({y, w});
        g2[y].push_back({x, w});
    }
    vector<long long> dist(n, (long long) 1e18);
    dist[0] = 0;
    set<pair<long long, int>> st = {{0, 0}};
    while (!st.empty()) {
        int v = (*st.begin()).second;
        st.erase(st.begin());
        for (auto [u, w] : g[v]) {
            if (dist[u] > dist[v] + w) {
                st.erase({dist[u], u});
                dist[u] = dist[v] + w;
                st.insert({dist[u], u});
            }
        }
    }
    auto ans = dist;
    for (int i = 0; i < n; i++) {
        st.insert({ans[i], i});
    }
    while (!st.empty()) {
        int v = (*st.begin()).second;
        st.erase(st.begin());
        for (auto [u, w] : g2[v]) {
            if (ans[u] > ans[v] + w) {
                st.erase({ans[u], u});
                ans[u] = ans[v] + w;
                st.insert({ans[u], u});
            }
        }
    }
    for (int i = 1; i < n; i++) {
        cout << (ans[i] == (long long) 1e18 ? -1 : ans[i]) << " ";
    }
}