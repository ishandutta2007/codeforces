#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, u, v, x, z, te, par[N];
vector<int> adj[N];

pair<int, int> DFS(int u, int p = 0) {
    par[u] = p;
    int lea = u, sz = 1;
    for (int v : adj[u]) {
        if (v != p) {
            auto [l, s] = DFS(v, u);
            lea = l; sz += s;
        }
    }
    if (2 * sz == n) {
        x = p; z = lea;
    }
    return {lea, sz};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> te;
    while (te--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        x = z = 0;
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        DFS(1);
        if (x == 0) {
            cout << u << " " << v << '\n' << u << " " << v << '\n';
        } else {
            cout << z << " " << par[z] << '\n' << x << " " << z << '\n';
        }
    }
}