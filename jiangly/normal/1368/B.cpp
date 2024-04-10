#include <bits/stdc++.h>
std::string s = "codeforces";
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long k;
    std::cin >> k;
    for (int l = 10; ; ++l) {
        int c[10] = {};
        for (int i = 0, j = l; i < 10; ++i) {
            c[i] = j / (10 - i);
            j -= c[i];
        }
        long long res = 1;
        for (int i = 0; i < 10; ++i)
            res *= c[i];
        if (res < k)
            continue;
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < c[i]; ++j)
                std::cout << s[i];
        std::cout << "\n";
        return 0;
    }
    return 0;
}