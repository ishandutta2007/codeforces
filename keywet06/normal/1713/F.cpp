#include <bits/stdc++.h>

const int N = 1 << 20;

int n;
int a[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k = 0; k < i && (j | i | k) < n; ++k) a[j | i | k] ^= a[j | k];
        }
    }
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k = 0; k < i && (j | i | k) < n; ++k) a[j | k] ^= a[j | i | k];
        }
    }
    for (int i = n - 1; i >= 0; --i) std::cout << a[i] << " \n"[!i];
    return 0;
}