#include <bits/stdc++.h>

const int N = 100005;

int a[N], p[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i], p[i] = i;
        std::sort(p + 1, p + n + 1, [](int x, int y) { return a[x] - a[x - 1] > a[y] - a[y - 1]; });
        for (int i = 1; i <= n; ++i) std::cout << p[i] << " \n"[i == n];
    }
    return 0;
}