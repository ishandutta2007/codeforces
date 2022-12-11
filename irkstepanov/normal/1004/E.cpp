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
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

struct edge {
    int to;
    ll cost;
};

vector<vector<edge> > g;
vector<ll> dist;
vector<pll> p;

void dfs(int v, ll x) {
    dist[v] = x;
    for (edge& e : g[v]) {
        int to = e.to;
        if (dist[to] != -1) {
            continue;
        }
        p[to] = {v, e.cost};
        dfs(to, x + e.cost);
    }
}

const ll inf = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    g.resize(n);
    p.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        --u, --v;
        g[u].pb({v, c});
        g[v].pb({u, c});
    }

    dist.assign(n, -1);
    dfs(0, 0);

    int u = 0;
    for (int i = 1; i < n; ++i) {
        if (dist[i] > dist[u]) {
            u = i;
        }
    }

    dist.assign(n, -1);
    dfs(u, 0);

    int v = 0;
    for (int i = 1; i < n; ++i) {
        if (dist[i] > dist[v]) {
            v = i;
        }
    }

    vector<int> vct;
    vector<int> path;
    path.pb(v);
    while (v != u) {
        vct.pb(p[v].second);
        v = p[v].first;
        path.pb(v);
    }

    dist.assign(n, -1);
    for (int x : path) {
        dist[x] = 0;
    }
    for (int x : path) {
        dfs(x, 0);
    }

    ll z = 0;
    for (int i = 0; i < n; ++i) {
        z = max(z, dist[i]);
    }

    vector<ll> pref(sz(vct));
    pref[0] = vct[0];
    for (int i = 1; i < sz(vct); ++i) {
        pref[i] = pref[i - 1] + vct[i];
    }

    vector<ll> suff(sz(vct));
    suff.back() = vct.back();
    for (int i = sz(vct) - 2; i >= 0; --i) {
        suff[i] = suff[i + 1] + vct[i];
    }

    ll ans = inf;
    for (int i = 0; i < sz(vct); ++i) {
        ll val = 0;
        if (i) {
            val = max(val, pref[i - 1]);
        }
        if (i + k - 1 < sz(vct)) {
            val = max(val, suff[i + k - 1]);
        }
        //cout << "!" << i << " " << val << "\n";
        ans = min(ans, val);
    }

    cout << max(ans, z) << "\n";

}