#include <bits/stdc++.h>

const int C = 26;

char ch;
int n, num, s;
int a[C];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for (int i = 0; i < n; ++i) std::cin >> a[i], num += a[i] & 1;
    s = a[0];
    for (int i = 1; i < n; ++i) s = std::__gcd(s, a[i]);
    if (n == 1) {
        std::cout << a[0] << std::endl;
        for (int i = 0; i < a[0]; ++i) std::cout << 'a';
        std::cout << std::endl;
        return 0;
    }
    if (num > 1) {
        std::cout << 0 << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < a[i]; ++j) std::cout << char('a' + i);
        }
        std::cout << std::endl;
        return 0;
    }
    std::cout << s << std::endl;
    s /= !(s & 1) + 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] & 1) ch = 'a' + i;
    }
    for (int i = 0; i < n; ++i) a[i] /= s;
    for (int c = 0; c < s; ++c) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < a[i] / 2; ++j) std::cout << char('a' + i);
        }
        if (ch) std::cout << ch;
        for (int i = n - 1; ~i; --i) {
            for (int j = 0; j < a[i] / 2; ++j) std::cout << char('a' + i);
        }
    }
    std::cout << std::endl;
    return 0;
}