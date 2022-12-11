#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> parent;
vector<int> size;

int get(int v) {
    if (parent[v] == v) {
        return v;
    }
    return parent[v] = get(parent[v]);
}

void unite(int u, int v) {
    u = get(u), v = get(v);
    assert(u != v);
    if (size[u] < size[v]) {
        swap(u, v);
    }
    parent[v] = u;
    size[u] += size[v];
}

pair<vector<vector<bool> >, vector<vector<bool> > > solve(int n, int m, int k, vector<pii> edges) {
    map<string, int> mapa;
    vector<int> corr(m);
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        int room;
        cin >> room;
        --room;
        mapa[s] = room;
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int e;
            cin >> e;
            --e;
            corr[e] = room;
        }
    }

    parent.resize(n);
    size.assign(n, 1);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    while (true) {
        bool found = false;
        for (int i = 0; i < m; ++i) {
            int u = edges[i].first, v = edges[i].second;
            if (get(u) == get(v)) {
                continue;
            }
            int r = corr[i];
            if (get(r) == get(u) || get(r) == get(v)) {
                unite(u, v);
                found = true;
            }
        }
        if (!found) {
            break;
        }
    }

    vector<vector<bool> > a(k, vector<bool>(n));
    vector<vector<bool> > b(m, vector<bool>(n));
    vector<pair<string, int> > vct;
    for (auto it : mapa) {
        vct.pb({it.first, it.second});
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            int u = get(vct[i].second), v = get(j);
            a[i][j] = (u == v ? true : false);
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = get(corr[i]), y = get(j);
            b[i][j] = (x == y ? true : false);
        }
    }
    return {a, b};
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pii> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[i] = {u, v};
    }

    pair<vector<vector<bool> >, vector<vector<bool> > > a = solve(n, m, k, edges);
    pair<vector<vector<bool> >, vector<vector<bool> > > b = solve(n, m, k, edges);
    cout << (a == b ? "YES\n" : "NO\n");

}