#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

bool dfs(int v) {
    int cnt = 0;
    for (auto u : adj[v]) {
        if (adj[u].empty())
            cnt++;
    }
    if (adj[v].size() && cnt < 3)
        return false;

    for (auto u : adj[v]) {
        if (!dfs(u))
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> children(n, 0);
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int p;
        cin >> p;
        adj[p - 1].push_back(i + 1);
    }
    
    cout << (dfs(0) ? "Yes" : "No") << '\n';
}