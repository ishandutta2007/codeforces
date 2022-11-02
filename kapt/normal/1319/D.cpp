#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5;
vector<int> g[MAXN], e[MAXN];
int cnt[MAXN], d[MAXN];
int p[MAXN];

void bfs(int v) {
    deque<int> q;
    q.push_back(v);
    d[v] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto u : e[v]) {
            if (d[u] > d[v] + 1) {
                d[u] = d[v] + 1;
                q.push_back(u);
            }
        }
    }
}

main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        e[v].push_back(u);
    }
    fill(d, d + n, 1e9);
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> p[i];
        p[i]--;
    }
    bfs(p[k - 1]);
    for (int i = 0; i < n; ++i) {
        for (auto u : g[i]) {
            if (d[i] - d[u] == 1) {
                cnt[i]++;
            }
        }
    }
    int mn = 0, mx = 0;
    for (int i = 1; i < k; ++i) {
        if (d[p[i - 1]] - d[p[i]] != 1) {
            mn++;
            mx++;
        } else if (cnt[p[i - 1]] >= 2) {
            mx++;
        }
    }
    cout << mn << " " << mx;
    return 0;
}