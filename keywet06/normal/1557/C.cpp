#include <bits/stdc++.h>

using int64 = long long;

const int P = 1000000007;
const int N = 200005;

int T;
int a[N];

int64 n, x, y, z, ans, k, d00, d01, d10, d11;
int64 re[N], pre[N], inv[N], se2[N];

inline int64 C(int m, int n) { return pre[m] * re[n] % P * re[m - n] % P; }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    pre[0] = inv[0] = inv[1] = re[0] = se2[0] = 1;
    for (int i = 1; i < N; ++i) pre[i] = pre[i - 1] * i % P;
    for (int i = 2; i < N; ++i) inv[i] = (P - P / i) * inv[P % i] % P;
    for (int i = 1; i < N; ++i) re[i] = re[i - 1] * inv[i] % P;
    for (int i = 1; i < N; ++i) se2[i] = se2[i - 1] * 2 % P;
    while (T--) {
        std::cin >> n >> k;
        d00 = d01 = d10 = d11 = 0;
        (n & 1 ? d11 : d10) = 1;
        for (int i = 0; i < n; ++++i) d00 += C(n, i);
        for (int i = 1; i < n; ++++i) d01 += C(n, i);
        d00 = d00 % P, d01 = d01 % P;
        x = 1, y = 0;
        for (int i = 1; i <= k; ++i) {
            y = (y * se2[n] + x * d10) % P;
            x = x * (d00 + d11) % P;
        }
        std::cout << (x + y) % P << '\n';
    }
    return 0;
}