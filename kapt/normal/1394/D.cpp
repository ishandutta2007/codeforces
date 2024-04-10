#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 3e5;
int t[MAXN], h[MAXN];
vector<int> g[MAXN];
int dp[MAXN][2];

void dfs(int v, int p = -1) {
    array<int, 2> bal = {0, 0};
    int ans = 0;
    vector<int> arr;
    for (auto u : g[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
        if (h[u] > h[v]) {
            bal[0]++;
            ans += dp[u][0];
        } else if (h[u] < h[v]) {
            ans += dp[u][1];
            bal[1]++;
        } else {
            ans += dp[u][0];
            bal[0]++;
            arr.push_back(dp[u][1] - dp[u][0]);
        }
    }
    sort(arr.begin(), arr.end());
    vector<int> pref(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); ++i) {
        pref[i + 1] = pref[i] + arr[i];
    }
    dp[v][0] = 1e18;
    dp[v][1] = 1e18;
    int res = 1e18;
    /// cout << v << ": ";
    /// cout << ans << endl;
    for (int i = 0; i <= arr.size(); ++i) {
        array<int, 2> b = bal;
        b[0] -= i;
        b[1] += i;
        /// cout << pref[i] << " ";
        res = min(res, ans + pref[i] + t[v] * max(b[0], b[1]));
        b[1]++;
        dp[v][0] = min(dp[v][0], ans + pref[i] + t[v] * max(b[0], b[1]));
        b[1]--;
        b[0]++;
        dp[v][1] = min(dp[v][1], ans + pref[i] + t[v] * max(b[0], b[1]));
    }
    /// cout << endl;
    /// cout << dp[v][0] << " " << dp[v][1] << endl;
    if (p == -1) {
        cout << res;
        exit(0);
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    return 0;
}