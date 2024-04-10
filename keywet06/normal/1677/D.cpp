#include <bits/stdc++.h>

const int P = 998244353;

using int64 = long long;

int Fix(int x) {
    if (x < 0) x += P;
    if (x >= P) x -= P;
    return x;
}

template <class T>
T Pow(T a, int64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) res *= a;
    }
    return res;
}

struct MInt {
    int x;
    MInt(int x = 0) : x(Fix(x)) {}
    MInt(int64 x) : x(Fix(x % P)) {}
    int val() const { return x; }
    MInt operator-() const { return MInt(Fix(P - x)); }
    MInt inv() const {
        assert(x != 0);
        return Pow(*this, P - 2);
    }
    MInt &operator*=(const MInt &rhs) {
        x = int64(x) * rhs.x % P;
        return *this;
    }
    MInt &operator+=(const MInt &rhs) {
        x = Fix(x + rhs.x);
        return *this;
    }
    MInt &operator-=(const MInt &rhs) {
        x = Fix(x - rhs.x);
        return *this;
    }
    MInt &operator/=(const MInt &rhs) { return *this *= rhs.inv(); }
    friend MInt operator*(const MInt &lhs, const MInt &rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend MInt operator+(const MInt &lhs, const MInt &rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend MInt operator-(const MInt &lhs, const MInt &rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend MInt operator/(const MInt &lhs, const MInt &rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, MInt &a) {
        int64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
};

void Solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    for (int i = n - k; i < n; ++i) {
        if (v[i] > 0) return void(std::cout << "0\n");
    }
    MInt Ans = 1;
    for (int i = 1; i <= k; ++i) Ans *= i;
    for (int i = 0; i < n - k; ++i) {
        if (v[i] == 0) {
            Ans *= k + 1;
        } else if (v[i] == -1) {
            Ans *= i + k + 1;
        }
    }
    std::cout << Ans.val() << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) Solve();
    return 0;
}