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

using ModInt = Modular<1'000'000'007>;

ModInt f(long long r) {
    long long cur = 1;
    long long power = 1;
    bool odd = true;
    ModInt ans = 0;
    long long next_odd = 1;
    long long next_even = 2;
    while (cur + power - 1 <= r) {
        if (odd) {
            ans += (next_odd + power - 1) * ModInt(power);
            next_odd += 2 * power;
        } else {
            ans += (next_even + power - 1) * ModInt(power);
            next_even += 2 * power;
        }
        cur += power;
        power *= 2;
        odd = !odd;
    }

    long long rem = r - cur + 1;
    if (odd) {
        ans += (next_odd + rem - 1) * ModInt(rem);
    } else {
        ans += (next_even + rem - 1) * ModInt(rem);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long l, r;
    cin >> l >> r;
    cout << f(r) - f(l-1) << '\n';
}