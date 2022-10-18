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
using DP = array<ModInt, 3>;

vector<vector<int>> children;

DP dfs(int v) {
    if (children[v].empty()) {
        return {1, 1, 0};
    }

    DP dp;
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 0;

    for (int u : children[v]) {
        DP cur = dfs(u);
        // auto sum = lca + not_lca;

        DP neww;
        // >= 2 zeros
        neww[2] = dp[2] * (cur[0] + cur[1] + 2 * cur[2]) + dp[1] * (cur[1] + cur[2]);
        // dp[2] = dp[1] * 1 + dp[2] * (sum + 1);

        // == 1 zeros
        neww[1] = dp[0] * (cur[1] + cur[2]) + dp[1] * (cur[0] + cur[2]);
        // dp[1] = dp[0] * 1 + dp[1] * sum;

        // == 0 zeros
        neww[0] = dp[0] * (cur[0] + cur[2]);
        // dp[0] = dp[0] * sum;

        dp = neww;
    }

    // auto lca = dp[2];
    // auto not_lca = dp[0];
    // return {lca, not_lca};
    return dp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    children.resize(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        children[x-1].push_back(i);
    }

    auto dp = dfs(0);
    cout << dp[0] + dp[2] << endl;
}