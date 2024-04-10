#include <bits/stdc++.h>

int n, k;

inline bool read() { return bool(std::cin >> n >> k); }

const int mod = 1e9 + 7;

int gcd(int a, int b, int& x, int& y) {
    if (!a) return x = 0, y = 1, b;
    int xx, yy, g = gcd(b % a, a, xx, yy);
    return x = yy - b / a * xx, y = xx, g;
}

inline int fix(int n) { return n %= mod, (n < 0) && (n += mod), n; }

inline int inv(int a) {
    int x, y;
    return assert(gcd(a, mod, x, y) == 1), fix(x);
}

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return int(a * 1ll * b % mod); }
inline int ds(int a, int b) { return mul(a, inv(b)); }

inline int binPow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

int calc(const std::vector<int>& y, int x) {
    int ans = 0;
    int k = 1;
    for (int j = 1; j < y.size(); ++j) {
        k = mul(k, fix(x - j)), k = ds(k, fix(0 - j));
    }
    for (int i = 0; i < y.size(); ++i) {
        ans = add(ans, mul(y[i], k));
        if (i + 1 >= y.size()) break;
        k = mul(k, ds(fix(x - i), fix(x - (i + 1))));
        k = mul(k, ds(fix(i - (y.size() - 1)), fix(i + 1)));
    }
    return ans;
}

inline int solve() {
    std::vector<int> y;
    int sum = 0;
    y.push_back(sum);
    for (int i = 0; i <= k; ++i) {
        sum = add(sum, binPow(i + 1, k));
        y.push_back(sum);
    }
    return n < y.size() ? y[n] : calc(y, n);
}

int main() {
    while (read()) std::cout << solve() << std::endl;
    return 0;
}