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

const ll MOD = 1000000007;

void bfs0(vector<vector<int>>& graph, vector<ll>& subtreesizes, vector<int>& p, int n, int r) {
    // cout << r << " UUU" << endl;
    for (auto u : graph[r]) {
        if (u != p[r]) {
            p[u] = r;
            bfs0(graph, subtreesizes, p, n, u);
            subtreesizes[r] += subtreesizes[u];
        }
    }
}

vector<ll> bfs(vector<vector<int>>& graph, int n) {
    vector<ll> subtreesizes(n, 1);
    vector<int> p(n, 0);
    // cout << "T" << endl;
    bfs0(graph, subtreesizes, p, n, 0);

    vector<ll> w(n - 1, 0);
    for (int i = 1; i < n; i++) {
        w[i - 1] = subtreesizes[i] * (n - subtreesizes[i]);
    }
    sort(w.begin(), w.end(), greater<ll>());
    return w;
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
        // cout << n << endl;
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }
        int m;
        cin >> m;
        // cout << m << endl;
        vector<ll> p(m);
        for (int i = 0; i < m; i++) {
            cin >> p[i];
        }
        sort(p.begin(), p.end(), greater<ll>());

        auto w = bfs(graph, n);
        // cout << "LOOO " << endl;
        ll cost = (ll) 0;
        if (m <= n - 1) {
            for (int i = 0; i < m; i++) {
                cost = (cost + p[i] * w[i]) % MOD;
            }

            for (int i = m; i < n - 1; i++) {
                cost = (cost + w[i]) % MOD;
            }

            cout << cost << "\n";
        } else {
            ll first = 1;
            for (int i = 0; i <= m - n + 1; i++) {
                first = (first * p[i]) % MOD;
            }
            cost = (w[0] * first) % MOD;
            for (int i = 1; i < n - 1; i++) {
                cost = (cost + w[i] * p[i + m - n + 1]) % MOD;
            }
            cout << cost << "\n";
        }
    }
}