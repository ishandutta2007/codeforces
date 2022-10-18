#include "bits/stdc++.h"
using namespace std;

template <int MOD>
class Modular {
// using ModInt = Modular<1'000'000'007>;
public:
    Modular(long long v=0) {
        value = v % MOD;
        if (value < 0)
            value += MOD;
    }

    Modular& operator+=(Modular const& b) {
        value += b.value;
        if (value >= MOD)
            value -= MOD;
        return *this;
    }

    Modular& operator*=(Modular const& b) {
        value = (long long)value * b.value % MOD;
        return *this;
    }

    friend Modular operator*(Modular a, Modular const b) {
        return a *= b;
    }

    friend std::ostream& operator<<(std::ostream &os, Modular const& a) {
        return os << a.value;
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

bool excellent(long long sum, int a, int b) {
    while (sum) {
        int d = sum % 10;
        if (d != a && d != b)
            return false;
        sum /= 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, n;
    cin >> a >> b >> n;
    precompute_factorial(n);

    ModInt res;
    for (int A = 0; A <= n; A++) {
        if (excellent(A * a + (n-A) * b, a, b))
            res += Binomial(n, A);
    }
    cout << res << '\n';
}