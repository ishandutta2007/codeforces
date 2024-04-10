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
        std::vector<int> p(n);
        std::vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> p[i];
            --p[i];
        }
        for (int i = 0; i < n; ++i)
            std::cin >> c[i];
        int ans = n;
        for (int i = 0; i < n; ++i) {
            if (p[i] == -1)
                continue;
            std::vector<int> a;
            for (int j = i; p[j] != -1; ) {
                a.push_back(c[j]);
                int k = p[j];
                p[j] = -1;
                j = k;
            }
            for (int j = 1; j <= int(a.size()); ++j) {
                if (a.size() % j == 0) {
                    for (int s = 0; s < j; ++s) {
                        bool ok = true;
                        for (int k = s; k < int(a.size()); k += j)
                            if (a[k] != a[s])
                                ok = false;
                        if (ok)
                            ans = std::min(ans, j);
                    }
                }
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}