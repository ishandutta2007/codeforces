#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

struct Edge {
    int to, cost;
};

const int maxn = 2e5 + 10;

int n, m;
vector<Edge> graph[maxn];
int dist[maxn];


signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        c *= 2;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    set< pair<int, int> > q;
    for (int i = 1; i <= n; ++i) {
        cin >> dist[i];
        q.insert({dist[i], i});
    }
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto e: graph[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                q.erase({dist[e.to], e.to});
                dist[e.to] = dist[v] + e.cost;
                q.insert({dist[e.to], e.to});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << ' ';
    }



}