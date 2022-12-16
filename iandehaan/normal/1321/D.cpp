#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    vector<int> backadj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        backadj[v].push_back(u);
    }
    int k;
    cin >> k;
    int p[k];
    for (int i = 0; i < k; i++) cin >> p[i];

    int start = p[0];
    int end = p[k-1];

    int dist[n+1];
    for (int i = 1; i <= n; i++) {
        dist[i] = -1;
    }
    dist[end] = 0;
    queue<int> q;
    q.push(end);
    while (!q.empty()) {
        int top = q.front(); q.pop();
        for (int nxt : backadj[top]) {
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[top]+1;
            q.push(nxt);
        }
    }

    int mx = 0;
    int mn = 0;
    for (int i = 0; i < k-1; i++) {
        int bestDist = 1e9;
        int curr = p[i];
        for (int nxt : adj[curr]) {
            bestDist = min(bestDist, dist[nxt]);
        }

        if (bestDist == dist[p[i+1]]) {
            for (int nxt : adj[curr]) {
                if (dist[nxt] == bestDist && nxt != p[i+1]) {
                    mx++;
                    break;
                }
            }
        } else {
            mn++;
            mx++;
        }
    }
    cout << mn << ' ' << mx << endl;
}