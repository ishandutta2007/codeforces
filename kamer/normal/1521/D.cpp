#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int bfs(int v, vector<vector<int>>& graph, vector<int>& p, vector<tuple<int, int>>& bad_edges, vector<tuple<int, int>>& bamboo_edges, bool push_down) {
    int down_count = 0;
    int first_endpoint = -1;
    bool next_push_down = true;
    for (auto u : graph[v]) {
        if (u != p[v]) {
            p[u] = v;
            int u_res = bfs(u, graph, p, bad_edges, bamboo_edges, next_push_down);
            if (u_res == -1 || !next_push_down) {
                bad_edges.emplace_back(v, u);
            } else if (u_res != -1 && down_count <= 1) {
                down_count++;
                if (down_count == 1) {
                    first_endpoint = u_res;
                } else {
                    next_push_down = false;
                    bamboo_edges.emplace_back(first_endpoint, u_res);
                    first_endpoint = -1;
                }
            }
        }
    }

    if (push_down) {
        if (first_endpoint == -1 && next_push_down) {
            return v;
        } else {
            return first_endpoint;
        }
    } else {
        if (first_endpoint == -1 && next_push_down) {
            bamboo_edges.emplace_back(v, v);
        } else if (first_endpoint != -1) {
            bamboo_edges.emplace_back(first_endpoint, v);
        }
        return -1;
    }

}

void solve(void) {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<tuple<int, int>> bad_edges;
    vector<tuple<int, int>> bamboo_edges;
    vector<int> p(n, 0);

    bfs(0, graph, p, bad_edges, bamboo_edges, false);

    cout << bad_edges.size() << "\n";
    for (int i = 0; i < bad_edges.size(); i++) {
        auto [bx, by] = bad_edges[i];
        auto [b1x, b1y] = bamboo_edges[i];
        auto [b2x, b2y] = bamboo_edges[i + 1];
        cout << bx + 1 << " " << by + 1 << " " << b1y + 1 << " " << b2x + 1 << "\n";
    }
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