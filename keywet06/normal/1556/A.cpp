#include <bits/stdc++.h>

using int64 = long long;

const int N = 1000005;

int T, n, k, x, y, z;
int a[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> x >> y;
        if ((x + y) & 1) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << (x == y ? bool(x) : 2) << std::endl;
        }
    }
    return 0;
}