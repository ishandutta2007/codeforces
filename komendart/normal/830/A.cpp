#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e17;
const int maxn = 2005;

int n, k, p;
vector<int> a, b;
int dp[maxn][maxn];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k >> p;
    a.resize(n);
    b.resize(k);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < k; ++i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (j != k) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            if (i != n && j != k) {
                int cost = abs(a[i] - b[j]) + abs(p - b[j]);
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], cost));
            }
        }
    }
    cout << dp[n][k] << '\n';
}