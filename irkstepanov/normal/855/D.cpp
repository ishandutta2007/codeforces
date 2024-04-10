#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

struct edge {
    int to;
    int tp;
};

const int nmax = 100500;
const int rmax = 19;

int parent[nmax][rmax];
vector<edge> g[nmax];
vector<int> roots;
int tin[nmax], tout[nmax];
int h[nmax];
int cnt[nmax][2];
int treeId[nmax];
int timer = 0;

void dfs(int v, int p, int ptr, int d) {
    parent[v][0] = p;
    h[v] = d;
    tin[v] = timer++;
    treeId[v] = ptr;
    for (edge& e : g[v]) {
        cnt[e.to][0] = cnt[v][0];
        cnt[e.to][1] = cnt[v][1];
        ++cnt[e.to][e.tp];
        dfs(e.to, v, ptr, d + 1);
    }
    tout[v] = timer++;
}

bool ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (ancestor(u, v)) {
        return u;
    }
    for (int r = rmax - 1; r >= 0; --r) {
        if (!ancestor(parent[u][r], v)) {
            u = parent[u][r];
        }
    }
    return parent[u][0];
}

int main() {

    //ifstream cin("input.txt");
    //freopen("defend.out", "w", stdout);
    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int p, tp;
        cin >> p >> tp;
        if (p == -1) {
            roots.pb(i);
            continue;
        }
        --p;
        g[p].pb({i, tp});
    }

    int ptr = 0;
    for (int v : roots) {
        dfs(v, v, ptr, 0);
        ++ptr;
    }

    for (int r = 0; r + 1 < rmax; ++r) {
        for (int v = 0; v < n; ++v) {
            int t = parent[v][r];
            parent[v][r + 1] = parent[t][r];
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int tp;
        cin >> tp;
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (treeId[u] != treeId[v]) {
            cout << "NO\n";
            continue;
        }
        --tp;
        int w = lca(u, v);
        if (u == v) {
            cout << "NO\n";
            continue;
        }
        if (tp == 0) {
            if (w != u) {
                cout << "NO\n";
                continue;
            }
            int s = cnt[v][0] - cnt[u][0];
            cout << (s == h[v] - h[u] ? "YES\n" : "NO\n");
        } else {
            if (w == v) {
                cout << "NO\n";
                continue;
            }
            int a = cnt[v][1] - cnt[w][1];
            int b = cnt[u][0] - cnt[w][0];
            cout << (a == h[v] - h[w] && b == h[u] - h[w] ? "YES\n" : "NO\n");
        }
    }

}