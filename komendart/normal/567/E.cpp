#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Edge {
    int from;
    int to;
    int l;
    int number;
};

vector< vector<Edge> > graph;

vector<char> is_bridge;
vector<int> fup;
vector<int> tin;
vector<char> used;
int timer = 0;

void dfs (int v, int parent) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (auto &e: graph[v]) {
		if (e.number == parent)  continue;
		if (used[e.to])
			fup[v] = min(fup[v], tin[e.to]);
		else {
			dfs(e.to, e.number);
			fup[v] = min(fup[v], fup[e.to]);
			if (fup[e.to] > tin[v]) is_bridge[e.number] = true;
		}
	}
}

const int INF = 1e13;
void dijkstra(vector< vector<Edge> > &graph, int st, vector<int> &d) {
    d.assign(graph.size(), INF);
    d[st] = 0;
    set< pair<int, int> > q = {{0, st}};
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto &e: graph[v]) {
            if (d[e.to] > d[v] + e.l) {
                if (d[e.to] < INF) q.erase({d[e.to], e.to});
                d[e.to] = d[v] + e.l;
                q.insert({d[e.to], e.to});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);

    int n, m, st, fin;
    cin >> n >> m >> st >> fin;
    st--; fin--;

    vector<Edge> edges; edges.reserve(m);
    graph.assign(n, vector<Edge>());
    vector< vector<Edge> > graph_rev(n);
    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--; b--;
        edges.push_back({a, b, l, i});
        graph[a].push_back({a, b, l, i});
        graph_rev[b].push_back({b, a, l, i});
    }

    vector<int> dst, dfin;
    dijkstra(graph, st, dst);
    dijkstra(graph_rev, fin, dfin);
    int dmin = dst[fin];

    graph.assign(n, vector<Edge>());
    for (auto &e: edges) {
        if (dst[e.from] + dfin[e.to] + e.l == dmin) {
            graph[e.from].push_back(e);
            graph[e.to].push_back({e.to, e.from, e.l, e.number});
        }
    }

    used.assign(n, false);
    fup.assign(n, -1);
    tin.assign(n, -1);
    is_bridge.assign(m, false);

    for (int i = 0; i < n; i++) {
        if (!used[i]) dfs(i, -1);
    }

    for (int i = 0; i < m; i++) {
        int a = dst[edges[i].from], b = dfin[edges[i].to];
        int l = edges[i].l;
        if (is_bridge[i]) {
            cout << "YES" << '\n';
        } else {
            int x = dmin - 1 - a - b;
            if (x > 0) {
                cout << "CAN" << ' ' << l - x << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
}