#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<bool> a(n);
        int res = -1;
        for (int i = 0; i < n; ++i) {
            int k;
            std::cin >> k;
            std::vector<int> v(k);
            for (int j = 0; j < k; ++j) {
                std::cin >> v[j];
                --v[j];
            }
            bool marry = false;
            for (int j : v) {
                if (!a[j]) {
                    a[j] = marry = true;
                    break;
                }
            }
            if (!marry)
                res = i;
        }
        if (res == -1) {
            std::cout << "OPTIMAL\n";
        } else {
            std::cout << "IMPROVE\n";
            int v = 0;
            while (a[v])
                ++v;
            std::cout << res + 1 << " " << v + 1 << "\n";
        }
    }
    return 0;
}