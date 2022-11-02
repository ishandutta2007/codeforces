#include <bits/stdc++.h>

using int64 = long long;

const int P = 1000000007ll;

void Add(int64 &a, int64 b) { a = (a + b) % P; }

int64 gcd(int64 a, int64 b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int64> a(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    std::vector<int> p(n);
    for (int i = 1; i < n; ++i) scanf("%d", &p[i]), --p[i];
    std::vector<int64> A = a;
    for (int i = n - 1; i > 0; --i) A[p[i]] += A[i];
    std::vector<int64> C(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        int64 k = A[0] / gcd(A[0], A[i]);
        if (k <= n) {
            for (int l = (int)k; l <= n; l += (int)k) ++C[l];
        }
    }
    int64 ans = 0;
    std::vector<int64> dp(n + 1, 0ll);
    dp[1] = 1ll;
    for (int i = 1; i <= n; ++i) {
        if (C[i] < i - 1) continue;
        Add(ans, dp[i]);
        for (int j = 2 * i; j <= n; j += i) {
            if (C[j] >= j - 1) Add(dp[j], dp[i]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}