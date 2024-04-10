#include <bits/stdc++.h>

int n, k, p;

std::string s;

int op(int x, int y) {
    for (int i = 0; i < k; ++i) {
        if (s[i % x] != s[i % y]) return s[i % x] < s[i % y];
    }
    return 0;
}

int main() {
    std::cin >> n >> k;
    std::cin >> s;
    p = 1;
    for (int i = 2; i <= n; ++i) {
        if (op(i, p)) p = i;
    }
    for (int i = 0; i < k; ++i) std::cout << s[i % p];
    std::cout << std::endl;
    return 0;
}