#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> odd, even;
        for (int i = 1; i <= 2 * n; ++i) {
            int a;
            std::cin >> a;
            if (a % 2) {
                odd.push_back(i);
            } else {
                even.push_back(i);
            }
        }
        if (odd.size() % 2 == 0) {
            if (!odd.empty()) {
                odd.pop_back();
            } else {
                even.pop_back();
            }
        }
        for (int i = 0; i + 1 < int(odd.size()); i += 2)
            std::cout << odd[i] << " " << odd[i + 1] << "\n";
        for (int i = 0; i + 1 < int(even.size()); i += 2)
            std::cout << even[i] << " " << even[i + 1] << "\n";
    }
    return 0;
}