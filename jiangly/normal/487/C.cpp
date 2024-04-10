#include <bits/stdc++.h>
using i64 = long long;
int power(int a, int b, int p) {
    int res = 1;
    for (; b > 0; b /= 2, a = i64(a) * a % p) {
        if (b % 2 == 1) {
            res = i64(res) * a % p;
        }
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << "YES\n";
        std::cout << "1\n";
        return 0;
    }
    if (n == 4) {
        std::cout << "YES\n";
        std::cout << "1\n";
        std::cout << "3\n";
        std::cout << "2\n";
        std::cout << "4\n";
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            std::cout << "NO\n";
            return 0;
        }
    }
    std::vector<int> ps;
    int x = n - 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ps.push_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        ps.push_back(x);
    }
    auto check = [&](int r) {
        for (auto p : ps) {
            if (power(r, (n - 1) / p, n) == 1) {
                return false;
            }
        }
        return true;
    };
    int r = 1;
    while (!check(r)) {
        r++;
    }
    std::vector<int> pw(n - 1);
    pw[0] = 1;
    for (int i = 1; i < n - 1; i++) {
        pw[i] = i64(pw[i - 1]) * r % n;
    }
    std::cout << "YES\n";
    std::cout << "1\n";
    for (int i = 1; i <= n - 2; i++) {
        if (i % 2 == 1) {
            std::cout << pw[i] << "\n";
        } else {
            std::cout << pw[n - 1 - i] << "\n";
        }
    }
    std::cout << n << "\n";
    return 0;
}