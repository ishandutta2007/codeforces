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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> graph(n, vector<int>());
        vector<int> deg(n, 0);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
            deg[u]++, deg[v]++;
        }

        vector<int> p(n, 0);
        queue<int> bfs;
        bfs.push(0);
        while (!bfs.empty()) {
            int v = bfs.front();
            bfs.pop();
            for (auto u : graph[v]) {
                if (u != p[v]) {
                    bfs.push(u);
                    p[u] = v;
                }
            }
        }

        vector<int> bad_deg(n, 0);
        for (int v = 1; v < n; v++) {
            if (deg[v] == 1) {
                bad_deg[v] = -1;
                continue;
            }

            for (auto u : graph[v]) {
                if (u != p[v]) {
                    if (deg[u] != 1) bad_deg[v]++;
                }
            }
        }

        queue<int> buds;
        for (int v = 1; v < n; v++) {
            if (bad_deg[v] == 0) buds.push(v);
        }

        while (!buds.empty()) {
            int v = buds.front();
            buds.pop();

            if (p[v] != 0) {
                deg[p[v]]--;
                bad_deg[p[v]]--;
                if (bad_deg[p[v]] == 0) {
                    if (deg[p[v]] == 1) {
                        if (p[p[v]] != 0) buds.push(p[p[v]]);
                    } else {
                        buds.push(p[v]);
                    }
                }

                p[v] = 0;
            }
        }

        vector<int> new_deg(n, 0);
        for (int v = 1; v < n; v++) {
            // cout << "U " << v + 1 << " " << deg[v] << "\n";
            if (deg[v] == 1) {
                new_deg[p[v]]++;
            }
        }

        int count_non_terminal = 0;
        int count_terminal = 0;
        for (int v = 0; v < n; v++) {
            // cout << "T " << v + 1 << " " << new_deg[v] << " " << p[v] + 1 << "\n";
            if (new_deg[v] > 0) count_non_terminal++;
            else if (v > 0) count_terminal++;
        }

        cout << count_terminal - count_non_terminal + 1 << "\n";
    }
}