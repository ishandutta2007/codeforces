#include <iostream>
#include <vector>
#include <algorithm>
int n, m, p;
int a1 = -1, b1 = -1;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> p;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        a %= p;
        if (a != 0 && a1 == -1)
            a1 = i;
    }
    for (int i = 0; i < m; ++i) {
        int b;
        std::cin >> b;
        b %= p;
        if (b != 0 && b1 == -1)
            b1 = i;
    }
    std::cout << a1 + b1 << "\n";
    return 0;
}