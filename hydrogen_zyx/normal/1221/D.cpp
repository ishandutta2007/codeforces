#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;

ll dp[N][3];
ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
            memset(dp[i], 0x3f, sizeof dp[i]);
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (a[i - 1] + j != a[i] + k) {
                        dp[i][k] = min(dp[i][k], dp[i - 1][j] + k * b[i]);
                    }
                }
            }
        }
        ll ans = 0x3f3f3f3f3f3f3f3f;
        for (int i = 0; i < 3; i++) ans = min(ans, dp[n][i]);
        cout << ans << endl;
    }
}