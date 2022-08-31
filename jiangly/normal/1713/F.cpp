#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> work(std::vector<int> a) {
    if (a.empty()) {
        return a;
    }
    
    const int n = a.size();
    int N = 1;
    while (N < n) {
        N *= 2;
    }
    
    std::vector<int> b(N);
    std::copy(a.begin(), a.end(), b.begin() + N - n);
    for (int i = 1; i < N; i *= 2) {
        for (int j = 0; j < N; j += 2 * i) {
            for (int k = 0; k < i; k++) {
                b[i + j + k] ^= b[j + k];
            }
        }
    }
    
    std::vector c(b.begin() + n, b.end());
    c = work(c);
    std::copy(c.begin(), c.end(), b.begin());
    std::copy(a.begin(), a.end(), b.begin() + N - n);
    
    for (int i = 1; i < N; i *= 2) {
        for (int j = 0; j < N; j += 2 * i) {
            for (int k = 0; k < i; k++) {
                b[i + j + k] ^= b[j + k];
            }
        }
    }
    
    for (int i = n; i < N; i++) {
        assert(b[i] == 0);
    }
    b.resize(n);
    return b;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::reverse(a.begin(), a.end());
    a = work(a);
    std::reverse(a.begin(), a.end());
    
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
    
    return 0;
}