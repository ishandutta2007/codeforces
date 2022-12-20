#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1;

long long dp[N], cnt[N], tek[N], a[N];
vector <int> e[N];
bool inm[N];

void dfs(int u, int pr) {
    int i;
    tek[u] = a[u];
    inm[u] = false;
    for (i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        dfs(e[u][i], u);
        if (tek[e[u][i]] > 0)
            tek[u] += tek[e[u][i]];

        dp[u] = max(dp[u], dp[e[u][i]]);
    }
    if (tek[u] > dp[u]) {
        inm[u] = true;
        dp[u] = tek[u];
        cnt[u] = 1;
        return;
    }
    cnt[u] = 0;
    for (i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        if (dp[e[u][i]] == dp[u])
            cnt[u] += cnt[e[u][i]];
        if (tek[e[u][i]] > 0 && dp[e[u][i]] == dp[u])
            inm[u] |= inm[e[u][i]];
    }
    if (tek[u] == dp[u] && !inm[u]) {
        ++cnt[u];
        inm[u] = true;
    }
}

int main() {
    int i, j, k, n, a1, b1;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    long long mx = -1e9;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    if (mx <= 0) {
        int ans = 0;
        for (i = 1; i <= n; ++i)
        if (a[i] == mx)
            ++ans;
        cout << mx * ans << ' ' << ans << "\n";
        return 0;
    }
    for (i = 1; i < n; ++i) {
        cin >> a1 >> b1;
        e[a1].push_back(b1);
        e[b1].push_back(a1);
    }
    dfs(1, 0);
    cout << dp[1] * cnt[1] << ' ' << cnt[1];
}