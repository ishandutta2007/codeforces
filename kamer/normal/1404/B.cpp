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

int bfs(int r, int& diam, vector<int>& p, vector<int>& dist, vector<vector<int>>& graph) {
    vector<int> depths;
    for (auto u : graph[r]) {
        if (u != p[r]) {
            p[u] = r;
            dist[u] = dist[r] + 1;
            depths.push_back(bfs(u, diam, p, dist, graph));
        }
    }

    int firstMax = 0, secondMax = 0;
    for (auto depth : depths) {
        if (depth >= firstMax) {
            secondMax = firstMax;
            firstMax = depth;
        } else if (depth > secondMax) {
            secondMax = depth;
        }
    }

    diam = max(diam, firstMax + secondMax + 1);
    return firstMax + 1;
}

void solve() {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--, b--;
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Jumps condition
    if (db <= 2 * da) {
        cout << "Alice\n";
        return;
    }

    vector<int> p(n, a);
    vector<int> dist(n, 0);
    int diam = 0;
    bfs(a, diam, p, dist, graph);

    // Initial distance condition
    if (dist[b] <= da) {
        cout << "Alice\n";
        return;
    }

    // Diameter condition
    if (diam <= 2 * da + 1) {
        cout << "Alice\n";
        return;
    }

    cout << "Bob\n";
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}