#include "bits/stdc++.h"
using namespace std;

int cnt[2];
vector<vector<int>> adj;

void dfs(int v, int p, int color) {
    cnt[color]++;
    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v, 1 ^ color);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1, 0);
    cout << min(cnt[0], cnt[1]) - 1 << '\n';
}