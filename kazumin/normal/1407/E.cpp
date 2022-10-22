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

const int MN = 500005;

int n, m, col[MN], dp[MN][2], vis[MN], bck[MN][2];
vector<pii> a[MN], rev[MN];

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        if (u != v) a[u].push_back({v, w}), rev[v].push_back({u, w});
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[n][0] = dp[n][1] = 0;
    queue<int> q;
    q.push(n);
    vis[n] = 1;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (pii nxt : rev[cur]) {
            if (dp[nxt.f][nxt.s] > max(dp[cur][0], dp[cur][1]) + 1) {
                dp[nxt.f][nxt.s] = max(dp[cur][0], dp[cur][1]) + 1;
                bck[nxt.f][nxt.s] = cur;
                q.push(nxt.f);
            }
        }
    }
    int ans = max(dp[1][0], dp[1][1]);
    if (ans > MN) ans = -1;
    printf("%lld\n", ans);
    /*int cur = 1;
    while (1) {
        int j;
        if (dp[cur][0] > dp[cur][1]) j = 0;
        else j = 1;
        col[cur] = j;
        if (cur == n) break;
        cur = bck[cur][j];
    }
    for (int i = 1; i <= n; i++) printf("%d", col[i]);*/
    for (int i = 1; i <= n; i++) {
        if (dp[i][0] > dp[i][1]) printf("0");
        else printf("1");
    }

    return 0;
}