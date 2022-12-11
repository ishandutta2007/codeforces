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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

struct edge {
    int from, to;
};

vector<edge> edges;
vector<vector<int> > g;
vector<int> ret, tin;
vector<bool> used;
//vector<bool> art;
int timer = 0;

vector<int> stack;
vector<vector<int> > comps;

void dfs(int v, int p) {
    //cout << "DFS" << v + 1 << endl;
    used[v] = true;
    tin[v] = timer++;
    ret[v] = tin[v];
    int sons = 0;
    for (int e : g[v]) {
        int to = edges[e].to;
        if (to == p) {
            continue;
        }
        if (!used[to]) {
            ++sons;
            int pr = -1;
            if (!stack.empty()) {
                pr = stack.back();
            }
            stack.pb(e >> 1);
            dfs(to, v);
            ret[v] = min(ret[v], ret[to]);
            if (tin[v] <= ret[to]) {
                comps.pb(vector<int>());
                while (!stack.empty()) {
                    int edge = stack.back();
                    if (edge == pr) {
                        break;
                    }
                    comps.back().pb(edge);
                    stack.pop_back();
                }
            }
        } else {
            if (tin[v] > tin[to]) {
                stack.pb(e >> 1);
            }
            ret[v] = min(ret[v], tin[to]);
        }
    }
    if (v == p && sons > 1) {
        // DO NOTHING
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    g.resize(n);
    //art.assign(n, false);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(sz(edges));
        edges.pb({u, v});
        g[v].pb(sz(edges));
        edges.pb({v, u});
    }

    used.assign(n, false);
    tin.resize(n);
    ret.resize(n);

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, i);
        }
    }

    vector<int> ans;

    for (int i = 0; i < sz(comps); ++i) {
        set<int> vert;
        for (int e : comps[i]) {
            vert.insert(edges[e * 2].from);
            vert.insert(edges[e * 2].to);
        }
        if (sz(vert) == sz(comps[i])) {
            for (int e : comps[i]) {
                ans.pb(e);
            }
        }
    }

    /*for (int i = 0; i * 2 < sz(edges); ++i) {
        cout << edges[i * 2].bridge << "\n";
    }*/

    sort(all(ans));

    cout << sz(ans) << "\n";
    for (int e : ans) {
        cout << e + 1 << " ";
    }
    cout << "\n";

}