#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    
    int n, m;
    ll x;
    cin >> n >> m >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<tuple<int, int>>> graph(n, vector<tuple<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].emplace_back(v, i + 1);
        graph[v].emplace_back(u, i + 1);
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];

    if (sum < (ll) (n - 1) * (ll) x) {
        cout << "NO\n";
        return 0;
    } else {
        cout << "YES\n";
    }


    vector<int> p(n, 0);
    vector<int> p_edge(n, 0);
    vector<int> ordered_tree;
    vector<bool> vis(n, false);
    queue<int> bfs;
    bfs.push(0);
    vis[0] = true;

    while (!bfs.empty()) {
        int u = bfs.front();
        ordered_tree.push_back(u);
        bfs.pop();
        for (auto [v, e] : graph[u]) {
            if (!vis[v]) {
                p[v] = u;
                p_edge[v] = e;
                vis[v] = true;
                bfs.push(v);
            }
        }
    }

    deque<int> edges_front, edges_back;
    for (int i = n - 1; i > 0; i--) {
        int v = ordered_tree[i];
        if (a[v] + a[p[v]] >= x) {
            edges_front.push_back(p_edge[v]);
            a[p[v]] = a[v] + a[p[v]] - x;
        } else {
            edges_back.push_front(p_edge[v]);
        }
    }

    for (auto e : edges_front) {
        cout << e << "\n";
    }

    for (auto e : edges_back) {
        cout << e << "\n";
    }
}