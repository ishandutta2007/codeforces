#include <bits/stdc++.h>

typedef long long int64;

const int N = 2005;

int n = 0;

int64 k, ans, cur;
int64 l[N], r[N], a[N];
int64 dp[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) std::cin >> l[i] >> r[i] >> a[i];
    for (int i = n; i >= 1; --i) {
        int64 need = a[i] + (i < n && r[i] == l[i + 1] ? dp[i + 1] : 0);
        if ((r[i] - l[i] + 1) * k < need) return std::cout << "-1\n", 0;
        dp[i] = need - (r[i] - l[i]) * k;
        if (dp[i] < 0) dp[i] = 0;
    }
    cur = k;
    for (int i = 1; i <= n; ++i) {
        if (cur < dp[i]) ans += cur, cur = k;
        ans += a[i], cur = ((cur - a[i]) % k + k) % k;
    }
    std::cout << ans << '\n';
    return 0;
}