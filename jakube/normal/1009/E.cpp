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
    vector<int> a(n);
    for (int& x : a)
        cin >> x;

    // dp[i] = sum of all possibilities to go from 0 to i
    // dp[i] = 
    //    1    => (a1 * 2^{i-2}) + dp[i-1]                   // *2^{i-2}
    //    2    => (a1 + a2)^{i-3} + dp[i-2]                  // *2^{i-3}
    //    ...                                                // *2
    //    i-1  => (a1 + ... + ai-1)*2^(i -1 -(i-1)) + dp[1]  // *1
    //    none => a1 + a2 + ... + ai + dp[0]                 // *1
    // dp[i] = sum_{j=1}^i sum_{k=1}^j ai + dp[i-j]
    // = sum_{j=1}^j * dp[i-j] + 
    
    ModInt cur = 0;
    vector<ModInt> psum2(n + 1, 0);
    vector<ModInt> psum(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cur += a[i-1];
        psum2[i] = psum2[i-1]*2 + a[i-1];
    }

    vector<ModInt> dp(n+1, 0);
    ModInt dp_sum = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp_sum + psum2[i];
        dp_sum += dp[i];
    }

    cout << dp[n] << '\n';
}