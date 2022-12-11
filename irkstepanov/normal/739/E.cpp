#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<int, ld> data;

const ld inf = 1e9;

struct edge
{
    int from, to;
    int cap, flow;
    ld cost;
};

int s, t;
vector<vector<int> > g;
vector<edge> edges;
int vsize;

vector<ld> pot;
vector<vector<data> > h;

void add_edge(int u, int v, int cap, ld cost)
{
    g[u].pb(sz(edges));
    h[u].pb({v, cost});
    edges.pb({u, v, cap, 0, cost});
    g[v].pb(sz(edges));
    edges.pb({v, u, 0, 0, -cost});
}

vector<ld> dist;
vector<int> p;

void fb()
{
    pot.resize(vsize + 1, inf);
    pot[vsize] = 0;
    vector<int> q(vsize + 1);
    int qh = 0, qt = 1;
    vector<char> used(vsize + 1, false);
    q[qh] = vsize;
    while (qh != qt) {
        int v = q[qh++];
        used[v] = false;
        if (qh == vsize + 1) {
            qh = 0;
        }
        for (data& e : h[v]) {
            if (pot[e.first] > pot[v] + e.second) {
                pot[e.first] = pot[v] + e.second;
                if (!used[e.first]) {
                    used[e.first] = true;
                    q[qt++] = e.first;
                    if (qt == vsize + 1) {
                        qt = 0;
                    }
                }
            }
        }
    }
}

struct comp
{
    bool operator()(int a, int b)
    {
        if (dist[a] != dist[b]) {
            return dist[a] < dist[b];
        }
        return a < b;
    }
};

bool dijkstra()
{
    dist.assign(vsize, inf);
    p.assign(vsize, -1);
    set<int, comp> q;
    dist[s] = 0;
    q.insert(s);
    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        for (int e : g[v]) {
            ld cost = edges[e].cost + pot[v] - pot[edges[e].to];
            if (edges[e].cap > edges[e].flow && dist[edges[e].to] > dist[v] + cost) {
                q.erase(edges[e].to);
                p[edges[e].to] = e;
                dist[edges[e].to] = dist[v] + cost;
                q.insert(edges[e].to);
            }
        }
    }
    for (int i = 0; i < vsize; ++i) {
        pot[i] += dist[i];
    }
    return p[t] != -1;
}

ld cost = 0;

int add_flow(int flow)
{
    int curr = t;
    while (p[curr] != -1) {
        int e = p[curr];
        flow = min(flow, edges[e].cap - edges[e].flow);
        curr = edges[e].from;
    }
    curr = t;
    while (p[curr] != -1) {
        int e = p[curr];
        cost += edges[e].cost * ld(flow);
        edges[e].flow += flow;
        edges[e ^ 1].flow -= flow;
        curr = edges[e].from;
    }
    return flow;
}

void mincost(int k)
{
    while (k && dijkstra()) {
        k -= add_flow(k);
    }
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("wa");

	//freopen("input.txt", "r", stdin);

    int n, a, b;
    cin >> n >> a >> b;

    vector<ld> p(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }

    vsize = n + 4;
    s = vsize - 2, t = vsize - 1;
    g.resize(vsize);
    h.resize(vsize + 1);

    int x = n, y = n + 1;
    add_edge(s, x, a, 0);
    add_edge(s, y, b, 0);
    for (int i = 0; i < n; ++i) {
        add_edge(i, t, 1, 0);
        add_edge(i, t, 1, p[i] * q[i]);
    }

    for (int i = 0; i < n; ++i) {
        add_edge(x, i, 1, -p[i]);
        add_edge(y, i, 1, -q[i]);
    }

    for (int i = 0; i < vsize; ++i) {
        h[vsize].pb({i, 0});
    }

    fb();

    mincost(a + b);

    cout << fixed;
    cout.precision(12);
    cout << -cost << "\n";

}