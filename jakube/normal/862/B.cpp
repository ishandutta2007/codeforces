#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

int dfs(int v, int p=-1, int color = 0) {
    int cnt = color;
    for (auto u : adj[v]) {
        if (u == p)
            continue;
        cnt += dfs(u, v, color^1);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long long l = dfs(0);
    long long r = n - l; 
    cout << l * r - n + 1 << '\n';
}