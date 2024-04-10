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

vector<vector<int>> adj;
vector<bool> neww, visited;
vector<int> side;
vector<ModInt> power2s;
int n;

ModInt f(vector<pair<int, int>> edges) {
    vector<int> order;
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (neww[u]) {
            order.push_back(u);
            neww[u] = false;
        }
        if (neww[v]) {
            order.push_back(v);
            neww[v] = false;
        }
    }

    ModInt result = 1;
    for (int start : order) {
        if (visited[start]) continue;

        queue<int> q;
        q.push(start);
        side[start] = 0;
        visited[start] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : adj[cur]) {
                if (visited[next]) {
                    if (side[cur] == side[next])
                        return 0;
                } else {
                    side[next] = 1 ^ side[cur];
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        result *= 2;
    }

    for (auto u : order) {
        adj[u].clear();
        neww[u] = true;
        visited[u] = false;
    }

    return result * power2s[n - (int)order.size()];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, k;
    cin >> n >> m >> k;
    vector<long long> c(n);
    for (auto& x : c)
        cin >> x;
    adj.resize(n);
    neww.assign(n, true);
    visited.assign(n, false);
    side.assign(n, 0);
    
    power2s.assign(n+1, 1);
    for (int i = 1; i <= n; i++) {
        power2s[i] = power2s[i-1] * 2;
    }

    map<long long, vector<pair<int, int>>> ma;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ma[c[u] ^ c[v]].push_back({u, v});
    }

    ModInt one_x = power(ModInt(2), n);
    ModInt result = one_x * power(ModInt(2), k);

    for (auto [x, edges] : ma) {
        result -= one_x;
        result += f(edges);
    }
    cout << result << '\n';
}