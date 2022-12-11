#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;

struct edge
{
    int to, color;
};

vector<vector<edge> > g;
vector<char> used;
vector<int> tin, ret;
int timer = 0;
set<pii> bridges;

void dfs_bridges(int v, int p)
{
    used[v] = true;
    tin[v] = timer++;
    ret[v] = tin[v];
    for (edge& e : g[v]) {
        int to = e.to;
        if (to == p) {
            continue;
        }
        if (!used[to]) {
            dfs_bridges(to, v);
            ret[v] = min(ret[v], ret[to]);
            if (ret[to] > tin[v]) {
                bridges.insert(mp(min(to, v), max(to, v)));
            }
        } else {
            ret[v] = min(ret[v], tin[to]);
        }
    }
}

vector<int> comp;

void dfs_comp(int v, int color)
{
    comp[v] = color;
    for (edge& e : g[v]) {
        int to = e.to;
        if (comp[to] != -1) {
            continue;
        }
        if (!bridges.count(mp(min(to, v), max(to, v)))) {
            dfs_comp(to, color);
        }
    }
}

vector<int> good;
vector<vector<edge> > gr;
vector<int> ok;

void dfs_final(int v, int p, int flag)
{
    if (flag || good[v]) {
        ok[v] = 1;
        flag = 1;
    }
    for (edge& e : gr[v]) {
        int to = e.to;
        if (to == p) {
            continue;
        }
        if (e.color) {
            dfs_final(to, v, 1);
        } else {
            dfs_final(to, v, flag);
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        g[u].pb({v, c});
        g[v].pb({u, c});
    }
    
    tin.resize(n), ret.resize(n);
    used.assign(n, false);
    dfs_bridges(0, -1);
    
    comp.assign(n, -1);
    int cc = 0;
    for (int i = 0; i < n; ++i) {
        if (comp[i] == -1) {
            dfs_comp(i, cc++);
        }
    }
    
    good.resize(cc);
    gr.resize(cc);
    for (int i = 0; i < n; ++i) {
        for (edge& e : g[i]) {
            int to = e.to;
            if (comp[i] == comp[to] && e.color == 1) {
                good[comp[i]] = 1;
            }
            if (comp[i] != comp[to]) {
                gr[comp[i]].pb({comp[to], e.color});
            }
        }
    }
    
    int s, t;
    cin >> s >> t;
    --s, --t;
    s = comp[s], t = comp[t];
    ok.resize(cc);
    
    dfs_final(s, -1, 0);
    
    cout << (ok[t] ? "YES\n" : "NO\n");

}