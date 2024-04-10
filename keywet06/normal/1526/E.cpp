#include <bits/stdc++.h>

using int64 = long long;

const int P = 998244353;
const int N = 200005;
const int M = N << 1;

int n, k, c;
int p[N], pos[N];

int64 pre[M], inv[M];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) std::cin >> pos[i], p[++pos[i]] = i;
    for (int i = 1; i < n; ++i) c += p[pos[i] + 1] < p[pos[i + 1] + 1];
    c = k + c;
    if (n > c) return std::cout << 0 << std::endl, 0;
    pre[0] = pre[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= c; ++i) pre[i] = pre[i - 1] * i % P;
    for (int i = 2; i <= c; ++i) inv[i] = (P - P / i) * inv[P % i] % P;
    for (int i = 2; i <= c; ++i) inv[i] = inv[i] * inv[i - 1] % P;
    std::cout << pre[c] * inv[n] % P * inv[c - n] % P << std::endl;
    return 0;
}