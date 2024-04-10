#include <bits/stdc++.h>

const int N = 2005;

int T, n;
int a[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        int Ans = a[n] - a[1];
        for (int i = 1; i < n; ++i) Ans = std::max(Ans, a[i] - a[i + 1]);
        for (int i = 2; i <= n; ++i) Ans = std::max(Ans, a[i] - a[1]);
        for (int i = 1; i < n; ++i) Ans = std::max(Ans, a[n] - a[i]);
        std::cout << Ans << '\n';
    }
    return 0;
}