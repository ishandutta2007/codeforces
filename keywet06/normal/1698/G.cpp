#include <bits/stdc++.h>

using int64 = long long;

using Poly = std::bitset<70>;

int deg(const Poly &a) {
    for (int i = 69; i >= 0; --i) {
        if (a[i]) return i;
    }
    return -1;
}

Poly operator+(const Poly &a, const Poly &b) { return a ^ b; }

Poly operator-(const Poly &a, const Poly &b) { return a ^ b; }

Poly operator%(Poly a, const Poly &b) {
    int n = deg(a), m = deg(b);
    for (int i = n; i >= m; --i) {
        if (a[i]) a ^= b << (i - m);
    }
    return a;
}

Poly operator*(const Poly &a, const Poly &b) {
    Poly c;
    int n = deg(a);
    for (int i = 0; i <= n; ++i) {
        if (a[i]) c ^= b << i;
    }
    return c;
}

Poly operator/(Poly a, const Poly &b) {
    Poly c;
    int n = deg(a), m = deg(b);
    for (int i = n; i >= m; --i) {
        if (a[i]) a ^= b << (i - m), c[i - m] = 1;
    }
    return c;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    if (s.find('1') == std::string::npos) return std::cout << "-1\n", 0;
    int P = s.find('1');
    s = s.substr(P);
    while (s.back() == '0') s.pop_back();
    int64 m = 0;
    int n = s.length() - 1;
    for (int i = 0; i <= n; ++i) {
        if (s[i] == '1') m |= 1LL << i;
    }
    if (m == 1) {
        std::cout << P + 1 << " " << P + 2 << "\n";
        return 0;
    }
    auto inverse = [&](Poly a, Poly b) {
        Poly m = 0, n = 1, t;
        Poly x = 1, y = 0;
        while (b != 0) {
            t = m, m = x - a / b * m, x = t;
            t = n, n = y - a / b * n, y = t;
            t = b, b = a % b, a = t;
        }
        return x;
    };
    auto invx = inverse(2, m);
    int t = 1 << (n / 2 + 1);
    std::unordered_map<Poly, int> r;
    Poly p = 1, pinv = 1;
    for (int i = 0; i < t; ++i) {
        if (!r.contains(pinv)) r[pinv] = i;
        p = p * 2 % m;
        pinv = pinv * invx % m;
    }
    Poly pp = Poly(2) % m;
    for (int i = 0;; ++i) {
        if (r.contains(pp)) {
            int j = r[pp];
            int64 Q = 1LL * t * i + j + 1;
            std::cout << P + 1 << " " << P + Q + 1 << "\n";
            return 0;
        }
        pp = pp * p % m;
    }
}