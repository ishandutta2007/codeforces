#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d(n);
    auto bfs = [&](int u) {
        queue<int> que;
        fill(d.begin(), d.end(), -1);
        d[u] = g[u].size() - 1;
        que.push(u);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int v : g[u])
                if (d[v] == -1) {
                    d[v] = d[u] + g[v].size() - 1;
                    que.push(v);
                }
        }
        return max_element(d.begin(), d.end()) - d.begin();
    };
    int u = bfs(0);
    int v = bfs(u);
    cout << d[v] + 2 << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}