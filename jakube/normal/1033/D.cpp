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

using ModInt = Modular<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto& x : v)
        cin >> x;
    
    map<long long, int> cnts;
    map<long long, int> cnts_unknown;

    for (auto x : v) {
        // check if p^2
        long long y = round(sqrt(x));
        if (y * y == x) {
            // check if p^4
            long long z = round(sqrt(y));
            if (z * z == y) {
                cnts[z] += 4;
            } else {
                cnts[y] += 2;
            }
            continue;
        }

        y = round(pow(x, 1 / 3.));
        if (y * y * y == x) {
            // try x = p^3
            cnts[y] += 3;
            continue;
        }
            
        // x = p * q
        // try to decompose
        bool decomposed = false;
        for (auto y : v) {
            if (x != y && gcd(x, y) > 1) {
                auto g = gcd(x, y);
                cnts[g]++;
                cnts[x / g]++;
                decomposed = true;
                break;
            }
        }
        if (!decomposed) {
            cnts_unknown[x]++;
        }
    }

    ModInt result = 1;
    for (auto [p, c] : cnts)
        result *= c + 1;
    for (auto [p, c] : cnts_unknown) {
        result *= c + 1;
        result *= c + 1;
    }
    cout << result << endl;
}