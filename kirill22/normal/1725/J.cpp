#include "bits/stdc++.h"

using namespace std;

const int N = 1e5;
int n;
long long dp[N], dp2[N], ans = (long long) 1e18, sum = 0;
vector<pair<int, int>> g[N];

void dfs(int v, int pr) {
    dp[v] = 0;
    dp2[v] = 0;
    for (auto [u, d] : g[v]) {
        if (u != pr) {
            dfs(u, v);
            dp[v] = max(dp[v], dp2[v] + d + dp2[u]);
            dp[v] = max(dp[v], dp[u]);
            dp2[v] = max(dp2[v], dp2[u] + d);
        }
    }
}

void dfs2(int v, int pr, long long tmp, long long tmp2) {
    multiset<long long> a = {tmp}, b = {tmp2};
    vector<long long> c = {tmp2};
    for (auto [u, d] : g[v]) {
        if (u != pr) {
            a.insert(dp[u]);
            b.insert(dp2[u] + d);
            c.push_back(dp2[u] + d);
        }
    }
    {
        sort(c.rbegin(), c.rend());
        long long res = 0;
        for (int i = 0; i < min(4, (int) c.size()); i++) {
            res += c[i];
        }
        res = 2 * sum - res;
        ans = min(ans, res);
    }
    for (auto [u, d] : g[v]) {
        if (u != pr) {
            a.erase(a.find(dp[u]));
            b.erase(b.find(dp2[u] + d));
            long long mx = max(*a.rbegin(), *b.rbegin());
            if ((int) b.size() >= 2) {
                auto it = --b.end();
                auto it2 = --(--b.end());
                mx = max(mx, *it + *it2);
            }
            long long res = 2 * sum - 2 * d - mx - dp[u];
            // cout << res << " " << v << " " << u << " " << mx << " " << dp[u] << endl;
            dfs2(u, v, max(mx, d + *b.rbegin()), d + *b.rbegin());
            ans = min(ans, res);
            a.insert(dp[u]);
            b.insert(dp2[u] + d);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n <= 2) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i + 1 < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
        sum += w;
    }
    dfs(0, -1);
    dfs2(0, -1, 0, 0);
    cout << ans;
}