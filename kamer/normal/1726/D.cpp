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
#include <complex>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<tuple<int, int>>> graph(n, vector<tuple<int, int>>());
        vector<tuple<int, int>> edges(m);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph[u].emplace_back(v, i);
            graph[v].emplace_back(u, i);
            edges[i] = { u, v };
        }

        string s(m, '0');
        vector<int> depth(n, 0);
        vector<bool> seen(n, false);
        seen[0] = true;
        vector<int> p_edge(n, -1);
        queue<int> bfs;
        bfs.push(0);
        while (!bfs.empty()) {
            int v = bfs.front();
            bfs.pop();
            for (auto [u, e] : graph[v]) {
                if (!seen[u]) {
                    seen[u] = true;
                    depth[u] = depth[v] + 1;
                    p_edge[u] = e;
                    s[e] = '1';
                    bfs.push(u);
                }
            }
        }

        if (m <= n + 1) {
            cout << s << "\n";
            continue;
        }

        int u = -1, v = -1, w = -1;
        int e1 = -1, e2 = -1, e3 = -1;
        bool done = false;
        for (int i = 0; i < m; i++) {
            if (s[i] == '0') {
                auto [t, ss] = edges[i];
                if (e1 == -1) {
                    e1 = i;
                    u = t;
                    v = ss;
                } else if (e2 == -1) {
                    e2 = i;
                    if (t == u) {
                        swap(u, v);
                        w = ss;
                    } else if (t == v) {
                        w = ss;
                    } else if (ss == u) {
                        swap(u, v);
                        w = t;
                    } else if (ss == v) {
                        w = t;
                    } else {
                        done = true;
                        break;
                    }
                } else {
                    e3 = i;
                    if (t != u) swap(t, ss);
                    if (t != u || ss != w) {
                        done = true;
                        break;
                    }
                }
            }
        }

        if (done) {
            cout << s << "\n";
            continue;
        }

        if (depth[u] < depth[v]) {
            swap(u, v);
            swap(e2, e3);
        }

        if (depth[u] < depth[w]) {
            swap(u, w);
            swap(e1, e2);
        }

        s[e1] = '1';
        s[p_edge[u]] = '0';
        cout << s << "\n";
    }
}