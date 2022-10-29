#include<bits/stdc++.h>

using namespace std;

#define pii pair<ll,ll>
#define fi first
#define se second
#define de(x) cout<< #x << ' ' << x << endl;
typedef long long ll;
const ll N = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct edge {
    int to, id;
};
vector<edge> g[N];
int vis[N];
int from[N], to[N];
int ans[N];

void dfs(int u, int fa) {
    vis[u] = 1;
    for (auto x: g[u]) {
        if (x.to == fa) continue;
        if (vis[x.to] == 1) {
            ans[x.id] = 1;
            continue;
        }
        dfs(x.to, u);
    }
}

int pa[N];
int n, m;

int find(int x) {
    return pa[x] == x ? x : pa[x] = find(pa[x]);
}

int merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    pa[x] = y;
    return 1;
}

bool solve() {
    for (int i = 1; i <= n; i++) {
        random_shuffle(g[i].begin(), g[i].end());
        vis[i] = 0;
    }
    for (int i = 1; i <= m; i++) ans[i] = 0;

    int root = rand() % n + 1;
    dfs(root, -1);
    for (int i = 1; i <= n; i++) pa[i] = i;
    bool ok = 1;
    for (int i = 1; i <= m; i++) {
        if (!ans[i]) continue;
        if (!merge(from[i], to[i])) {
            ok = 0;
            break;
        }
    }
    if (!ok) return false;
    for (int i = 1; i <= m; i++) cout << ans[i];
    cout << endl;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            from[i] = u, to[i] = v;
            g[u].push_back({v, i});
            g[v].push_back({u, i});
        }
        while (!solve());
    }
}