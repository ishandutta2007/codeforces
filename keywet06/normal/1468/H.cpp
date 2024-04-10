#include <bits/stdc++.h>

const int N = 200005;

int T, n, m, k, tot, d, sum, l, r;
int b[N];

int Main() {
    std::cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) std::cin >> b[i];
    if ((n - m) % (k - 1) != 0) return std::cout << "NO\n", 0;
    tot = 1, d = (k - 1) / 2, sum = n;
    for (int i = 1; i <= m; ++i) {
        if (b[i] - i < d || n - b[i] - m + i < d) continue;
        return std::cout << "YES\n", 0;
    }
    return std::cout << "NO\n", 0;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) Main();
    return 0;
}