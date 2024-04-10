#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long k, x;
vector<vector<vector<long long>>> dp;
// type = 0: < k
// type = 1: = k
// type = 2: > k

vector<vector<int>> adj;

int MOD = 1e9+7;

void dfs(int v, int p) {
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }

    {
        // type 1: = k
        vector<long long> node_dp(x+1, 0);
        node_dp[0] = 1;
        for (int u : adj[v]) {
            if (u == p) continue;
            vector<long long> tmp(x+1, 0);
            for (int i = 0; i <= x; i++) {
                for (int j = 0; j <= i; j++) {
                    tmp[i] += (node_dp[j] * dp[u][0][i - j]) % MOD;
                }
            }

            for (int i = 0; i <= x; i++)
                node_dp[i] = tmp[i] % MOD;
        }
        dp[v][1][0] = 0;
        for (int i = 1; i <= x; i++)
            dp[v][1][i] = node_dp[i-1];
    }

    {
        // type 2: > k
        vector<long long> node_dp(x+1, 0);
        node_dp[0] = 1;
        for (int u : adj[v]) {
            if (u == p) continue;
            vector<long long> tmp(x+1, 0);
            for (int i = 0; i <= x; i++) {
                for (int j = 0; j <= i; j++) {
                    tmp[i] += (node_dp[j] * (dp[u][0][i - j] + dp[u][2][i - j])) % MOD;
                }
            }

            for (int i = 0; i <= x; i++)
                node_dp[i] = tmp[i] % MOD;
        }
        for (int i = 0; i <= x; i++)
            dp[v][2][i] = (node_dp[i] * (m - k)) % MOD;
    }

    {
        // type 0: < k
        vector<long long> node_dp(x+1, 0);
        node_dp[0] = 1;
        for (int u : adj[v]) {
            if (u == p) continue;
            vector<long long> tmp(x+1, 0);
            for (int i = 0; i <= x; i++) {
                for (int j = 0; j <= i; j++) {
                    tmp[i] += (node_dp[j] * (dp[u][0][i - j] + dp[u][1][i - j] + dp[u][2][i - j])) % MOD;
                }
            }

            for (int i = 0; i <= x; i++)
                node_dp[i] = tmp[i] % MOD;
        }
        for (int i = 0; i <= x; i++)
            dp[v][0][i] = (node_dp[i] * (k - 1)) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> k >> x;
    dp.assign(n, vector<vector<long long>>(3, vector<long long>(x + 1, 0)));

    dfs(0, -1);
    long long result = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= x; j++) {
            result += dp[0][i][j];
        }
    }
    cout << (result % MOD) << endl;
}