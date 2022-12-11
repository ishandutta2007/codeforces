#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

const int inf = 1e9;

struct edge
{
    int from, to;
    int cap, flow;
    edge() {}
    edge(int from, int to, int cap) : from(from), to(to), cap(cap), flow(0) {}
};

vector<edge> edges;
vector<vector<int> > g;
int vsize;

void add_edge(int from, int to, int cap)
{
    g[from].pb(sz(edges));
    edges.pb(edge(from, to, cap));
    g[to].pb(sz(edges));
    edges.pb(edge(to, from, 0));
}

vector<int> level, ptr;
int s, t;

bool bfs()
{
    ptr.assign(vsize, 0);
    level.assign(vsize, -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int e : g[v]) {
            if (edges[e].cap > edges[e].flow && level[edges[e].to] == -1) {
                level[edges[e].to] = level[v] + 1;
                q.push(edges[e].to);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int v, int flow)
{
    if (v == t) {
        return flow;
    }
    for (; ptr[v] < sz(g[v]); ++ptr[v]) {
        int e = g[v][ptr[v]];
        if (edges[e].cap > edges[e].flow && level[edges[e].to] == level[v] + 1) {
            int x = dfs(edges[e].to, min(flow, edges[e].cap - edges[e].flow));
            if (x) {
                edges[e].flow += x;
                edges[e ^ 1].flow -= x;
                return x;
            }
        }
    }
    return 0;
}

int dinic()
{
    int ans = 0;
    while (bfs()) {
        int x;
        while ((x = dfs(s, inf))) {
            ans += x;
        }
    }
    return ans;
}

int main()
{

    int n, b, q;
    cin >> n >> b >> q;
    
    vector<int> cnt(b + 1, -1);
    cnt[b] = n;
    
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (cnt[x] != -1 && cnt[x] != y) {
            cout << "unfair\n";
            return 0;
        }
        cnt[x] = y;
    }
    
    vector<int> c;
    for (int i = 1; i <= b; ++i) {
        if (cnt[i] != -1) {
            c.pb(i);
        }
    }
    
    s = 0;
    vsize = 1 + sz(c) + b + 5 + 1;
    t = vsize - 1;
    g.resize(vsize);
    for (int i = 0; i < sz(c); ++i) {
        if (!i) {
            add_edge(s, i + 1, cnt[c[i]]);
            continue;
        }
        if (cnt[c[i]] < cnt[c[i - 1]]) {
            cout << "unfair\n";
            return 0;
        }
        add_edge(s, i + 1, cnt[c[i]] - cnt[c[i - 1]]);
    }
    
    for (int i = 0; i < sz(c); ++i) {
        if (!i) {
            for (int j = 1; j <= c[i]; ++j) {
                add_edge(i + 1, j + sz(c), 1);
            }
            continue;
        }
        for (int j = c[i - 1] + 1; j <= c[i]; ++j) {
            add_edge(i + 1, j + sz(c), 1);
        }
    }
    
    for (int j = 1; j <= b; ++j) {
        add_edge(j + sz(c), (j % 5) + 1 + sz(c) + b, 1);
    }
    
    for (int j = 0; j < 5; ++j) {
        add_edge(1 + sz(c) + b + j, t, n / 5);
    }
    
    /*for (edge& e : edges) {
        cout << e.from << " " << e.to << " " << e.cap << " " << e.flow << "\n";
    }*/
    
    cout << (dinic() == n ? "fair\n" : "unfair\n");
    //cout << dinic() << "\n";

}