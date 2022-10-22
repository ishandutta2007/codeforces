#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

struct edge {
    int v, x, y;
};

const int MN = 200005, MOD = 998244353;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int inv(int x) {
    return fpow(x, MOD - 2);
}

int t, n, u, v, x, y, cnt[MN], sum, mx[MN];
vector<edge> a[MN];

vector<pii> fact(int x) {
    vector<pii> ret;
    for (int i = 2; i * i <= x; i++) {
        if (x % i) continue;
        int tmp = 0;
        while (x % i == 0) x /= i, tmp++;
        ret.push_back({i, tmp});
    }
    if (x > 1) ret.push_back({x, 1});
    return ret;
}

void dfs(int cur, int par, int val) {
    sum = (sum + val) % MOD;
    for (edge nxt : a[cur]) {
        if (nxt.v == par) continue;
        vector<pii> fx = fact(nxt.x), fy = fact(nxt.y);
        for (pii p : fy) cnt[p.f] += p.s;
        for (pii p : fx) cnt[p.f] -= p.s, mx[p.f] = max(mx[p.f], -cnt[p.f]);
        dfs(nxt.v, cur, val * inv(nxt.x) % MOD * nxt.y % MOD);
        for (pii p : fy) cnt[p.f] -= p.s;
        for (pii p : fx) cnt[p.f] += p.s;
    }
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cnt[i] = mx[i] = 0, a[i].clear();
        for (int i = 1; i < n; i++) {
            cin >> u >> v >> x >> y;
            int g = __gcd(x, y);
            x /= g, y /= g;
            a[u].push_back({v, x, y});
            a[v].push_back({u, y, x});
        }
        sum = 0;
        dfs(1, 0, 1);
        for (int i = 1; i <= n; i++) for (int j = 1; j <= mx[i]; j++) sum = sum * i % MOD;
        printf("%lld\n", sum);
    }

    return 0;
}