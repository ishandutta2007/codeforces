#include <bits/stdc++.h>

int n;

std::string l, r;

std::string inc(std::string x) {
    int c = x.length() - 1;
    ++x.back();
    while (c && x[c] > '1') x[c] = '0', ++x[--c];
    if (x[0] > '1') x[0] = '0', x = '1' + x;
    return x;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> l >> r;
    if (l == r) return std::cout << l << std::endl, 0;
    if (l[0] == '0') return std::cout << std::string(n, '1') << std::endl, 0;
    std::cout << (inc(l) == r || r.back() == '1' ? r : inc(r)) << std::endl;
    return 0;
}