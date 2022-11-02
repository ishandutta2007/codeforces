#include <bits/stdc++.h>

using int64 = long long;

const int P = 998244353;

int norm(int x) {
    if (x < 0) x += P;
    if (x >= P) x -= P;
    return x;
}

template <class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b & 1) res *= a;
    }
    return res;
}

struct MI {
    int x;
    MI(int x = 0) : x(norm(x)) {}
    int val() const { return x; }
    MI operator-() const { return MI(norm(P - x)); }
    MI inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    MI &operator*=(const MI &rhs) {
        x = int64(x) * rhs.x % P;
        return *this;
    }
    MI &operator+=(const MI &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    MI &operator-=(const MI &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    MI &operator/=(const MI &rhs) { return *this *= rhs.inv(); }
    friend MI operator*(const MI &lhs, const MI &rhs) {
        MI res = lhs;
        res *= rhs;
        return res;
    }
    friend MI operator+(const MI &lhs, const MI &rhs) {
        MI res = lhs;
        res += rhs;
        return res;
    }
    friend MI operator-(const MI &lhs, const MI &rhs) {
        MI res = lhs;
        res -= rhs;
        return res;
    }
    friend MI operator/(const MI &lhs, const MI &rhs) {
        MI res = lhs;
        res /= rhs;
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }
    std::vector cnt(n, std::vector<int>(26));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            cnt[i][j] = std::count(s[i].begin(), s[i].end(), 'a' + j);
        }
    }
    std::vector<int> min(26, 1E9);
    std::vector<MI> f(1 << n);
    std::function<void(int, int)> dfs = [&](int x, int s) {
        if (x == n) {
            MI v = 1;
            for (int i = 0; i < 26; ++i) v *= min[i] + 1;
            f[s] = v;
            return;
        }
        dfs(x + 1, s);
        auto tmp = min;
        for (int i = 0; i < 26; ++i) min[i] = std::min(min[i], cnt[x][i]);
        dfs(x + 1, s | 1 << x), min = std::move(tmp);
    };
    dfs(0, 0);
    for (int i = 1; i < (1 << n); i *= 2) {
        for (int j = 0; j < (1 << n); j += 2 * i) {
            for (int k = 0; k < i; ++k) f[j + k] -= f[i + j + k];
        }
    }
    f[0] = 0;
    for (int i = 1; i < (1 << n); i *= 2) {
        for (int j = 0; j < (1 << n); j += 2 * i) {
            for (int k = 0; k < i; ++k) f[i + j + k] += f[j + k];
        }
    }
    int64 ans = 0;
    for (int s = 0; s < (1 << n); ++s) {
        int64 v = (f[(1 << n) - 1] - f[(1 << n) - 1 - s]).val();
        int k = 0, c = 0;
        for (int i = 0; i < n; ++i) {
            if (s >> i & 1) c += i + 1, ++k;
        }
        v *= c * k, ans ^= v;
    }
    std::cout << ans << "\n";
    return 0;
}