#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    if (n <= 2) {
        std::cout << -1 << "\n";
        return 0;
    }
    int cnt = n * n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    a[2][2] = cnt--;
    a[0][1] = cnt--;
    a[0][2] = cnt--;
    a[1][2] = cnt--;
    a[2][1] = cnt--;
    a[2][0] = cnt--;
    a[1][0] = cnt--;
    a[0][0] = cnt--;
    a[1][1] = cnt--;
    if (n >= 4) {
        a[3][1] = cnt--;
        a[3][0] = cnt--;
        a[3][2] = cnt--;
        a[3][3] = cnt--;
        a[2][3] = cnt--;
        a[1][3] = cnt--;
        a[0][3] = cnt--;
        for (int i = 4; i < n; ++i) {
            if (i % 2 == 0) {
                for (int j = 0; j <= i; ++j)
                    a[j][i] = cnt--;
                for (int j = i - 1; j >= 0; --j)
                    a[i][j] = cnt--;
            } else {
                for (int j = 0; j <= i; ++j)
                    a[i][j] = cnt--;
                for (int j = i - 1; j >= 0; --j)
                    a[j][i] = cnt--;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cout << a[i][j] << " \n"[j == n - 1];
    return 0;
}