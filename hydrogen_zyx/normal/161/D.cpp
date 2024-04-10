#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MAXN = 100005;
const ll INF = 1000000000;

struct edge {
    ll to, length;

    edge() {}

    edge(ll a, ll b) : to(a), length(b) {}
};


vector<edge> g[MAXN];

bool centroid[MAXN];
ll subtree_size[MAXN];

ll ans, k;

//
ll compute_subtree_size(ll v, ll p) {
    ll c = 1;
    for (ll i = 0; i < g[v].size(); i++) {
        ll w = g[v][i].to;
        if (w == p || centroid[w]) continue;
        c += compute_subtree_size(w, v);
    }
    subtree_size[v] = c;
    return c;
}

//t
// pair
pair<ll, ll> search_centroid(ll v, ll p, ll t) {
    pair<ll, ll> res = pair<ll, ll>(INF, -1);
    ll s = 1, m = 0;
    for (ll i = 0; i < g[v].size(); i++) {
        ll w = g[v][i].to;
        if (w == p || centroid[w]) continue;
        res = min(res, search_centroid(w, v, t));
        m = max(m, subtree_size[w]);
        s += subtree_size[w];
    }
    m = max(m, t - s);
    res = min(res, pair<ll, ll>(m, v));
    return res;
}

void init(ll n) {
    memset(centroid, 0, sizeof(centroid));
    memset(subtree_size, 0, sizeof(subtree_size));
    for (ll i = 0; i <= n; i++) g[i].clear();
    ans = 0;
}

void dfs1(ll v, ll fa, ll d, unordered_map<ll, ll> &mp) {
    ans += mp[k - d];
    for (auto x:g[v]) {
        if (x.to == fa || centroid[x.to]) continue;
        dfs1(x.to, v, d + x.length, mp);
    }
}

void dfs2(ll v, ll fa, ll d, unordered_map<ll, ll> &mp) {
    mp[d]++;
    for (auto x:g[v]) {
        if (x.to == fa || centroid[x.to]) continue;
        dfs2(x.to, v, d + x.length, mp);
    }
}

ll solve(ll u) {
    compute_subtree_size(u, -1);
    ll s = search_centroid(u, -1, subtree_size[u]).second;
    centroid[s] = 1;
    unordered_map<ll, ll> mp;
    mp[0] = 1;
    for (ll i = 0; i < g[s].size(); i++) {
        ll v = g[s][i].to;
        if (centroid[v]) continue;
        solve(v);
        /*solve()*/
    }
    for (ll i = 0; i < g[s].size(); i++) {
        ll v = g[s][i].to;
        if (centroid[v]) continue;
        dfs1(v, s, g[s][i].length, mp);
        dfs2(v, s, g[s][i].length, mp);
    }
    /*do something*/
    centroid[s] = 0;
    return ans;
}

signed main() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
    ll n;
    cin >> n >> k;
    init(n);
    for (ll i = 1; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back({b, 1});
        g[b].push_back({a, 1});
    }
    solve(1);
    cout << ans << endl;
}