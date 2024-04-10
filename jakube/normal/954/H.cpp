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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<vector<ModInt>> down(n, vector<ModInt>(2*n, 0));
    for (int i = 0; i < n; i++) {
        down[i][0] = 1;
        for (int j = 1; i + j < n; j++) {
            down[i][j] = down[i][j-1] * a[i+j-1];
        }
    }

    vector<ModInt> res(2*n-1);
    vector<ModInt> dp(n, 1);
    for (int len = 1; len < 2*n - 1; len++) {
        vector<ModInt> dp2(n);
        dp2[0] = down[0][len];
        for (int level = 1; level < n; level++) {
            dp2[level] = down[level][len] + (dp[level-1] - (len == 1 ? 0 : down[level][len-2]));
        }

        for (int level = 0; level < n; level++)
            res[len] += down[0][level] * dp2[level];

        dp = dp2;
    }

    ModInt inv2(1, 2);

    res.erase(res.begin());
    for (auto x : res)
        cout << x * inv2 << " ";
    cout << endl;
}