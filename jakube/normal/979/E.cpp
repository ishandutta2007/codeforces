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

std::vector<ModInt> f;
std::vector<ModInt> f_inv;
std::vector<ModInt> inv;

void precompute_factorial(int n) {
    int m = ModInt::MOD_value;
    f.resize(n + 1, 1);
    inv.resize(n+1, 1);
    f_inv.resize(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        f[i] = f[i-1] * i;
        inv[i] = -(m / i) * inv[m % i];
        f_inv[i] = f_inv[i-1] * inv[i];
    }
}

ModInt Binomial(int n, int k) {
    return f[n] * f_inv[k] * f_inv[n-k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    cin >> n >> p;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    precompute_factorial(n);

    vector<vector<ModInt>> bsum(2, vector<ModInt>(n+1, 0));
    for (int ob = 0; ob <= n; ob++) {
        for (int k = 0; k <= ob; k++) {
            bsum[k&1][ob] += Binomial(ob, k);
        }
    }
    vector<ModInt> powers(n+1, 1);
    for (int i = 1; i <= n; i++) {
        powers[i] = powers[i-1] * 2;
    }

    vector<vector<vector<vector<ModInt>>>> dp(n+1, vector<vector<vector<ModInt>>>(n+1, vector<vector<ModInt>>(n+1, vector<ModInt>(n+1, 0))));
    dp[0][0][0][0] = 1;
    ModInt result = 0;
    for (int i = 1; i <= n; i++) {
        for (int ew = 0; ew <= i; ew++) {
            for (int ow = 0; ew + ow <= i; ow++) {
                for (int eb = 0; ew + ow + eb <= i; eb++) {
                    int ob = i - ew - ow - eb;
                    auto& x = dp[i][ew][ow][eb];
                    if (c[i-1] != 1) {
                        // white
                        auto p = powers[ow + ew + eb - 1];
                        if (ew)
                            x += p * bsum[1][ob] * dp[i-1][ew-1][ow][eb];
                        if (ow)
                            x += p * bsum[0][ob] * dp[i-1][ew][ow-1][eb];
                    }
                    if (c[i-1] != 0) {
                        // black
                        auto p = powers[ew + eb + ob - 1];
                        if (eb)
                            x += p * bsum[1][ow] * dp[i-1][ew][ow][eb-1];
                        if (ob)
                            x += p * bsum[0][ow] * dp[i-1][ew][ow][eb];
                    }
                    if (i == n && ((ow + ob) & 1) == p) {
                        result += x;
                    }
                }
            }
        }
    }

    cout << result << '\n';
}