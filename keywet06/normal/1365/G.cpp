#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> w(n);
    for (int i = 0, j = 0; i < n; ++i) {
        while (__builtin_popcount(j) != 6) ++j;
        w[i] = j++;
    }
    long long a[13];
    for (int i = 0; i < 13; ++i) {
        std::vector<int> v;
        for (int j = 0; j < n; ++j)
            if (w[j] >> i & 1) v.push_back(j);
        if (v.empty()) {
            a[i] = 0;
        } else {
            std::cout << "? " << v.size();
            for (auto j : v) std::cout << " " << j + 1;
            std::cout << std::endl;
            std::cin >> a[i];
        }
    }
    std::vector<long long> p(n);
    for (int i = 0; i < 63; ++i) {
        int x = 0;
        for (int j = 0; j < 13; ++j)
            if (a[j] >> i & 1) x |= 1 << j;
        if (!x) {
            continue;
        } else if (__builtin_popcount(x) > 6) {
            for (int j = 0; j < n; ++j) p[j] |= 1ll << i;
        } else {
            for (int j = 0; j < n; ++j) {
                if (w[j] != x) p[j] |= 1ll << i;
            }
        }
    }
    std::cout << "!";
    for (auto i : p) std::cout << " " << i;
    std::cout << std::endl;
    return 0;
}