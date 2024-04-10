#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cnt++;
            pos.push_back(i);
        }
    }
    if (cnt % 2 == 1) {
        cout << -1 << '\n';
        return;
    }
    if (x >= y) {
        long long ans = 0;
        if (cnt >= 4) {
            ans = y * 1ll * cnt / 2;
        } else if (cnt == 2) {
            if (pos[0] + 1 == pos[1]) {
                ans = min(x, 2 * y);
            } else {
                ans = y;
            }
        }
        cout << ans << '\n';
        return;
    }
    vector<int> L(n, -1), R(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] != b[j]) L[i] = j;
        }
        for (int j = n - 1; j > i; j--) {
            if (a[j] != b[j]) R[i] = j;
        }
    }
    vector<vector<long long>> dp(n, vector<long long> (n, (long long) 1e18));
    for (int l = n - 1; l >= 0; l--) {
        int c = 0;
        for (int r = l; r < n; r++) {
            if (a[r] != b[r]) {
                c++;
            }
            if (c == 0) {
                dp[l][r] = 0;
                continue;
            }
            if (c % 2 == 1) {
                continue;
            }
            if (l == r) {
                if (a[l] == b[l]) {
                    dp[l][r] = 0;
                }
                continue;
            }
            if (a[l] == b[l]) {
                dp[l][r] = dp[l + 1][r];
                continue;
            }
            if (a[r] == b[r]) {
                dp[l][r] = dp[l][r - 1];
                continue;
            }
            if (l + 1 == r) {
                dp[l][r] = min(x, 2 * y);
            } else {
                dp[l][r] = dp[l + 1][r - 1] + y;
                if (R[l] != r) {
                    dp[l][r] = min(dp[l][r], dp[R[l] + 1][r] + x * 1ll * (R[l] - l));
                    dp[l][r] = min(dp[l][r], dp[l][L[r] - 1] + x * 1ll * (r - L[r]));
                } else {
                    dp[l][r] = min(dp[l][r], (r - l) * 1ll * x);
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
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