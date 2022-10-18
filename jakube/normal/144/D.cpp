#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int t, w;
};

vector<vector<Edge>> adj;

vector<bool> visited;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, s;
    cin >> n >> m >> s;

    adj.resize(n);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int l;
    cin >> l;

    visited.assign(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s-1});

    set<tuple<int, int, int, int>> se;

    vector<int> dist(n, numeric_limits<int>::max() - 1005);

    int cnt = 0;
    while (!pq.empty()) {
        int cur, w;
        tie(w, cur) = pq.top();
        pq.pop();

        if (visited[cur]) continue;
        visited[cur] = true;
        dist[cur] = w;

        if (w == l) cnt++;
        if (w >= l) continue;

        for (auto e : adj[cur]) {
            if (e.w + w > l) {
                if (cur < e.t) {
                    se.insert(make_tuple(cur, e.t, l - w, e.w));
                } else {
                    se.insert(make_tuple(e.t, cur, e.w + w - l, e.w));
                }
            }
            else if (!visited[e.t]) {
                pq.push({e.w + w, e.t});
            }
        }
    }

    for (auto e : se) {
        int u, v, w_p, w;
        tie(u, v, w_p, w) = e;

        int a = dist[u] + w_p;
        int b = dist[v] + w - w_p;
        if (min(a, b) == l) cnt++;
    }

    cout << cnt << endl;

    return 0;
}