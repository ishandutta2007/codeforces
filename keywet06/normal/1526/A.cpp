#include <bits/stdc++.h>

const int N = 1005;

int T, n;
int a[N];

int main() {
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 0; i < n << 1; ++i) std::cin >> a[i];
        std::sort(a, a + (n << 1));
        for (int i = 0; i < n << 1; ++i) std::cout << a[(i >> 1) + (i & 1) * n] << ' ';
        std::cout << std::endl;
    }
    return 0;
}