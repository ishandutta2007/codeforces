#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

vector<int> parent;
vector<int> size;

int get(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = get(parent[v]);
}

void unite(int u, int v) {
    if (size[u] < size[v]) {
        swap(u, v);
    }
    size[u] += size[v];
    parent[v] = u;
}

struct edge {
    int u, v;
    ll cost;
    bool operator<(const edge& other) const {
        return cost < other.cost;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    int opt = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (opt == -1 || a[i] < a[opt]) {
            opt = i;
        }
    }

    vector<edge> edges;
    for (int i = 0; i < n; ++i) {
        if (i == opt) {
            continue;
        }
        edges.pb({i, opt, a[i] + a[opt]});
    }

    while (m--) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        --u, --v;
        edges.pb({u, v, c});
    }

    parent.resize(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    size.assign(n, 1);

    ll ans = 0;
    sort(all(edges));
    for (int i = 0; i < sz(edges); ++i) {
        int u = get(edges[i].u), v = get(edges[i].v);
        if (u == v) {
            continue;
        }
        ans += edges[i].cost;
        unite(u, v);
    }
    cout << ans << "\n";

}