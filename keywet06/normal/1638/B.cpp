// Luogu Remote

#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int L1 = 0, L0 = 0;
        bool Flag = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] & 1) {
                Flag &= a[i] >= L1, L1 = a[i];
            } else {
                Flag &= a[i] >= L0, L0 = a[i];
            }
        }
        std::cout << (Flag ? "Yes" : "No") << '\n';
    }
    return 0;
}