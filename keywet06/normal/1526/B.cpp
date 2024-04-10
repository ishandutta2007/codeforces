#include <bits/stdc++.h>

const int N = 2005;

int T, n;
int a[N];

int main() {
    a[0] = 1;
    for (int i = 11; i < N; ++i) a[i] |= a[i - 11];
    for (int i = 111; i < N; ++i) a[i] |= a[i - 111];
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        std::cout << (n >= N || a[n] ? "YES" : "NO") << std::endl;
    }
    return 0;
}