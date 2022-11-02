#include <bits/stdc++.h>

using int64 = long long;

inline void FWTxor(int64 *f, int n) {
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k = 0; k < i; ++k) {
                int64 x = f[j | k], y = f[j | i | k];
                f[j | k] = x + y, f[j | i | k] = x - y;
            }
        }
    }
}

inline void UFWTxor(int64 *f, int n) {
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k = 0; k < i; ++k) {
                int64 x = f[j | k], y = f[j | i | k];
                f[j | k] = x + y >> 1, f[j | i | k] = x - y >> 1;
            }
        }
    }
}

const int N = 1 << 20;
const int M = 100005;

int n, m;
int64 a[M], f[N], dp[N], Ans[N];

std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> s;
        for (int j = 0; j < m; ++j) a[j] ^= (s[j] == '1') << i;
    }
    for (int i = 0; i < m; ++i) ++f[a[i]];
    for (int i = 0; i < 1 << n; ++i) {
        dp[i] = std::min(__builtin_popcount(i), __builtin_popcount(~i & (1 << n) - 1));
    }
    FWTxor(f, 1 << n), FWTxor(dp, 1 << n);
    for (int i = 0; i < 1 << n; ++i) Ans[i] = f[i] * dp[i];
    UFWTxor(Ans, 1 << n);
    int64 Out = INT_MAX;
    for (int i = 0; i < 1 << n; ++i) Out = std::min(Out, Ans[i]);
    std::cout << Out << std::endl;
    return 0;
}