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

const int MN = 100005;

int n, m, p[MN], h[MN], cnt[MN], sadcnt[MN], hpycnt[MN]; //how many pass thru i
vector<int> a[MN];
bool ok = 1;

void dfs(int cur, int par) {
    cnt[cur] += p[cur];
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
        cnt[cur] += cnt[nxt];
    }
}

void check(int cur, int par) {
    int hpy = 0;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        check(nxt, cur);
        hpy += hpycnt[nxt];
        //if (hpycnt[nxt] > hpycnt[cur] && cnt[nxt]) ok = 0;
    }
    if (hpy > hpycnt[cur]) ok = 0;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        ok = 1;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) cin >> h[i];
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        dfs(1, 0);
        for (int i = 1; i <= n; i++) {
            if ((cnt[i] - h[i]) % 2 != 0 || cnt[i] < h[i] || -cnt[i] > h[i]) {
                ok = 0;
                //printf("%d %d %d\n", i, cnt[i], h[i]);
                break;
            }
            sadcnt[i] = (cnt[i] - h[i]) / 2;
            hpycnt[i] = cnt[i] - sadcnt[i];
            assert(hpycnt[i] - sadcnt[i] == h[i] && hpycnt[i] + sadcnt[i] == cnt[i]);
        }
        check(1, 0);
        if (ok) printf("YES\n");
        else printf("NO\n");
        for (int i = 0; i <= n; i++) {
            //printf("%d %d\n", hpycnt[i], sadcnt[i]);
            a[i].clear();
            cnt[i] = h[i] = p[i] = sadcnt[i] = hpycnt[i] = 0;
        }
        //printf("\n");
        ok = 1;
    }

    return 0;
}