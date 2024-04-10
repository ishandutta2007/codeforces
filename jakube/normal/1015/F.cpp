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

class PrefixAutomaton {
public:
    PrefixAutomaton(std::string str) : s(str) {
        s += '#';
        int n = s.size();
        pi = prefix_function(s);
        aut.assign(n, std::vector<int>(2));
        for (int i = 0; i < n; i++) {
            for (int c = 0; c < 2; c++) {
                if (i > 0 && '(' + c != s[i])
                    aut[i][c] = aut[pi[i-1]][c];
                else
                    aut[i][c] = i + ('(' + c == s[i]);
            }
        }
    }

    int transition(int state, char c) {
        return aut[state][c - '('];
    }

    static std::vector<int> prefix_function(std::string s) {
        int n = (int)s.length();
        std::vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }

private:
    std::string s;
    std::vector<int> pi;
    std::vector<std::vector<int>> aut;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<ModInt>> dp(2*n + 1, vector<ModInt>(2 * n + 2, 0));
    dp[0][0] = 1;
    for (int len = 1; len <= 2*n; len++) {
        dp[len][0] = dp[len-1][1];
        for (int st = 1; st <= 2*n; st++) {
            dp[len][st] = dp[len-1][st-1] + dp[len-1][st+1];
        }
    }

    PrefixAutomaton aut(s);

    vector<vector<vector<ModInt>>> dp2(2*n+2, vector<vector<ModInt>>(2*n+2, vector<ModInt>(2*n+2, 0)));
    dp2[0][0][0] = 1;
    ModInt total = 0;
    for (int l = 0; l <= 2*n; l++) {
        for (int b = 0; b <= min((int)s.size(), 2*n); b++) {
            int rem = 2*n - l;
            for (int st = 0; st <= rem; st++) {
                if (b == (int)s.size())
                    total += dp2[l][b][st] * dp[rem][st];
                else {
                    if (l < 2*n) {
                        if (st)
                            dp2[l+1][aut.transition(b, ')')][st-1] += dp2[l][b][st];
                        if (st < 2*n)
                            dp2[l+1][aut.transition(b, '(')][st+1] += dp2[l][b][st];
                    }
                }
            }
        }
    }
    cout << total << '\n';
}