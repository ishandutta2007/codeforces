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

    friend Modular operator-(Modular const a) {
        return 0 - a;
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

using ModInt = Modular<998'244'353>;

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

    int n;
    cin >> n;
    precompute_factorial(n);
    
    ModInt result = f[n];
    for (int i = 1; i < n; i++) {
        result += Binomial(n, i) * (f[i] - 1) * f[n-i];
    }
    cout << result << '\n';
    
}