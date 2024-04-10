#include <bits/stdc++.h>
using namespace std;
constexpr int N = 80, M = 1E5, INF = 1E9;
int n, m;
int dp[M + 1];
pair<int, int> a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    fill(dp + 1, dp + m + 1, INF);
    for (int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        int x = a[i].first;
        int s = a[i].second;
        for (int l = 0; l < m; ++l)
            dp[min(m, x + l)] = min(dp[min(m, x + l)], dp[max(0, x - l - 1)] + max(0, l - s));
        for (int i = m; i > 0; --i)
            dp[i - 1] = min(dp[i - 1], dp[i]);
    }
    cout << dp[m] << endl;
    return 0;
}