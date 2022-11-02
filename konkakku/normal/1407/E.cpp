#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int n, m, u, v, x, dst[N], ans[N];
bool chk[N];
vector<pair<int, int>> adj[N];

void BFS() {
    fill(dst + 1, dst + n + 1, -1);
    queue<int> q;
    for (dst[n] = 0, q.push(n); !q.empty(); q.pop()) {
        int u = q.front();
        for (auto [v, x] : adj[u]) {
            if (v == u) {
                continue;
            }
            if (chk[v] && ans[v] == x) {
                if (dst[v] == -1) {
                    dst[v] = dst[u] + 1;
                    q.push(v);
                }
            } else {
                chk[v] = true;
                ans[v] = x ^ 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> x;
        adj[v].push_back({u, x});
    }
    BFS();
    cout << dst[1] << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
}