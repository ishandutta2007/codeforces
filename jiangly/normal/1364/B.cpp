#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            if (a.empty()) {
                a.push_back(x);
            } else if (a.size() == 1 && x != a.back()) {
                a.push_back(x);
            } else if (a[a.size() - 2] < a.back()) {
                if (a.back() <= x) {
                    a.back() = x;
                } else {
                    a.push_back(x);
                }
            } else {
                if (a.back() >= x) {
                    a.back() = x;
                } else {
                    a.push_back(x);
                }
            }
        }
        std::cout << a.size() << "\n";
        for (int i = 0; i < int(a.size()); ++i)
            std::cout << a[i] << " \n"[i == int(a.size()) - 1];
    }
    return 0;
}