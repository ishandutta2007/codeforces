#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

struct node {
    int val, u, i;
};

bool cmp(node x, node y) {
    return x.val < y.val;
}

const int MN = 300005;

int n, m, X, val[MN], u, v, par[MN], tot[MN];
vector<pii > a[MN];
priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, greater<>> adj[MN];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (adj[x].size() < adj[y].size()) swap(x, y);
    par[y] = par[x];
    tot[x] += tot[y] - X;
    while (adj[y].size()) adj[x].push(adj[y].top()), adj[y].pop();
    return true;
}

int32_t main() {
    boost();

    cin >> n >> m >> X;
    priority_queue<pii, vector<pii>> q; //total asphalt, cmp id
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        par[i] = i;
        tot[i] = val[i];
        q.push({val[i], i});
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a[u].push_back({v, i});
        a[v].push_back({u, i});
        adj[u].push({{val[v], v}, {i, 0}});
        adj[v].push({{val[u], u}, {i, 0}});
    }
    vector<int> out;
    while (q.size()) {
        pii cur = q.top(); q.pop();
        cur.s = find(cur.s);
        if (cur.f != tot[cur.s]) continue;
        cur.f = tot[cur.s];
        while (adj[cur.s].size() && find(adj[cur.s].top().f.s) == cur.s) adj[cur.s].pop();
        if (adj[cur.s].size()) {
            auto nxt = adj[cur.s].top(); adj[cur.s].pop();
            nxt.f.s = find(nxt.f.s);
            if (tot[cur.s] + tot[nxt.f.s] - X < 0) return 0 * printf("NO\n");
            merge(cur.s, nxt.f.s);
            out.push_back(nxt.s.f);
            q.push({tot[find(cur.s)], find(cur.s)});
        }
    }
    printf("YES\n");
    for (int p : out) printf("%lld\n", p);

    return 0;
}