#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int __int128
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 1005, MOD = 998244353;

ll t, n, m, a[MN], u, v, deg[MN];
vector<int> adj[MN];
vector<pii> segs[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i]) segs[i].push_back({1, a[i]});
        }
        for (int i = 1; i <= m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            deg[v]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) if (!deg[i]) q.push(i);
        int lst = 0;
        while (q.size()) {
            int cur = q.front(); q.pop();
            lst = cur;
            sort(segs[cur].begin(), segs[cur].end());
            int r = -1;
            vector<pii> tmp;
            for (pii p : segs[cur]) {
                if (p.f > r + 1) tmp.push_back(p), r = p.s;
                else {
                    r = tmp.back().s + p.s - p.f + 1;
                    int l = tmp.back().f;
                    tmp.pop_back();
                    tmp.push_back({l, r});
                }
            }
            segs[cur] = tmp;
            for (int nxt : adj[cur]) {
                deg[nxt]--;
                for (pii p : segs[cur]) segs[nxt].push_back({p.f + 1, p.s + 1});
                if (!deg[nxt]) q.push(nxt);
            }
        }
        int ans = 0;
        if (segs[lst].size()) ans = segs[lst].back().s % MOD;
        printf("%lld\n", (ll) ans);
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            segs[i].clear();
            deg[i] = 0;
        }
    }

    return 0;
}