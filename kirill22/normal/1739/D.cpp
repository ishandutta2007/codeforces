#include "bits/stdc++.h"

using namespace std;

const int N = 2e5;
int n, k, m, cnt = 0, dp[N];
vector<int> g[N];

void dfs(int v, int pr) {
    dp[v] = 1;
    for (auto u : g[v]) {
        dfs(u, v);
        dp[v] = max(dp[v], dp[u] + 1);
    }
    if (pr != 0 && v != 0 && dp[v] == m) {
        cnt++;
        dp[v] = 0;
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        g[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p - 1].push_back(i);
    }
    int l = 0, r = n;
    while (l + 1 < r) {
        m = (l + r) / 2;
        cnt = 0;
        dfs(0, -1);
        //cout << m << " " << cnt << endl;
        if (cnt > k) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << r << '\n';
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