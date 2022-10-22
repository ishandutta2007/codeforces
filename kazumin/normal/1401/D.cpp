#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005, MOD = 1e9 + 7;

int n, u, v, m, p[MN], freq[MN], sub[MN];
vector<int> a[MN];

void dfs(int cur, int par) {
    sub[cur] = 1;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
        sub[cur] += sub[nxt];
    }
    freq[cur] = sub[cur] * (n - sub[cur]);
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        cin >> m;
        for (int i = 1; i <= m; i++) cin >> p[i];
        sort(p + 1, p + m + 1);
        while (m > n - 1) {
            p[m - 1] *= p[m];
            p[m - 1] %= MOD;
            m--;
        }
        reverse(p + 1, p + m + 1);
        dfs(1, 0);
        sort(freq + 2, freq + n + 1, greater<>());
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int mult = 0;
            if (i > m) mult = 1;
            else mult = p[i];
            freq[i + 1] %= MOD;
            ans += mult * freq[i + 1];
            ans %= MOD;
        }
        printf("%lld\n", ans % MOD);
        for (int i = 1; i <= n; i++) a[i].clear(), sub[i] = freq[i] = 0;
    }

    return 0;
}