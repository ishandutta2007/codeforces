#include <bits/stdc++.h>

using int64 = long long;

const int N = 100005;

int T, n;
int a[N];

int64 p;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        std::sort(a + 1, a + n + 1);
        p = a[n];
        for (int i = 1; i <= n; ++i) p += (n - i - i + 1ll) * a[i];
        std::cout << p << std::endl;
    }
    return 0;
}