#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf = 1e9;

struct edge {
    int from, to;
    int cap, cost, flow;
};

vector<edge> edges;
vector<vector<int> > g;

void addEdge(int u, int v, int cap, int cost) {
    g[u].pb(sz(edges));
    edges.pb({u, v, cap, cost, 0});
    g[v].pb(sz(edges));
    edges.pb({v, u, 0, -cost, 0});
}

vector<int> dist;
int vsize;
vector<int> p;
int s, t;

bool fb() {
    dist.assign(vsize, inf);
    dist[s] = 0;
    p.assign(vsize, -1);
    vector<int> q(vsize);
    q[0] = s;
    int qh = 0, qt = 1;
    vector<char> used(vsize, false);
    while (qh != qt) {
        int v = q[qh++];
        if (qh == vsize) {
            qh = 0;
        }
        used[v] = false;
        for (int e : g[v]) {
            if (edges[e].cap > edges[e].flow && dist[edges[e].to] > dist[v] + edges[e].cost) {
                dist[edges[e].to] = dist[v] + edges[e].cost;
                p[edges[e].to] = e;
                if (!used[edges[e].to]) {
                    used[edges[e].to] = true;
                    q[qt++] = edges[e].to;
                    if (qt == vsize) {
                        qt = 0;
                    }
                }
            }
        }
    }
    return dist[t] != inf;
}

int cost = 0, flow = 0;

void add() {
    int curr = t;
    ++flow;
    while (curr != s) {
        int e = p[curr];
        cost += edges[e].cost;
        edges[e].flow += 1;
        edges[e ^ 1].flow -= 1;
        curr = edges[e].from;
    }
}

void mcmf() {
    while (fb()) {
        add();
    }
}

int main() {

    //ifstream cin("input.txt");
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n, 0), b(n, n - 1);
    while (q--) {
        int type;
        cin >> type;
        int l, r, val;
        cin >> l >> r >> val;
        --l, --r, --val;
        if (type == 1) {
            for (int i = l; i <= r; ++i) {
                a[i] = max(a[i], val);
            }
        } else {
            for (int i = l; i <= r; ++i) {
                b[i] = min(b[i], val);
            }
        }
    }

    vsize = 2 + 2 * n;
    g.resize(vsize);
    s = vsize - 2, t = vsize - 1;
    for (int i = 0; i < n; ++i) {
        addEdge(s, i, 1, 0);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = a[i]; j <= b[i]; ++j) {
            addEdge(i, j + n, 1, 0);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            addEdge(i + n, t, 1, j * j - (j - 1) * (j - 1));
        }
    }

    mcmf();
    if (flow != n) {
        cout << "-1\n";
        return 0;
    }

    cout << cost << "\n";

}