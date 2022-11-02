#include <bits/stdc++.h>

using int64 = long long;

const int N = 300;
const int P = 1000000007;


int n, m, K, cnt;

int id[N][N];

struct mat {
    int a[N][N];
    mat() { memset(a, 0, sizeof a); }
    mat operator*(const mat& b) const {
        mat c;
        for (int i = 1; i <= cnt; ++i)
            for (int k = 1; k <= cnt; ++k) {
                for (int j = 1; j <= cnt; ++j) {
                    c.a[i][k] = (c.a[i][k] + (int64)a[i][j] * b.a[j][k]) % P;
                }
            }
        return c;
    }
} A, B;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> K >> m;
    for (int i = 0; i <= K; ++i) {
        for (int j = 0; j < (1 << m); ++j) id[i][j] = ++cnt;
    }
    for (int i = 0; i <= K; ++i) {
        for (int j = 0; j < (1 << m); ++j) {
            B.a[id[i][j]][id[i][j * 2 % (1 << m)]] = 1;
            if (i != K) {
                B.a[id[i][j]][id[i + 1][(j * 2 + 1) % (1 << m)]] =
                    __builtin_popcount(j) + 1;
            }
        }
    }
    A.a[1][1] = 1;
    for (; n; n /= 2, B = B * B) {
        if (n & 1) A = A * B;
    }
    int ans = 0;
    for (int i = 0; i < (1 << m); ++i) ans = (ans + A.a[1][id[K][i]]) % P;
    std::cout << ans << '\n';
    return 0;
}