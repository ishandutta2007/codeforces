#include <iostream>
#include <vector>
int n, m;
std::vector<int> a;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    while (m > 0) {
        if (int(a.size()) == n) {
            std::cout << -1 << "\n";
            return 0;
        }
        if (m <= int(a.size()) / 2) {
            a.push_back(2 * (a.size() - m) + 1);
            break;
        } else {
            m -= a.size() / 2;
            a.push_back(a.size() + 1);
        }
    }
    while (int(a.size()) < n)
        a.push_back(100000000 + 10000 * a.size());
    for (int x : a)
        std::cout << x << " \n"[x == a.back()];
    return 0;
}