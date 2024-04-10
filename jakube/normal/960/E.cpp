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

using ModInt = Modular<1'000'000'007>;

ModInt total = 0;
vector<vector<int>> adj;
vector<int> V;

struct S
{
    ModInt odd, even;
};

vector<S> dp;

// count under and prepair
S dfs(int v, int p=-1) {
    S s = {1, 0};
    ModInt paths = 1;
    for (int u : adj[v]) {
        if (u == p)
            continue;

        auto t = dfs(u, v);

        paths += 2 * s.odd * t.even;
        paths -= 2 * s.even * t.odd;

        s.odd += t.even;
        s.even += t.odd;
    }

    total += paths * V[v];

    return dp[v] = s;
}

void dfs2(int v, int p=-1, S t={0, 0}) {
    auto s = dp[v];
    if (p >= 0) {
        t.even -= s.odd;
        t.odd -= s.even;
    }

    ModInt paths = 0;
    paths += s.odd * t.even;
    paths -= s.even * t.odd;
    total += 2 * paths * V[v];

    S next = t;
    swap(next.even, next.odd);
    next.even += s.even;
    next.odd += s.odd;

    for (int u : adj[v]) {
        if (u == p)
            continue;
        dfs2(u, v, next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    V.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }
    adj.resize(n);
    dp.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0);
    dfs2(0);
    cout << total << endl;
}