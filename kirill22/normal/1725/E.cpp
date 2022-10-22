#include "bits/stdc++.h"

using namespace std;

const int mod = 998244353;
const int N = 2e5 + 1;
int n, dp[N], cnt[N], f[N], calc[N], ans = 0, res = 0;
vector<int> prime, g[N], p[N];
map<int, int> G[N];

void dfs(int v, int pr) {
    calc[v] = res;
    auto add = [&] (int x, int c) {
        int l = 0;
        if (G[v].find(x) != G[v].end()) {
            l = G[v][x];
        }
        int r = cnt[x] - l;
        calc[v] = (0ll + calc[v] - f[l] - f[r] + mod + mod) % mod;
        G[v][x] += c;
        l = G[v][x];
        r = cnt[x] - l;
        calc[v] = (0ll + calc[v] + f[l] + f[r]) % mod;
    };
    for (auto x : p[v]) {
        add(x, 1);
    }
    for (auto u : g[v]) {
        if (u != pr) {
            dfs(u, v);
            ans = (0ll + ans + res - calc[u] + mod) % mod;
            if ((int) G[v].size() < (int) G[u].size()) {
                swap(G[v], G[u]);
                swap(calc[v], calc[u]);
            }
            for (auto [x, c] : G[u]) {
                add(x, c);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 3; i < N; i++) {
        f[i] = (i * 1ll * (i - 1) * (i - 2) / 6) % mod;
    }
    iota(dp, dp + N, 0);
    for (int i = 2; i < N; i++) {
        if (dp[i] == i) {
            prime.push_back(i);
        }
        for (auto x : prime) {
            if (x <= dp[i] && x * 1ll * i < N) {
                dp[x * i] = x;
            } else {
                break;
            }
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x > 1) {
            int d = dp[x];
            while (x % d == 0) {
                x /= d;
            }
            cnt[d]++;
            p[i].push_back(d);
        }
    }
    for (int i = 0; i < N; i++) {
        res = (res + f[cnt[i]]) % mod;
    }
    for (int i = 0; i + 1 < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);
    cout << ans;
}