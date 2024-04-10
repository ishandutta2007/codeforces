#include <bits/stdc++.h>

using int64 = long long;

const int N = 100005;

int n, m;
int a[N];

int64 lD[N], rD[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 2; i <= n; ++i) lD[i] = lD[i - 1] + std::max(a[i - 1] - a[i], 0);
    for (int i = n - 1; i; --i) rD[i] = rD[i + 1] + std::max(a[i + 1] - a[i], 0);
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        if (l < r) {
            std::cout << lD[r] - lD[l] << '\n';
        } else {
            std::cout << rD[r] - rD[l] << '\n';
        }
    }
    return 0;
}