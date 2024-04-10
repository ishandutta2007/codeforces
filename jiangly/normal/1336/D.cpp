#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>
int main() {
    int n;
    std::cin >> n;
    int x, y;
    std::cin >> x >> y;
    std::vector<int> a(n);
    std::vector<int> dx, dy;
    auto query = [&](int i) {
        std::cout << "+ " << i + 1 << std::endl;
        int nx, ny;
        std::cin >> nx >> ny;
        dx.push_back(nx - x);
        dy.push_back(ny - y);
        x = nx;
        y = ny;
    };
    for (int i = n - 2; i >= 2; --i)
        query(i);
    query(0);
    query(1);
    query(0);
    a[0] = std::sqrt(2 * dx[n - 1]);
    a[2] = dy[n - 1] - dy[n - 3] - 1;
    a[1] = dy[n - 1] / (a[2] + 1) - 1;
    a[3] = (dy[n - 2] - (a[0] + 1) * (a[2] + 1)) / (a[2] + 1) - (n > 4);
    for (int i = 2; i < n - 2; ++i)
        a[i + 2] = (dy[n - i - 2] - a[i - 2] * a[i - 1] - a[i - 1] * (a[i + 1] + 1)) / (a[i + 1] + 1) - (i < n - 3);
    std::cout << "!";
    for (int i = 0; i < n; ++i)
        std::cout << " " << a[i];
    std::cout << std::endl;
    return 0;
}