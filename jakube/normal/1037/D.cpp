#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> adj;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> order(n);
    for (auto& x : order) {
        cin >> x;
        x--;
    }

    
    bool valid = true;
    if (order[0] != 0) {
        valid = false;
    }

    queue<int> q;
    vector<bool> visited(n, false);
    visited[0] = true;
    q.push(0);

    int idx = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        set<int> nbs;
        for (int u : adj[v]) {
            if (visited[u]) continue;
            visited[u] = true;
            nbs.insert(u);
        }

        for (int i = idx; i < idx + (int)nbs.size(); i++) {
            if (!nbs.count(order[i]))
                valid = false;
            q.push(order[i]);
        }
        idx += nbs.size();
    }

    vector<int> all_(n, 0);
    iota(all_.begin(), all_.end(), 0);
    sort(order.begin(), order.end());
    if (order != all_)
        valid = false;

    cout << (valid ? "Yes" : "No") << endl;
}