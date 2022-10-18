#include <bits/stdc++.h>
using namespace std;

template <int MOD>
class Modular {
public:
    Modular(long long v=0) {
        value = v % MOD;
        if (value < 0)
            value += MOD;
    }

    Modular(long long a, long long b) : value(0) {
        *this += a;
        *this /= b;
    }

    Modular& operator+=(Modular const& b) {
        value += b.value;
        if (value >= MOD)
            value -= MOD;
        return *this;
    }

    Modular& operator-=(Modular const& b) {
        value -= b.value;
        if (value < 0)
            value += MOD;
        return *this;
    }

    Modular& operator*=(Modular const& b) {
        value = (long long)value * b.value % MOD;
        return *this;
    }

    friend Modular power(Modular a, long long e) {
        Modular res = 1;
        while (e) {
            if (e & 1)
                res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    friend Modular inverse(Modular a) {
        return power(a, MOD - 2);
    }

    Modular& operator/=(Modular const& b) {
        return *this *= inverse(b);
    }

    friend Modular operator+(Modular a, Modular const b) {
        return a += b;
    }

    friend Modular operator-(Modular a, Modular const b) {
        return a -= b;
    }

    friend Modular operator*(Modular a, Modular const b) {
        return a *= b;
    }

    friend Modular operator/(Modular a, Modular const b) {
        return a /= b;
    }

    friend std::ostream& operator<<(std::ostream &os, Modular const& a) {
        return os << a.value;
    }

    friend bool operator==(Modular const& a, Modular const& b) {
        return a.value == b.value;
    }

    friend bool operator!=(Modular const& a, Modular const& b) {
        return a.value != b.value;
    }

    int value;
    static const int MOD_value = MOD;
};

using ModInt = Modular<1'000'000'007>;

ModInt lagrange_interpolation(std::vector<ModInt> x, std::vector<ModInt> y, ModInt X) {
    ModInt Y = 0;
    int k = x.size() - 1;
    for (int j = 0; j <= k; j++) {
        ModInt num = 1, den = 1;
        for (int m = 0; m <= k; m++) {
            if (m == j) continue;
            num *= (X - x[m]);
            den *= (x[j] - x[m]);
        }
        Y += y[j] * num / den;
    }
    return Y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, D;
    cin >> n >> D;
    vector<int> p(n, 0);
    vector<vector<int>> child(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        child[x-1].push_back(i);
    }

    vector<vector<ModInt>> dp(n, vector<ModInt>(n+1, 1));
    for (int v = n-1; v >= 0; v--) {
        for (int u : child[v]) {
            for (int i = 1; i <= n; i++)
                dp[v][i] *= dp[u][i];
        }
        for (int i = 2; i <= n; i++)
            dp[v][i] += dp[v][i-1];
    }
    dp[0][0] = 0;

    vector<ModInt> y(dp[0].begin(), dp[0].end());
    auto x = y;
    iota(x.begin(), x.end(), 0);
    cout << lagrange_interpolation(x, y, D) << '\n';
}