#include <iostream>
#include <vector>
#include <algorithm>
int t, n;
std::vector<std::pair<int, int>> p;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        p.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> p[i].first >> p[i].second;
        std::sort(p.begin(), p.end());
        bool ok = true;
        for (int i = 0; i < n; ++i)
            if (p[i].second > p[i + 1].second)
                ok = false;
        if (!ok) {
            std::cout << "NO\n";
            continue;
        }
        std::cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            for (int j = p[i].first; j < p[i + 1].first; ++j)
                std::cout << "R";
            for (int j = p[i].second; j < p[i + 1].second; ++j)
                std::cout << "U";
        }
        std::cout << "\n";
    }
    return 0;
}