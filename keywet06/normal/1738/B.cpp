#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int64> s(n + 1);
        for (int i = n - k + 1; i <= n; ++i) std::cin >> s[i];
        if (k == 1 && (std::cout << "Yes\n", true)) continue;
        bool Flag = true;
        for (int i = n - k + 3; i <= n; ++i) Flag &= s[i - 1] - s[i - 2] <= s[i] - s[i - 1];
        for (int i = n - k; i >= 0; --i) s[i] = s[i + 1] + s[i + 1] - s[i + 2];
        Flag &= s[0] <= 0;
        std::cout << (Flag ? "Yes\n" : "No\n");
    }
    return 0;
}