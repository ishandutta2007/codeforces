#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
int n, m, q;
vector<pii> E[2005];
int mx[2005];
ll dp[2005][2005];

bool operator<(pll a, pll b) {
    return a.first * b.second < b.first * a.second;
}

pll inter(pll a, pll b) {
    return pll(a.second - b.second, b.first - a.first);
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= m; i++) {
        int v, u, w;
        scanf("%d %d %d", &v, &u, &w);
        E[v].emplace_back(u, w);
        E[u].emplace_back(v, w);
        mx[v] = max(mx[v], w);
        mx[u] = max(mx[u], w);
    }
    for (int i = 2; i <= n; i++) dp[0][i] = -1e18;
    int ans = 0;
    for (int d = 1; d <= m; d++) {
        ll a = -1e18;
        for (int x = 1; x <= n; x++) {
            ll v = -1e18;
            for (auto [i, c] : E[x]) {
                v = max(v, dp[d - 1][i] + c);
            }
            dp[d][x] = v;
            a = max(a, v);
        }
        ans = (ans + a) % mod;
    }
    vector<int> V;
    for (int i = 1; i <= n; i++) V.push_back(i);
    sort(V.begin(), V.end(), [&](int a, int b) { return mx[a] < mx[b]; });
    vector<pll> L;
    for (int x : V) {
        ll v = -1e18;
        for (int d = 1; d <= m; d++) {
            v = max(v, dp[d][x] - (ll)d * mx[x]);
        }
        if (!L.empty() && L.back().first == mx[x]) {
            if (L.back().second < v) L.pop_back();
            else continue;
        }
        pll l = pll(mx[x], v);
        int s;
        while ((s = L.size()) > 1 && !(inter(L[s - 2], L[s - 1]) < inter(L[s - 1], l))) L.pop_back();
        L.push_back(l);
    }
    for (int i = 0; i < L.size(); i++) {
        ll l = m + 1, r = q;
        if (i > 0) {
            ll b, a;
            tie(b, a) = inter(L[i - 1], L[i]);
            if (b >= 0) {
                l = (b + a - 1) / a;
            }
        }
        if (i + 1 < L.size()) {
            ll b, a;
            tie(b, a) = inter(L[i], L[i + 1]);
            if (b >= 0) r = b / a;
            else continue;
        }
        l = max(l, m + 1ll);
        r = min(r, (ll)q);
        if (l > r) continue;
        ll a = (r - l + 1ll) * (l + r) % mod * (mod + 1) / 2 % mod;
        a = (a * L[i].first + L[i].second % mod * (r - l + 1ll)) % mod;
        a = (a + mod) % mod;
        ans = (ans + a) % mod;
        m = r;
    }
    printf("%d\n", ans);
}