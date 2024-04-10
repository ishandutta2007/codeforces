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

std::vector<int> largest;

void computePrimesLargest(int n) {
    largest.resize(n + 1);
    std::iota(largest.begin(), largest.end(), 0);

    for (int i = 2; i <= n; i++) {
        if (i == largest[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                largest[j] = i;
            }
        }
    }
}

std::vector<int> divisors(int x) {
    std::vector<int> d;
    d.push_back(1);

    while (x > 1) {
        int p = largest[x];
        int c = 0;
        while (largest[x] == p) {
            c++;
            x /= p;
        }
        std::vector<int> d2;
        int b = 1;
        for (int j = 0; j <= c; j++) {
            for (int x : d) {
                d2.push_back(x * b);
            }
            b *= p;
        }
        d.swap(d2);
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    
    computePrimesLargest(1'000'000);

    vector<ModInt> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        auto divs = divisors(v[i]);
        sort(divs.begin(), divs.end());
        reverse(divs.begin(), divs.end());
        
        for (int d : divs) {
            if (d <= n) {
                dp[d] += dp[d-1];
            }
        }
    }
    ModInt sum = 0;
    for (auto s : dp) {
        sum += s;
    }
    cout << sum - 1 << '\n';
}