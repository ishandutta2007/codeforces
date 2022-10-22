#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
typedef pair<lint, lint> plint;

lint n, m, ans, F[404], IF[404], P[404], Dp[404][404];

lint inv(lint a, lint x = m - 2) {
    lint ret = 1;
    while (x) {
        if (x & 1) ret = ret * a % m;
        x /= 2; a = a * a % m;
    }
    return ret;
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    F[0] = 1; P[0] = 1;
    for (int i = 1; i < 404; i++) F[i] = F[i - 1] * i % m;
    for (int i = 1; i < 404; i++) P[i] = P[i - 1] * 2 % m;
    IF[403] = inv(F[403]);
    for (int i = 403; i > 0; i--) IF[i - 1] = IF[i] * i % m;
    Dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        Dp[i][i] = P[i - 1];
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= j; k++) {
                if (i - k - 1 >= 0) {
                    Dp[i][j] = (Dp[i][j] + Dp[i - k - 1][j - k] * P[k - 1] % m * F[j] % m * IF[j - k] % m * IF[k] % m) % m;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = (ans + Dp[n][i]) % m;
    }
    cout << ans;
}