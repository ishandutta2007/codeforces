#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2;
        std::cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 && a + b > 0 || y1 == y2 && c + d > 0 || x - a + b < x1 || x - a + b > x2 || y - c + d < y1 || y - c + d > y2) {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
        }
    }
    return 0;
}