#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll dp[3005][3005];
char s[3005], t[3005];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> s + 1 >> t + 1;
    ll n = strlen(s + 1);
    ll m = strlen(t + 1);
    for (int i = 1; i <= n + 1; i++) dp[i][i - 1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j + i - 1 <= n; j++) {
            if (j > m || s[i] == t[j]) {
                dp[j][j + i - 1] =
                    (dp[j][j + i - 1] + dp[j + 1][j + i - 1]) % mod;
            }
            if (j + i - 1 > m || s[i] == t[j + i - 1]) {
                dp[j][j + i - 1] = (dp[j][j + i - 1] + dp[j][j + i - 2]) % mod;
            }
        }
    }
    ll ans = 0;
    for (int i = m; i <= n; i++) {
        ans = (ans + dp[1][i]) % mod;
    }
    cout << ans;
}