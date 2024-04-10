#include <bits/stdc++.h>

const int P = (int)1e9 + 7;

inline void add(int &a, int b) {
    a += b;
    if (a >= P) a -= P;
}

inline void sub(int &a, int b) {
    a -= b;
    if (a < 0) a += P;
}

inline int mul(int a, int b) { return (int)((long long)a * b % P); }

inline int power(int a, long long b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a), b >>= 1;
    }
    return res;
}

inline int inv(int a) {
    a %= P;
    if (a < 0) a += P;
    int b = P, u = 0, v = 1;
    while (a) {
        int t = b / a;
        b -= t * a, std::swap(a, b);
        u -= t * v, std::swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += P;
    return u;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    long long n;
    int k;
    std::cin >> n >> k;
    std::vector<std::pair<long long, int> > f;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int cc = 0;
            while (n % i == 0) n /= i, ++cc;
            f.emplace_back(i, cc);
        }
    }
    if (n > 1) f.emplace_back(n, 1);
    int ans = 1;
    for (auto &p : f) {
        int cc = p.second;
        std::vector<std::vector<int> > dp(k + 1, std::vector<int>(cc + 1, 0));
        dp[0][cc] = 1;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j <= cc; ++j) {
                int cur = mul(dp[i][j], inv(j + 1));
                for (int t = 0; t <= j; ++t) add(dp[i + 1][t], cur);
            }
        }
        int x = 1;
        int cur = 0;
        for (int j = 0; j <= cc; ++j) {
            add(cur, mul(x, dp[k][j]));
            x = mul(x, (int)(p.first % P));
        }
        ans = mul(ans, cur);
    }
    std::cout << ans << '\n';
    return 0;
}