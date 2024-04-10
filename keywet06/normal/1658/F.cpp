#include <bits/stdc++.h>

using int64 = long long;

const int N = 500010;
const int Z = 7000010;
const int P = 998244353;
const int L = 20;
const int I2 = (P + 1) / 2;

int a[N], f[N];

void Solve() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        char c;
        std::cin >> c;
        a[i] = c - '0';
    }
    int64 sum = 0ll;
    for (int i = 1; i <= n; ++i) sum += a[i];
    sum *= m;
    if (sum % n) {
        std::cout << -1 << '\n';
        return;
    }
    sum /= n;
    for (int i = 1; i <= n; ++i) f[i] = f[i - 1] + a[i];
    for (int i = m; i <= n; ++i) {
        if (f[i] - f[i - m] == sum) {
            std::cout << 1 << '\n';
            std::cout << i - m + 1 << " " << i << '\n';
            return;
        }
    }
    for (int i = 1; i < m; ++i) {
        if (f[i] + (f[n] - f[n - m + i]) == sum) {
            std::cout << 2 << '\n';
            std::cout << 1 << " " << i << '\n';
            std::cout << n - m + i + 1 << " " << n << '\n';
            return;
        }
    }
    std::cout << -1 << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) Solve();
    return 0;
}