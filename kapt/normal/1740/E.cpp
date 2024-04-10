#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
vector<int> g[MAXN];
int rk[MAXN], dp[MAXN];

void dfs(int v) {
    rk[v] = 1;
    int sum = 0;
    for (int u : g[v]) {
        dfs(u);
        rk[v] = max(rk[v], rk[u] + 1);
        sum += dp[u];
    }
    dp[v] = max(sum, rk[v]);
}

main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }
    dfs(0);
    cout << dp[0];
    return 0;
}