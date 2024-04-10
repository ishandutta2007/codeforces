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

    friend bool operator==(Modular const& a, Modular const& b) {
        return a.value == b.value;
    }

    friend bool operator!=(Modular const& a, Modular const& b) {
        return a.value != b.value;
    }

    long long value;
};

using ModInt = Modular<1'000'000'007>;

template <typename T>
struct DP3 : vector<vector<vector<T>>> {
    DP3(int a, int b, int c, T val)
        : vector<vector<vector<T>>>(a, 
                vector<vector<T>>(b, 
                    vector<T>(c, val))) { }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;

    DP3 dp(max(x+1, 2), n+1, n+1, ModInt(0));

    // fill dp[0] and dp[1]
    for (int k = 0; k < 2; k++) {
        char c = '0' + k;
        dp[k][0][0] = 2;
        dp[k][0][1] = s[0] == c;

        for (int i = 1; i < n; i++) {
            dp[k][i][i+1] = s[i] == c;
            dp[k][i][i] = 1;
        }

        dp[k][n][n] = 2;
    }

    for (int k = 2; k <= x; k++) {
        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                for (int t = i; t <= j; t++) {
                    dp[k][i][j] += dp[k-1][i][t] * dp[k-2][t][j];
                }
            }
        }
    }

    cout <<  dp[x][0][n] << endl;
}