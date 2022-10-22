#include "bits/stdc++.h"

using namespace std;

constexpr int mod = 1e9 + 7;

int normalize(int x) {
    if (x >= mod) {
        x -= mod;
    }
    if (x < 0) {
        x += mod;
    }
    return x;
}

template<typename T>
T power(T a, int n) {
    T res = 1;
    for (; n; n /= 2, a *= a) {
        if (n % 2) {
            res *= a;
        }
    }
    return res;
}

class Mint {
public:
    int x;

    Mint(int x = 0) : x(normalize(x)) {}
    Mint(long long x) : x(normalize(x % mod)) {}

    int val() const {
        return x;
    }

    Mint operator-() const {
        return Mint(normalize(mod - x));
    }

    Mint inv() const {
        return power(*this, mod - 2);
    }

    Mint& operator*=(const Mint& rhs) {
        x = x * 1ll * rhs.x % mod;
        return *this;
    }

    Mint& operator+=(const Mint& rhs) {
        x = normalize(x + rhs.x);
        return *this;
    }

    Mint& operator-=(const Mint& rhs) {
        x = normalize(x - rhs.x);
        return *this;
    }

    Mint& operator/=(const Mint& rhs) {
        return *this *= rhs.inv();
    }

    friend Mint operator*(const Mint& lhs, const Mint& rhs) {
        Mint res = lhs;
        res *= rhs;
        return res;
    }

    friend Mint operator+(const Mint& lhs, const Mint& rhs) {
        Mint res = lhs;
        res += rhs;
        return res;
    }
    friend Mint operator-(const Mint& lhs, const Mint& rhs) {
        Mint res = lhs;
        res -= rhs;
        return res;
    }
    friend Mint operator/(const Mint& lhs, const Mint& rhs) {
        Mint res = lhs;
        res /= rhs;
        return res;
    }
};

using mint = Mint;

vector<mint> fact(1, 1);
vector<mint> inv_fact(1, 1);

void fast(int n) {
    while ((int) fact.size() < n + 1) {
        fact.push_back(fact.back() * (int) fact.size());
    }
    inv_fact.resize(n + 1, 1);
    inv_fact[n] = 1 / fact[n];
    for (int i = n - 1; i >= 2; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1);
    }
}

mint C(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    while ((int) fact.size() < n + 1) {
        fact.push_back(fact.back() * (int) fact.size());
        inv_fact.push_back(fact.back().inv());
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    vector<mint> ans(n);
    mint all = power(mint(2), n);
    vector<mint> dp(n + 1), pref(n + 1);
    dp[n] = 1;
    dp[n - 1] = 1;
    pref[n] = 1;
    pref[n - 1] = 2;
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = pref[i + 1];
        int j = min(n - i, i + 1) + i;
        if (j <= n) {
            dp[i] -= pref[j];
        }
        pref[i] = pref[i + 1] + dp[i];
    }
    for (int i = 1; i < n; i++) {
        int need = (i + 2) / 2;
        ans[i] = power(mint(2), i + 1 - need) * dp[i];
    }
    for (auto& x : ans) {
        x = x / all * mint(2);
        cout << x.x << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}