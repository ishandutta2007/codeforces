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
vector<int> deg;

void dfs(int v, int p, int d) {
    dist[v] = d;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v, d + 1);
    }
}

vector<int> t;

void build(int v, int tl, int tr, const vector<int>& a) {
    if (tl == tr) {
        t[v] = 1 - a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

int get(int v, int tl, int tr) {
    if (t[v] == 0) {
        return -1;
    }
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) >> 1;
    if (t[v * 2 + 1]) {
        return get(v * 2 + 1, tm + 1, tr);
    } else {
        return get(v * 2, tl, tm);
    }
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v] ^= 1;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        update(v * 2, tl, tm, pos);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos);
    }
    t[v] = t[v * 2] + t[v * 2 + 1];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    g.resize(n);
    dist.resize(n);

    for (int i = 0; i < n; ++i) {
        int p;
        /*if (i == 0) {
            p = 0;
        } else {
            p = rr() % i + 1;
        }
        cout << p << " ";*/
        cin >> p;
        if (p == 0) {
            continue;
        }
        --p;
        g[i].pb(p);
        g[p].pb(i);
    }
    cout << endl;

    dfs(0, 0, 0);
    deg.resize(n);

    vector<int> order;
    for (int i = 0; i < n; ++i) {
        order.pb(i);
    }
    sort(all(order), [&] (int u, int v) {
        return dist[u] < dist[v];
    });

    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[order[i]] = i;
        deg[i] = sz(g[order[i]]) % 2;
    }

    t.resize(4 * n);
    build(1, 0, n - 1, deg);
    vector<bool> used(n, false);

    vector<int> ans;

    //cout << deg[5] << "\n";

    for (int op = 0; op < n; ++op) {
        int p = get(1, 0, n - 1);
        if (p == -1) {
            if (n % 2 == 1) {
                assert(false);
            }
            cout << "NO\n";
            return 0;
        }
        int v = order[p];
        assert(!used[v]);
        ans.pb(v);
        update(1, 0, n - 1, p);
        used[v] = true;
        for (int to : g[v]) {
            if (!used[to]) {
                update(1, 0, n - 1, pos[to]);
            }
        }
    }

    if (n % 2 == 0) {
        assert(false);
    }
    cout << "YES\n";
    for (int x : ans) {
        /*assert(deg[x] == 0);
        for (int to : g[x]) {
            deg[to] ^= 1;
        }*/
        cout << x + 1 << "\n";
    }

}