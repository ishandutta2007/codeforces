#include <bits/stdc++.h>

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int N = 1000005;

int64 T, n;
int64 a[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cout << n + i << " \n"[i == n];
    }
    return 0;
}