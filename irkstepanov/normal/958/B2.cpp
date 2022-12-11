#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

vector<vector<int> > g;
vector<int> dist;

void dfs1(int v, int p, int d) {
    dist[v] = d;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs1(to, v, d + 1);
    }
}

vector<int> parent;
vector<int> leaves;
vector<int> depth;
vector<pii> control;

const int inf = 1e9;

void dfs2(int v, int p, int d) {
    int cnt = 0;
    depth[v] = d;
    parent[v] = p;
    int lf = inf, rg = -1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        ++cnt;
        dfs2(to, v, d + 1);
        lf = min(lf, control[to].first);
        rg = max(rg, control[to].second);
    }
    control[v] = {lf, rg};
    if (cnt == 0) {
        leaves.pb(v);
        control[v] = {sz(leaves) - 1, sz(leaves) - 1};
    }
}

struct node {
    int maxx;
    int promise;
};

vector<node> t;

void push(int v) {
    t[v * 2].promise += t[v].promise;
    t[v * 2].maxx += t[v].promise;
    t[v * 2 + 1].promise += t[v].promise;
    t[v * 2 + 1].maxx += t[v].promise;
    t[v].promise = 0;
}

void build(int v, int tl, int tr, const vector<int>& a) {
    if (tl == tr) {
        t[v].maxx = a[tl];
        t[v].promise = 0;
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    t[v].maxx = max(t[v * 2].maxx, t[v * 2 + 1].maxx);
}

int get(int v, int tl, int tr) {
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) >> 1;
    push(v);
    if (t[v * 2].maxx == t[v].maxx) {
        return get(v * 2, tl, tm);
    } else {
        return get(v * 2 + 1, tm + 1, tr);
    }
}

vector<bool> used;

void update(int v, int tl, int tr, int l, int r, int val) {
    if (tl == l && tr == r) {
        t[v].promise += val;
        t[v].maxx += val;
        return;
    }
    int tm = (tl + tr) >> 1;
    push(v);
    if (l <= tm) {
        update(v * 2, tl, tm, l, min(r, tm), val);
    }
    if (r > tm) {
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
    t[v].maxx = max(t[v * 2].maxx, t[v * 2 + 1].maxx);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    g.resize(n);
    depth.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dist.assign(n, -1);
    dfs1(0, 0, 0);

    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (dist[i] > dist[r]) {
            r = i;
        }
    }

    parent.resize(n);
    control.resize(n);
    dfs2(r, r, 1);

    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    used.assign(n, false);
    int N = sz(leaves);

    vector<int> a;
    for (int v : leaves) {
        a.pb(depth[v]);
    }
    t.resize(4 * N);
    build(1, 0, N - 1, a);

    vector<int> ans(n, -1);
    ans[0] = 1;
    int s = 0;

    for (int i = 0; i < sz(leaves); ++i) {
        int u = get(1, 0, N - 1);
        u = leaves[u];
        while (!used[u]) {
            ++s;
            used[u] = true;
            update(1, 0, N - 1, control[u].first, control[u].second, -1);
            u = parent[u];
        }
        ans[i + 1] = s;
    }

    for (int i = 0; i < n; ++i) {
        if (ans[i] == -1) {
            ans[i] = n;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}