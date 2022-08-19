#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<vector<int>> cnt(m);
    for (auto &i : cnt)
        i.resize(m);
    for (int i = 0; i < n - 1; ++i) {
        ++cnt[s[i] - 'a'][s[i + 1] - 'a'];
        ++cnt[s[i + 1] - 'a'][s[i] - 'a'];
    }
    vector<vector<int>> cost(m);
    for (auto &i : cost)
        i.resize(1 << m);
    for (int x = 0; x < m; ++x) {
        for (int y = 0; y < m; ++y)
            cost[x][1 << y] = cnt[x][y];
        for (int i = 1; i < (1 << m); ++i)
            cost[x][i] = cost[x][i & -i] + cost[x][i & (i - 1)];
    }
    vector<int> dp(1 << m, INF);
    dp[0] = 0;
    for (int i = 1; i <= (1 << m); ++i) {
        int pos = __builtin_popcount(i);
        for (int x = 0; x < m; ++x)
            if (i >> x & 1)
                dp[i] = min(dp[i], dp[i ^ 1 << x] + (cost[x][i ^ 1 << x] - cost[x][((1 << m) - 1) ^ i]) * pos);
    }
    cout << dp.back() << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}