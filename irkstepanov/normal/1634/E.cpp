#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

struct edge {
    int from, to;
    pii id;
};

vector<edge> edges;
vector<bool> used;
vector<bool> was;
vector<vector<int> > g;

void addEdge(int u, int v, pii id) {
    g[u].pb(sz(edges));
    edges.pb({u, v, id});
    g[v].pb(sz(edges));
    edges.pb({v, u, id});
}

vector<pii> ans;
vector<int> ptr;

void euler(int v, pii pe) {
    while (ptr[v] < sz(g[v])) {
        int e = g[v][ptr[v]];
        if (used[e]) {
            ++ptr[v];
            continue;
        }
        used[e] = used[e ^ 1] = true;
        ++ptr[v];
        euler(edges[e].to, edges[e].id);
    }
    if (pe.first != -1) {
        ans.pb(pe);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    map<int, int> mapa;
    int n;
    cin >> n;
    vector<vector<int> > a(n);

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
            ++mapa[a[i][j]];
        }
    }

    for (auto it : mapa) {
        if (it.second % 2) {
            cout << "NO\n";
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (sz(a[i]) % 2) {
            cout << "NO\n";
            return 0;
        }
    }

    int vsize = n + sz(mapa);
    g.resize(vsize);

    vector<int> vct;
    int iter = 0;
    for (auto it : mapa) {
        vct.pb(it.first);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sz(a[i]); ++j) {
            int pos = lower_bound(all(vct), a[i][j]) - vct.begin();
            addEdge(i, pos + n, {i, j});
        }
    }

    used.assign(sz(edges), false);
    was.assign(vsize, false);
    ptr.assign(vsize, 0);
    pii p = {-1, -1};

    for (int i = 0; i < vsize; ++i) {
        if (was[i]) {
            continue;
        }
        euler(i, p);
    }
    /*for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }
    return 0;*/

    vector<vector<char> > b(n);
    for (int i = 0; i < n; ++i) {
        b[i].assign(sz(a[i]), 'R');
    }
    for (int i = 0; i < sz(ans); i += 2) {
        int x = ans[i].first, y = ans[i].second;
        b[x][y] = 'L';
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (char c : b[i]) {
            cout << c;
        }
        cout << "\n";
    }

}