#include <bits/stdc++.h>

const int N = 100;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> Times(N + 1);
        for (int i = 0, x; i < n; ++i) std::cin >> x, ++Times[std::abs(x)];
        int Ans = std::min(1, Times[0]);
        for (int i = 1; i <= N; ++i) Ans += std::min(Times[i], 2);
        std::cout << Ans << std::endl;
    }
    return 0;
}