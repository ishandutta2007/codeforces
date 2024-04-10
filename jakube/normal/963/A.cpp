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
        value *= b.value;
        value %= MOD;
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

    long long value;
};

using ModInt = Modular<1'000'000'009>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;

    auto aib = inverse(ModInt{a}) * ModInt{b};
    auto factor = power(ModInt{a}, n);

    ModInt sum;
    for (char c : s) {
        if (c == '-')
            sum -= factor;
        else
            sum += factor;
        factor *= aib;
    }

    int repeat = (n + 1) / k;
    ModInt res;

    factor = power(inverse(ModInt{a}) * b, k);
    if (factor.value == 1) {
        res = sum * repeat;
    } else {
        res = sum * (1 - power(factor, repeat)) * inverse(1 - factor);
    }

    cout << res << endl;
}