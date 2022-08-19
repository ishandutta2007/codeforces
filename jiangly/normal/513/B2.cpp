#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    i64 m;
    std::cin >> n >> m;
    m--;
    std::vector<int> a(n);
    int L = 0, R = n;
    for (int i = 1; i < n; i++) {
        if (m >> (n - i - 1) & 1) {
            a[--R] = i;
        } else {
            a[L++] = i;
        }
    }
    a[L] = n;
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}