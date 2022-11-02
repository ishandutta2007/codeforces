#include <bits/stdc++.h>

template <typename Type>
inline bool NEq(Type u) {
    return true;
}

template <typename Type, typename... Args>
inline bool NEq(Type u, Type x, Args... args) {
    return u != x && NEq(u, args...);
}

using int64 = long long;

const int64 C = 10000000007;

const int N = 1000005;

int p[N], Fc[N];

int64 f[N];

template <typename... Args>
inline int Answer(int n, int c, Args... args) {
    std::cout << c << std::endl;
    for (int i = 1; i <= n; ++i) {
        if (NEq(i, args...)) std::cout << i << ' ';
    }
    std::cout << std::endl;
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, Cnt = 0;
    std::cin >> n;
    for (int i = 2; i <= n; ++i) {
        if (!Fc[i]) Fc[i] = i, p[Cnt++] = i, f[i] = i * C;
        for (int j = 0; j < Cnt && p[j] * i <= n; ++j) {
            Fc[i * p[j]] = p[j], f[i * p[j]] = f[i] ^ f[p[j]];
            if (!(i % p[j])) break;
        }
    }
    int64 Sum = 0;
    for (int i = 1; i <= n; ++i) Sum ^= f[i] ^= f[i - 1];
    if (!Sum) return Answer(n, n);
    std::map<int64, int> Map;
    for (int i = 1; i <= n; ++i) Map[f[i]] = i;
    if (Map.count(Sum)) return Answer(n, n - 1, Map[Sum]);
    for (int x = 1; x <= n; ++x) {
        if (Map.count(Sum ^ f[x])) return Answer(n, n - 2, x, Map[Sum ^ f[x]]);
    }
    return Answer(n, n - 3, 2, n / 2, n);
}