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

void find_max(vector<vector<int>>& graph, vector<ll>& w_l, vector<ll>& w_r,
              vector<int>& p, vector<ll>& b_l, vector<ll>& b_r, int r) {
    b_l[r] = 0;
    b_r[r] = 0;
    for (auto u : graph[r]) {
        if (u != p[r]) {
            p[u] = r;
            find_max(graph, w_l, w_r, p, b_l, b_r, u);
            b_l[r] += max(max(w_l[r] - w_l[u], w_l[u] - w_l[r]) + b_l[u],
                          max(w_l[r] - w_r[u], w_r[u] - w_l[r]) + b_r[u]);
            b_r[r] += max(max(w_r[r] - w_l[u], w_l[u] - w_r[r]) + b_l[u],
                          max(w_r[r] - w_r[u], w_r[u] - w_r[r]) + b_r[u]);
            // cout << r << " " << u << " " << w_l[r] << " " << w_r[r] << " " << w_l[u] << " " << w_r[u] << " " << b_l[r] << " " << b_r[r] << " " << b_l[u] << " " << b_r[u] << "\n";
        }
    }
}


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
        vector<ll> w_l(n), w_r(n);
        for (int i = 0; i < n; i++) {
            cin >> w_l[i] >> w_r[i];
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<ll> b_l(n, 0), b_r(n, 0);
        vector<int> p(n, 0);
        find_max(graph, w_l, w_r, p, b_l, b_r, 0);
        cout << max(b_l[0], b_r[0]) << "\n";
    }
}