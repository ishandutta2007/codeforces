#include <bits/stdc++.h>

using int64 = long long;

const int64 P = 1000000007;
const int N = 100000 + 1;

int64 Pow(int64 a, int64 r) {
    int64 res = 1;
    for (; r; r >>= 1, a = a * a % P) {
        if (r & 1) res = res * a % P;
    }
    return res;
}

int64 g[N], f[N], F[N], G[N], S[N];

int64 C(int64 n, int64 m) { return F[n] * G[m] % P * G[n - m] % P; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::map<int, int> mp;
    for (int i = 0; i <= n; ++i) G[i] = Pow(F[i] = i ? F[i - 1] * i % P : 1, P - 2);
    for (int i = 0, a; i < n; ++i) std::cin >> a, ++mp[a];
    for (int i = 0; i < n; ++i) {
        g[i] = i ? (i * g[i - 1] % P * (k - 1) + (int64)n * k) % P * Pow(n - i, P - 2) % P : k;
    }
    for (int i = n - 1; i >= 0; --i) f[i] = (g[i] + f[i + 1]) % P;
    std::map<int, int> count;
    count[0] = k;
    for (auto [x, y] : mp) {
        if (x != -1) ++count[y], --count[0];
    }
    int r = mp[-1];
    for (auto [x, y] : count) {
        for (int i = 0; i <= r; ++i) S[i] = (S[i] + y * f[x + i]) % P;
    }
    int64 ans = 0;
    for (int i = 0; i <= r; ++i) {
        int64 p = C(r, i) * Pow(k - 1, r - i) % P * Pow(Pow(k, P - 2), r) % P;
        ans = (ans + p * S[i]) % P;
    }
    std::cout << (ans + P - f[0] * (k - 1) % P) % P * Pow(k, P - 2) % P << std::endl;
    return 0;
}