#include <bits/stdc++.h>

using namespace std;
typedef long long llong;

int dp[100001];

llong get(llong n) {
    if (n <= 100000) return dp[n];
    if (n % 2) return n - get(n - 1);
    if (n / 2 % 2) return n - get(n / 2);
    return n - get(n - 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i <= 100000; ++i) {
        if (i % 2 == 0) dp[i] = i - dp[i / 2];
        dp[i] = max(dp[i], i - dp[i - 1]);
    }
    int T;
    cin >> T;
    while (T--) {
        llong n;
        cin >> n;
        printf("%lld\n", get(n));
    }
    return 0;
}