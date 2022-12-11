#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const ll inf = 1e18;

struct edge
{
    int from, to;
    ll cap, cost, flow;
    edge() {}
    edge(int from, int to, ll cap, ll cost, ll flow) : from(from), to(to), cap(cap), cost(cost), flow(flow) {}
};

vector<edge> edges;
vector<vector<int> > g;
int s, t;
int vsize;

void addEdge(int u, int v, ll cap, ll cost)
{
    g[u].pb(sz(edges));
    edges.pb({u, v, cap, cost, 0});
    g[v].pb(sz(edges));
    edges.pb({v, u, 0, -cost, 0});
}

vector<int> p;

bool fb()
{
    vector<ll> dist(vsize, inf);
    p.assign(vsize, -1);
    dist[s] = 0;
    vector<char> used(vsize, false);
    vector<int> q(vsize);
    int qh = 0, qt = 1;
    q[0] = s;
    while (qh != qt) {
        int v = q[qh++];
        used[v] = false;
        if (qh == vsize) {
            qh = 0;
        }
        for (int e : g[v]) {
            if (edges[e].cap > edges[e].flow && dist[edges[e].to] > dist[v] + edges[e].cost) {
                dist[edges[e].to] = dist[v] + edges[e].cost;
                p[edges[e].to] = e;
                if (!used[edges[e].to]) {
                    q[qt++] = edges[e].to;
                    if (qt == vsize) {
                        qt = 0;
                    }
                    used[edges[e].to] = true;
                }
            }
        }
    }
    return dist[t] != inf;
}

ll cost = 0, flow = 0;

ll add(ll k)
{
    int curr = t;
    while (curr != s) {
        int e = p[curr];
        k = min(k, edges[e].cap - edges[e].flow);
        curr = edges[e].from;
    }
    flow += k;
    curr = t;
    while (curr != s) {
        int e = p[curr];
        edges[e].flow += k;
        edges[e ^ 1].flow -= k;
        cost += k * edges[e].cost;
        curr = edges[e].from;
    }
    return k;
}

void mckf(int k)
{
    while (k && fb()) {
        k -= add(k);
    }
}

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vsize = 3 * n + 1;
    s = 0, t = n;
    g.resize(vsize);

    for (int i = 0; i < n; ++i) {
        addEdge(i, i + 1, ll(1e9), 0);
    }
    for (int i = 0; i < n; ++i) {
        addEdge(i, 2 * i + n + 1, 1, c[a[i]]);
        addEdge(2 * i + n + 2, i + 1, 1, 0);
    }

    for (int i = 0; i < n; ++i) {
        addEdge(2 * i + n + 1, 2 * i + n + 2, 1, -ll(1e9));
    }

    for (int i = 0; i < n; ++i) {
        int next = -1;
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j]) {
                next = j;
                break;
            }
        }
        if (next == -1) {
            continue;
        }
        addEdge(2 * i + n + 2, 2 * next + n + 1, 1, 0);
    }

    mckf(k);

    cout << cost + ll(n) * ll(1e9) << "\n";

}