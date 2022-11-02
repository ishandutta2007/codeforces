#include <bits/stdc++.h>

const int N = 2000005;

using int64 = long long;

int n;

int64 x, s, t, p1;
int64 b[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 0; i < n; ++i) std::cin >> x, s += x;
    p1 = (s - 1ll * n * (n - 1) / 2) / n;
    for (int i = 1; i <= n; ++i) b[i] = p1 + i - 1, t += b[i];
    for (int i = 1; i <= n; ++i) {
        if (t < s) ++b[i], ++t;
    }
    for (int i = 1; i <= n; ++i) std::cout << b[i] << " \n"[i == n];
    return 0;
}