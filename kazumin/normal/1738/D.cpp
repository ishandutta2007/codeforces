#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005;

int t, n, b[MN], a[MN], k, id;
vector<int> adj[MN];

bool cmp(int x, int y) {
    return adj[x].size() < adj[y].size();
}

void dfs(int cur) {
    a[id++] = cur;
    for (int nxt : adj[cur]) dfs(nxt);
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        k = 0;
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            if (b[i] > i) k = i;
            if (1 <= b[i] && b[i] <= n) adj[b[i]].push_back(i);
            else adj[0].push_back(i);
        }
        for (int i = 0; i <= n; i++) sort(adj[i].begin(), adj[i].end(), cmp);
        id = 0;
        dfs(0);
        printf("%lld\n", k);
        for (int i = 1; i <= n; i++) printf("%lld%c", a[i], " \n"[i == n]);
        for (int i = 0; i <= n; i++) adj[i].clear();
    }

    return 0;
}