#include <bits/stdc++.h>

const int N = 100005;

int a[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n, k, s = 0;
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i], s += a[i];
        int Ans = n - 1, c = 0;
        for (int i = 0; i <= n; ++i) c += a[i], Ans = std::min(Ans, std::max(c, n - i - s + c));
        std::cout << Ans << '\n';
    }
    return 0;
}