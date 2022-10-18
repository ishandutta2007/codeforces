#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> child;
vector<vector<long long>> dp;
vector<int> color;

int MOD = 1e9 + 7;

void dfs(int node) {
    if (color[node] == 1) {
        dp[node][0] = 0;
        dp[node][1] = 1;
    } else {
        dp[node][0] = 1;
        dp[node][1] = 0;
    }

    for (int next : child[node]) {
        dfs(next);
        if (color[node] == 1) {
            dp[node][1] = (dp[node][1] * ((dp[next][0] + dp[next][1]) % MOD)) % MOD;
        } else {
            dp[node][1] = (dp[node][1] * ((dp[next][0] + dp[next][1]) % MOD)) % MOD;
            dp[node][1] = (dp[node][1] + ((dp[node][0] * dp[next][1]) % MOD)) % MOD;

            dp[node][0] = (dp[node][0] * ((dp[next][0] + dp[next][1]) % MOD)) % MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    vector<int> par(n-1);
    for (int idx = 0; idx < n-1; idx++)
        cin >> par[idx];
    child.resize(n);

    for (int i = 0; i < n-1; i++) {
        child[par[i]].push_back(i+1);
    }

    color.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }

    dp.assign(n, vector<long long>(2, 0));
    dfs(0);

    cout << dp[0][1] << endl;
    return 0;
}