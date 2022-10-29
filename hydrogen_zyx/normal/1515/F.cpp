#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 3e5 + 10;

struct edge {
    ll to, id;
};

vector<edge> g[N];
ll val[N];
ll pa[N];

void init(ll n) {
    for (ll i = 0; i <= n; i++) {
        pa[i] = i;
    }
}

ll find(ll a) {
    return pa[a] == a ? a : pa[a] = find(pa[a]);
}

ll n, m, x;

void merge(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (g[a].size() > g[b].size()) swap(a, b);
    for (auto i:g[a]) {
        g[b].push_back(i);
    }
    g[a].clear();
    val[b] = val[a] + val[b] - x;
    pa[a] = b;
}

vector<ll> ans;

bool vis[N];
ll from[N], to[N];


signed main() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
    cin >> n >> m >> x;
    init(n);
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> val[i];
        sum += val[i];
    }
    if (sum < x * (n - 1)) {
        cout << "NO" << endl;
        return 0;
    } else cout << "YES" << endl;
    for (ll i = 1; i <= m; i++) {
        ll a, b;
        cin >> a >> b;
        from[i] = a;
        to[i] = b;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }
    for (ll i = 1; i <= n; i++) {
        ll q = find(i);
        while (!g[q].empty() && val[q] >= x) {
            ll go = g[q].back().to;
            go = find(go);
            if (go == q) {
                g[q].pop_back();
                continue;
            }
            vis[g[q].back().id] = 1;
            ans.push_back(g[q].back().id);
            merge(q, go);
            q = find(q);
        }
    }
    for (ll i = 1; i <= m; i++) {
        if (vis[i]) continue;
        if (find(from[i]) != find(to[i])) {
            ans.push_back(i);
            merge(from[i], to[i]);
        }
    }
    for (auto x:ans) cout << x << endl;
}