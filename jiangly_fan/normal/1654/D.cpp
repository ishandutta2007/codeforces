#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<vector<LL>> pf(n + 1);
        for (int i = 2; i <= n; i += 1)
            if (pf[i].empty())
                for (int j = i; j <= n; j += i)
                    pf[j].push_back(i);
        vector<int> mpf(n + 1), cur(n + 1);
        vector<vector<tuple<int, int, int>>> G(n + 1);
        for (int i = 1; i < n; i += 1) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            G[u].emplace_back(v, x, y);
            G[v].emplace_back(u, y, x);
        }
        vector<LL> f(n + 1);
        f[1] = 1;
        function<void(int, int)> DFS = [&](int u, int par) {
            for (auto [v, x, y] : G[u]) if (v != par) {
                f[v] = f[u] * y % mod * power(x, mod - 2) % mod;
                for (int i : pf[x])
                    for (int j = x; j % i == 0; j /= i)
                        cur[i] -= 1;
                for (int i : pf[y])
                    for (int j = y; j % i == 0; j /= i)
                        cur[i] += 1;
                for (int i : pf[x]) mpf[i] = max(mpf[i], -cur[i]);
                for (int i : pf[y]) mpf[i] = max(mpf[i], -cur[i]);
                DFS(v, u);
                for (int i : pf[x])
                    for (int j = x; j % i == 0; j /= i)
                        cur[i] += 1;
                for (int i : pf[y])
                    for (int j = y; j % i == 0; j /= i)
                        cur[i] -= 1;
            }
        };
        DFS(1, 0);
        LL ans = 0;
        for (int i = 1; i <= n; i += 1) ans = (ans + f[i]) % mod;
        for (int i = 1; i <= n; i += 1) ans = ans * power(i, mpf[i]) % mod;
        cout << ans << "\n";
    }
    return 0;
}