#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 22;
int n, cost[N], id[N];
vector<int> g[N];
vector<int> dp[N];
multiset<int> dp2[N];

void dfs(int v) {
    if ((int) g[v].size() == 0) {
        id[v] = v;
        dp[v] = {0};
        dp2[v] = {0};
        cost[v] = 1;
        return;
    }
    if ((int) g[v].size() == 1) {
        int u = g[v][0];
        dfs(u);
        id[v] = id[u];
        dp[id[v]].push_back(cost[u]);
        dp2[id[v]].insert(cost[u]);
        cost[v] = cost[u] + 1;
        while (dp2[id[v]].find(cost[v]) != dp2[id[v]].end()) {
            cost[v]++;
        }
        return;
    }
    int j = -1;
    for (auto u : g[v]) {
        dfs(u);
        if (j == -1 || (int) dp[id[u]].size() < (int) dp[id[j]].size()) {
            j = u;
        }
    }
    id[v] = id[j];
    dp[id[v]].push_back(cost[j]);
    dp2[id[v]].insert(cost[j]);
    for (auto u : g[v]) {
        if (u == j) {
            continue;
        }
        dp[id[u]].push_back(cost[u]);
        for (int i = 0; i < (int) dp[id[v]].size(); i++) {
            int ii = (int) dp[id[u]].size() - ((int) dp[id[v]].size() - i);
            int& x = dp[id[v]][i];
            dp2[id[v]].erase(dp2[id[v]].find(x));
            x ^= dp[id[u]][ii];
            dp2[id[v]].insert(x);
            dp[id[v]][i] = x;
        }
    }
    cost[v] = 0;
    while (dp2[id[v]].find(cost[v]) != dp2[id[v]].end()) {
        cost[v]++;
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        g[i].clear();
        dp[i].clear();
        dp2[i].clear();
    }
    vector<int> roots = {};
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        p--;
        if (p != -1) {
            g[p].push_back(i);
        } else {
            roots.push_back(i);
        }
    }
    int ans = 0;
    for (auto v : roots) {
        dfs(v);
        ans ^= cost[v];
    }
    cout << (ans ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}