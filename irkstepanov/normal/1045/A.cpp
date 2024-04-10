#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct edge {
    int from, to;
    int cap, flow;
};

const int inf = 1e9;

vector<edge> edges;
vector<vector<int> > g;
int s, t;
int vsize;
vector<int> level, ptr;

void addEdge(int u, int v, int c) {
    //cout << "!" << u << " " << v << " " << c << endl;
    g[u].pb(sz(edges));
    edges.pb({u, v, c, 0});
    g[v].pb(sz(edges));
    edges.pb({v, u, 0, 0});
}

bool bfs() {
    level.assign(vsize, vsize);
    ptr.assign(vsize, 0);
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int e : g[v]) {
            if (edges[e].cap > edges[e].flow && level[edges[e].to] == vsize) {
                level[edges[e].to] = level[v] + 1;
                q.push(edges[e].to);
            }
        }
    }
    return level[t] != vsize;
}

int dfs(int v, int flow) {
    if (v == t) {
        return flow;
    }
    while (ptr[v] < sz(g[v])) {
        int e = g[v][ptr[v]];
        if (edges[e].cap > edges[e].flow && level[edges[e].to] == level[v] + 1) {
            int k = dfs(edges[e].to, min(flow, edges[e].cap - edges[e].flow));
            if (k) {
                edges[e].flow += k;
                edges[e ^ 1].flow -= k;
                return k;
            }
        }
        ++ptr[v];
    }
    return 0;
}

int dinic() {
    int ans = 0;
    while (bfs()) {
        int x;
        while ((x = dfs(s, inf))) {
            ans += x;
        }
    }
    return ans;
}

vector<int> corresp;

void build(int v, int tl, int tr) {
    while (sz(g) <= v) {
        g.pb(vector<int>());
    }
    if (tl == tr) {
        corresp[tl] = v;
        return;
    }
    int tm = (tl + tr) >> 1;
    while (sz(g) <= 2 * v + 1) {
        g.pb(vector<int>());
    }
    addEdge(v, 2 * v, inf);
    addEdge(v, 2 * v + 1, inf);
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
}

void add(int from, int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        addEdge(from, v, 1);
        return;
    }
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        add(from, v * 2, tl, tm, l, min(r, tm));
    }
    if (r > tm) {
        add(from, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

vector<bool> used;
vector<int> path;

bool decomp(int v) {
    if (v == t) {
        return true;
    }
    used[v] = true;
    for (int e : g[v]) {
        if (edges[e].flow > 0 && !used[edges[e].to]) {
            path.pb(e);
            if (decomp(edges[e].to)) {
                return true;
            }
            path.pop_back();
        }
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    corresp.resize(m);

    build(1, 0, m - 1);
    int tree = sz(g);

    vsize = n + tree + 2;
    s = vsize - 2, t = vsize - 1;
    while (sz(g) <= vsize) {
        g.pb(vector<int>());
    }
    for (int i = 0; i < m; ++i) {
        addEdge(corresp[i], t, 1);
    }

    vector<int> type;
    vector<vector<int> > vct;

    for (int i = 0; i < n; ++i) {
        int tp;
        cin >> tp;
        vct.pb(vector<int>());
        type.pb(tp);
        if (tp == 0) {
            addEdge(s, i + tree, 1);
            int k;
            cin >> k;
            while (k--) {
                int x;
                cin >> x;
                --x;
                addEdge(i + tree, corresp[x], 1);
            }
        } else if (tp == 1) {
            int lf, rg;
            addEdge(s, i + tree, 1);
            cin >> lf >> rg;
            --lf, --rg;
            add(i + tree, 1, 0, m - 1, lf, rg);
        } else {
            addEdge(s, i + tree, 2);
            int a, b, c;
            cin >> a >> b >> c;
            --a, --b, --c;
            vct.back() = {a, b, c};
            addEdge(i + tree, corresp[a], 1);
            addEdge(i + tree, corresp[b], 1);
            addEdge(i + tree, corresp[c], 1);
        }
    }

    int flow = dinic();
    cout << flow << endl;
    vector<vector<int> > ans(n);
    vector<int> mt(m, -1);

    vector<int> rev(vsize);
    for (int i = 0; i < m; ++i) {
        rev[corresp[i]] = i;
    }

    while (flow--) {
        used.assign(vsize, false);
        path.clear();
        decomp(s);
        for (int e : path) {
            edges[e].flow -= 1;
            edges[e ^ 1].flow += 1;
        }
        int x = edges[path[0]].to - tree;
        int y = rev[edges[path.back()].from];
        //cout << "!" << x << " " << y << endl;
        ans[x].pb(y);
        mt[y] = x;
    }

    for (int i = 0; i < n; ++i) {
        //cout << i << endl;
        if (type[i] == 2 && sz(ans[i]) == 1) {
            for (int x : vct[i]) {
                if (mt[x] != -1 && mt[x] != i) {
                    ans[mt[x]].clear();
                    mt[x] = i;
                    ans[i].pb(x);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int to : ans[i]) {
            cout << i + 1 << " " << to + 1 << "\n";
        }
    }
    
}