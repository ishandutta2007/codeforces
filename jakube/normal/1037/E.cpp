#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int k;
vector<vector<pair<int, int>>> adj;
vector<bool> deleted;
vector<int> nbs;
int val;

void f(int del_idx) {
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto [u, idx] : adj[v]) {
            if (deleted[u] || idx >= del_idx) continue;
            nbs[u]--;
            nbs[v]--;
            if (!deleted[u] && nbs[u] < k) {
                q.push(u);
                deleted[u] = true;
                val--;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m >> k;
    vector<pair<int, int>> edges(m);
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        edges[i] = {u, v};
    }

    nbs.assign(n, 0);
    for (auto [p, q] : edges) {
        nbs[p]++;
        nbs[q]++;
    }

    deleted.assign(n, false);
    val = n;
    for (int i = 0; i < n; i++) {
        if (!deleted[i] && nbs[i] < k) {
            q.push(i);
            deleted[i] = true;
            val--;
        }
    }

    f(m);
    vector<int> results;
    for (int i = m-1; i >= 0; i--) {
        results.push_back(val);
        auto [x, y] = edges[i];
        if (deleted[x] || deleted[y]) continue;
        nbs[x]--;
        nbs[y]--;
        if (nbs[x] < k) {
            q.push(x);
            deleted[x] = true;
            val--;
        }
        if (nbs[y] < k) {
            q.push(y);
            deleted[y] = true;
            val--;
        }
        f(i);
    }
    reverse(results.begin(), results.end());
    for (auto x : results) {
        cout << x << '\n';
    }
}