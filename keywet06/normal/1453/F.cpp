#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef long double ld;
const int64 INF = 9223372036854775807;
const int64 MOD = 1000000007;
const long double PI = acos(-1);
#define pb push_back
#define mp make_pair
#define fi first
#define se second

inline int64 power(int64 a, int64 b, int64 z = MOD) {
    int64 res = 1;
    a = (a % z);
    while (b) {
        if (b & 1) res = (res * a) % z;
        a = (a * a) % z;
        b = b >> 1;
    }
    return res;
}

inline int64 inverse(int64 a, int64 z = MOD) { return power(a, z - 2, z); }

int64 extend(int64 a, int64 b, int64 &x, int64 &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int64 x1, y1;
    int64 g = extend(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

inline int64 mat_power(int64 a, int64 b, int64 c, int64 d, int64 n,
                       int64 z = MOD) {
    int64 a0 = 1, b0 = 0, c0 = 0, d0 = 1;
    while (n) {
        if (n & 1) {
            int64 a1 = a0, b1 = b0, c1 = c0, d1 = d0;
            a0 = (a1 * a + b1 * c) % z;
            b0 = (a1 * b + b1 * d) % z;
            c0 = (c1 * a + d1 * c) % z;
            d0 = (c1 * b + d1 * d) % z;
        }
        int64 a1 = a, b1 = b, c1 = c, d1 = d;
        a = (a1 * a1 + b1 * c1) % z;
        b = (a1 * b1 + b1 * d1) % z;
        c = (c1 * a1 + d1 * c1) % z;
        d = (c1 * b1 + d1 * d1) % z;
        n = n >> 1;
    }
    return c0;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int64 t, n;
    std::cin >> t;
    for (int64 test = 1; test <= t; test++) {
        std::cin >> n;
        int64 aray[n];
        int64 dp[n][n], sum[n][n];
        for (int64 i = 0; i < n; i++) std::cin >> aray[i];
        dp[n - 1][n - 1] = 0;
        for (int64 i = 0; i < n; i++) {
            sum[i][i] = 0;
            if (i > 0) sum[i - 1][i] = 0;
            for (int64 j = i - 2; j >= 0; j--) {
                sum[j][i] = sum[j + 1][i] + (j + 1 + aray[j + 1] >= i);
            }
        }
        for (int64 i = n - 2; i >= 0; i--) {
            if (aray[i] == 0) {
                for (int64 j = i; j < n; j++) dp[i][j] = 1e10;
                continue;
            }
            dp[i][n - 1] = 1e10;
            for (int64 j = n - 2; j >= i; j--) {
                if (aray[i] + i <= j) {
                    dp[i][j] = 1e10;
                } else {
                    dp[i][j] = std::min(dp[i][j + 1],
                                        dp[j + 1][i + aray[i]] + sum[i][j + 1]);
                }
            }
        }
        std::cout << dp[0][0] << "\n";
    }
    return 0;
}