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
typedef long double ld;
typedef pair<ld, ld> pld;

mt19937 rr(998244353);

void rs(vector<int>& v) {
    for (int i = 1; i < sz(v); ++i) {
        int j = rr() % (i + 1);
        swap(v[i], v[j]);
    }
}

vector<int> solve(vector<vector<int> >& g) {
    int n = sz(g);
    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        order[i] = i;
    }
    rs(order);
    vector<bool> take(n, false);
    vector<int> taken;
    vector<bool> reach(n, false);
    for (int v : order) {
        if (reach[v]) {
            continue;
        }
        bool valid = true;
        for (int to : g[v]) {
            if (take[to]) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            continue;
        }
        take[v] = true;
        taken.pb(v);
        for (int to : g[v]) {
            reach[to] = true;
        }
    }
    bool term = true;
    for (int v = 0; v < n; ++v) {
        if (!take[v] && !reach[v]) {
            term = false;
            break;
        }
    }
    if (term) {
        return taken;
    }
    vector<int> newId(n, -1);
    order.clear();
    int cnt = 0;
    for (int v = 0; v < n; ++v) {
        if (reach[v] || take[v]) {
            continue;
        }
        newId[v] = cnt++;
        order.pb(v);
    }
    vector<vector<int> > newG(cnt);
    for (int v = 0; v < n; ++v) {
        if (newId[v] == -1) {
            continue;
        }
        for (int to : g[v]) {
            if (newId[to] == -1) {
                continue;
            }
            newG[newId[v]].pb(newId[to]);
        }
    }
    vector<int> res = solve(newG);
    for (int i = 0; i < sz(res); ++i) {
        res[i] = order[res[i]];
    }
    vector<bool> ok(n, false);
    for (int v : res) {
        for (int to : g[v]) {
            ok[to] = true;
        }
    }
    for (int v : taken) {
        if (!ok[v]) {
            res.pb(v);
        }
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > g(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
    }

    vector<int> ans = solve(g);
    sort(all(ans));
    cout << sz(ans) << "\n";
    for (int v : ans) {
        cout << v + 1 << " ";
    }
    cout << "\n";

}