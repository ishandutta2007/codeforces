#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<bitset<2001>> dp(1 << n);
    dp[0][0] = 1;
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) dp[mask] |= dp[mask ^ 1 << i] << a[i];
        }
        for (int i = 2000; i >= 1; --i) {
            if (dp[mask][i] == 1 && i % k == 0) dp[mask][i / k] = 1;
        }
    }
    if (dp[(1 << n) - 1][1] == 0) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    function<void(int, int)> dfs = [&](int mask, int x) {
        if (mask == 0) return;
        if (x * k <= 2000 && dp[mask][x * k] == 1) {
            for (int i = 0; i < n; ++i) {
                if (mask >> i & 1) ++b[i];
            }
            return dfs(mask, x * k);
        }
        for (int i = 0; i < n; ++i)
            if ((mask >> i & 1) && x >= a[i] && dp[mask ^ 1 << i][x - a[i]] == 1) return dfs(mask ^ 1 << i, x - a[i]);
    };
    dfs((1 << n) - 1, 1);
    auto mx = max_element(b.begin(), b.end());
    while (*mx > 0) {
        int x = mx - b.begin();
        int y = max_element(mx + 1, b.end()) - b.begin();
        cout << a[x] << " " << a[y] << "\n";
        a[x] += a[y];
        while (a[x] % k == 0) a[x] /= k, --b[x];
        b[y] = 0;
        mx = max_element(b.begin(), b.end());
    }
    return 0;
}