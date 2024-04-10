#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 200005;

int n, m, cnt[MN], freq[MN], vis[MN], rem[MN];
pii a[MN];
vector<pii> adj[MN];
vector<int> v;

int main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> cnt[i];
    for (int i = 1; i <= m; i++) {
        cin >> a[i].f >> a[i].s;
        freq[a[i].f]++; freq[a[i].s]++;
        adj[a[i].f].push_back({a[i].s, i});
        adj[a[i].s].push_back({a[i].f, i});
    }
    queue<int> q;
    //for (int i = 1; i <= n; i++) printf("%d ", freq[i]);
    for (int i = 1; i <= n; i++) if (freq[i] <= cnt[i]) q.push(i);
    while (q.size()) {
        int cur = q.front(); q.pop();
        vis[cur] = 1;
        for (pii nxt : adj[cur]) {
            if (!rem[nxt.s]) {
                rem[nxt.s] = 1, freq[nxt.f]--; v.push_back(nxt.s);
                if (freq[nxt.f] <= cnt[nxt.f] && !vis[nxt.f]) q.push(nxt.f);
            }
        }
    }
    int mis = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) mis++;
    if (mis) return 0 * printf("DEAD\n");
    printf("ALIVE\n");
    for (int i = v.size() - 1; i >= 0; i--) printf("%d ", v[i]);

    return 0;
}