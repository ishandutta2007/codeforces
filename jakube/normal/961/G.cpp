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
};

using ModInt = Modular<1'000'000'007>;

int MOD = 1'000'000'007;

vector<ModInt> f;
vector<ModInt> f_inv;

void precompute_factorial(int n, long long m) {
    vector<int> inv(n+1, 1);
    for (int i = 2; i <= n; i++) {
        inv[i] = (m - (m / i) * inv[m % i] % m) % m;
    }

    f.resize(n + 1, 1);
    f_inv.resize(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        f[i] = f[i-1] * i;
        f_inv[i] = f_inv[i-1] * inv[i];
    }
}

ModInt Binomial(int n, int k) {
    return f[n] * f_inv[k] * f_inv[n-k];
}

ModInt Stirling2nd(int n, int k) {
    ModInt res;
    for (int j = 0; j <= k; j++) {
        ModInt x = Binomial(k, j) * power(ModInt(j), n);
        if ((k - j) & 1)
            res -= x;
        else
            res += x;
    }
    return res * f_inv[k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, k;
    cin >> n >> k;
    ModInt sum;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
    }

    precompute_factorial(n, 1'000'000'007);
    // {n;k} + {n-1;k}*(n-1)
    cout << (sum * (Stirling2nd(n, k) + (n-1)*Stirling2nd(n-1, k))) << '\n';
}