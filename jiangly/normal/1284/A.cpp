#include <iostream>
#include <vector>
#include <string>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n), t(m);
    for (int i = 0; i < n; ++i)
        std::cin >> s[i];
    for (int i = 0; i < m; ++i)
        std::cin >> t[i];
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int y;
        std::cin >> y;
        --y;
        std::cout << s[y % n] + t[y % m] << "\n";
    }
    return 0;
}