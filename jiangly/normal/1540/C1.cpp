#include <bits/stdc++.h>
constexpr int P = 1000000007;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
};
constexpr int C = 10000;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    std::vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> b[i];
    }
    std::vector<int> s(n);
    for (int i = 0; i < n - 1; i++) {
        s[i + 1] = s[i] + b[i];
    }
    std::vector<int> ss(s);
    for (int i = 1; i < n; i++) {
        ss[i] += ss[i - 1];
    }
    int q;
    std::cin >> q;
    int x;
    std::cin >> x;
    std::vector<Z> dp(C + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = C; j >= 0; j--) {
            Z v;
            for (int x = 0; x <= c[i] && x <= j; x++) {
                v += dp[j - x];
            }
            dp[j] = v;
        }
        for (int j = 0; j < (i + 1) * x + ss[i] && j <= C; j++) {
            dp[j] = 0;
        }
    }
    auto ans = std::accumulate(dp.begin(), dp.end(), Z(0));
    std::cout << ans.val() << "\n";
    return 0;
}