#include <bits/stdc++.h>
constexpr int N = 2e6, P = 1000000007;
int a[N + 1], b[N + 1];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for (int i = 1; i <= N; ++i) {
        a[i] = (2ll * a[i - 2] + a[i - 1]) % P;
        if (b[i - 1] && b[i - 2]) {
            a[i] = (a[i] + 1) % P;
        } else {
            b[i] = 1;
        }
    }
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::cout << 4ll * a[n] % P << "\n";
    }
    return 0;
}