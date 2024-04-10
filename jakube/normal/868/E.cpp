#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> leaves;
vector<int> ga;

int dfs(int v, int p) {
    if (adj[v].size() == 1)
        leaves.push_back(v);

    int g = std::count(ga.begin(), ga.end(), v+1);
    for (int u : adj[v]) {
        if (u != p) 
            g += dfs(u, v);
    }
    return g;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    adj.resize(n);
    map<pair<int, int>, int> weight;
    vector<vector<int>> cost(n, vector<int>(n, numeric_limits<int>::max() / 3));
    for (int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u][v] = w;
        cost[v][u] = w;
        weight[{u, v}] = w;
        weight[{v, u}] = w;
    }

    int s;
    cin >> s;
    int m;
    cin >> m;
    ga.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> ga[i];
    }

    vector<int> leaf_nodes;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1)
            leaf_nodes.push_back(i);
    }

    for (int i = 0; i < n; i++) cost[i][i] = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    vector<vector<int>> dp(m+1, vector<int>(n, 0));
    for (int M = 1; M <= m; M++) {
        for (int node : leaf_nodes) {
            int L = 0; // L is possible
            int R = numeric_limits<int>::max() / 3;
            while (L + 1 < R) {
                int MM = (L + R) / 2;
                // is cost MM possible?
                int c = M;
                for (int next : leaf_nodes) {
                    int possible = 0;
                    while (possible < c && MM <= cost[node][next] + dp[M - possible - 1][next])
                        possible++;
                    c -= possible;
                }
                if (c == 0) {
                    L = MM;
                } else {
                    R = MM;
                }
            }
            dp[M][node] = L;
        }
    }

    s--;
    if (adj[s].size() == 1) {
        cout << dp[m][s] << endl;
        return 0;
    }

    int lowest = numeric_limits<int>::max();
    for (int next : adj[s]) {
        leaves.clear();
        int g = dfs(next, s);

        int L = 0;
        int R = numeric_limits<int>::max() / 3;
        while (L + 1 < R) {
            int MM = (L + R) / 2;
            // is cost MM possible?
            int c = g;
            for (int next : leaves) {
                int possible = 0;
                while (possible < c && MM <= cost[s][next] + dp[m - possible - 1][next])
                    possible++;
                c -= possible;
            }
            if (c == 0) {
                L = MM;
            } else {
                R = MM;
            }
        }
        lowest = min(lowest, L);
    }

    cout << lowest << endl;
}