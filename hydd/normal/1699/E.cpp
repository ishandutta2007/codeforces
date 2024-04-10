//
// Created by hydd on 2022/10/12.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 0;
    cin >> T;
    while (T--) {
        int n = 0, m = 0;
        cin >> n >> m;
        vector<int> v(m + 1);
        int mn = m + 1;
        for (int i = 1, x = 0; i <= n; i++) {
            cin >> x;
            mn = min(mn, x);
            v[x] = true;
        }
        vector<int> dp(m + 1), tot(m + 1);
        for (int i = 1; i <= m; i++) {
            dp[i] = i;
            if (v[i]) tot[i]++;
        }

        int ans = m + 1;
        for (int i = m, now = m; i >= 1; i--) {
            if (1ll * i * i <= m)
                for (int j = i * i; j <= m; j += i) {
                    if (v[j]) tot[dp[j]]--;
                    dp[j] = min(dp[j], dp[j / i]);
                    if (v[j]) tot[dp[j]]++;
                }
            while (!tot[now]) now--;
            if (i <= mn) ans = min(ans, now - i);
        }
        cout << ans << '\n';
    }
    return 0;
}