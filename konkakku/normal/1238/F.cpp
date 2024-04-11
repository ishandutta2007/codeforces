#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, u, v, q, ans, f[N];
vector<int> adj[N];

void DFS(int u, int p = 0) {
    int fi = 0, se = 0;
    for (int &v : adj[u]) {
        if (v != p) {
            DFS(v, u);
            if (f[v] > fi) {
                se = fi;
                fi = f[v];
            } else if (f[v] > se) {
                se = f[v];
            }
        }
    }
    if (fi > 0) { // not leaf 
        ans = max(ans, fi + (int)adj[u].size());
        f[u] = fi + (int)adj[u].size() - 1;
    } else {
        f[u] = 1;
    }
    if (se > 0) { // two paths
        ans = max(ans, fi + se + (int)adj[u].size() - 1);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = 0;
    DFS(1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--) {
        solve();
    }
}