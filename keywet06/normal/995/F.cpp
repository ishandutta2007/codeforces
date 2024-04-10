#include <bits/stdc++.h>

using int64 = long long;

const int64 P = (int64)1e9 + 7;

int64 Add(int64 x, int64 y) {
    x += y;
    if (x >= P) return x - P;
    return x;
}

int64 Sub(int64 x, int64 y) {
    x -= y;
    if (x < 0) return x + P;
    return x;
}

int64 Mul(int64 x, int64 y) { return (x * y) % P; }

const int N = 3005;

int n;
int p[N];

int64 Inv[N];
int64 dp[N][N];

std::vector<int> g[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    Inv[1] = 1;
    for (int64 x = 2; x < N; ++x) Inv[x] = Sub(0, Mul(P / x, Inv[P % x]));
    int64 P;
    std::cin >> n >> P;
    for (int i = 1; i < n; ++i) std::cin >> p[i], --p[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) dp[i][j] = 1;
    }
    for (int v = n - 1; v >= 0; --v) {
        dp[v][0] = 0;
        for (int i = 1; i <= n; ++i) dp[v][i] = Add(dp[v][i], dp[v][i - 1]);
        if (v == 0) break;
        for (int i = 0; i <= n; ++i) dp[p[v]][i] = Mul(dp[p[v]][i], dp[v][i]);
    }
    int64 Ans = 0;
    for (int i = 0; i <= n; ++i) {
        int64 ans = dp[0][i];
        for (int j = 0; j <= n; ++j) {
            if (j == i) continue;
            ans = Mul(ans, Sub(P, j));
            ans = Mul(ans, Inv[abs(i - j)]);
            if (i < j) ans = Sub(0, ans);
        }
        Ans = Add(Ans, ans);
    }
    std::cout << Ans << std::endl;
    return 0;
}