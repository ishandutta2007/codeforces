#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<int> a(n);
    vector<vector<int>> xx(k);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        xx[a[i]].push_back(i);
    }
    vector<vector<int>> adj;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> x(n);
    vector<bool> visited(n, false);
    for (int K = 0; K < k; K++) {
        fill(visited.begin(), visited.end(), false);
        deque<pair<int, int>> pq;
        for (int i : xx[K]) {
            visited[i] = true;
            pq.push_back({0, i});
        }
        while (!pq.empty()) {
            auto [nw, cur] = pq.front();
            pq.pop_front();
            x[cur].push_back(-nw);
            for (int next : adj[cur]) {
                if (!visited[next]) {
                    visited[next] = true;
                    pq.push_back({nw-1, next});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        nth_element(x[i].begin(), x[i].begin() + s, x[i].end());
        long long r = 0;
        for (int j = 0; j < s; j++) {
            r += x[i][j];
        }
        cout << r << ' ';
    }
    cout << '\n';
}