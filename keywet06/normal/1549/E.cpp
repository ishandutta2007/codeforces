#include <bits/stdc++.h>

using int64 = long long;

const int64 P = 1000000007;
const int N = 1000010;
const int M = N * 3;

int n, q, x, c;

int64 a[M], iv[M], p[M];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> q;
    c = 3 * n + 3, iv[1] = 1;
    for (int i = 2; i <= c; ++i) iv[i] = (P - P / i) * iv[P % i] % P;
    p[0] = 1;
    for (int i = 1; i <= c; ++i) p[i] = p[i - 1] * (c - i + 1) % P * iv[i] % P;
    for (int i = 3 * n; i; --i) {
        a[i] = (((p[i + 3] - 3 * (a[i + 1] + a[i + 2])) % P) + P) % P;
    }
    while (q--) std::cin >> x, std::cout << a[x] << '\n';
    return 0;
}