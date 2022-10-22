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

ll dfs(int root, const vector<vector<int>>& graph, const vector<int>& p, const vector<tuple<ll, ll>>& bounds, int& ops) {
    
    bool has_child = false;
    ll sum_r = 0;
    for (auto v : graph[root]) {
        if (p[root] == v) {
            continue;
        }

        has_child = true;
        sum_r += dfs(v, graph, p, bounds, ops);
    }

    auto [l, r] = bounds[root];

    if (!has_child) {
        ops++;
        return r;
    }

    if (sum_r < l) {
        ops++;
        return r;
    }

    return min(sum_r, r);
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
        vector<tuple<ll, ll>> bounds(n);
        vector<int> p(n, 0);

        for (int i = 1; i < n; i++) {
            int p_i;
            cin >> p_i;
            graph[i].push_back(p_i - 1);
            graph[p_i - 1].push_back(i);
            p[i] = p_i - 1;
        }

        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            bounds[i] = { l, r };
        }

        int ops = 0;
        dfs(0, graph, p, bounds, ops);
        cout << ops << "\n";
    }
}