#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, fn, x, y;
int a[505], q[1005];
basic_string<int> e[1005], extraS, extraT, esc, etc;

struct MinCostMaxFlow {

	static const int INF;

	struct edge {
		int v, capacity, cost, flow;
		size_t twin;
	};

	vector<vector<edge>> g;
	int n;
	int flow;
	int cost;

	// Cvorovi su indeksirani od 0 do n-1
	explicit MinCostMaxFlow(int n) : g(n), n(n), flow(0), cost(0) {}

	void add_edge(int u, int v, int capacity, int cost, int flow=0) {

		// cerr << "add_edge " << u << ' ' << v << ' ' << capacity << ' ' << cost << '\n';

		edge e1 = {v, capacity, cost, flow, g[v].size()};
		edge e2 = {u, 0, -cost, -flow, g[u].size()};
		g[u].push_back(e1);
		g[v].push_back(e2);
	}

	void clear_flow() {
		for (auto& v : g) {
			for (auto& e : v) {
				e.flow = 0;
			}
		}
		flow = cost = 0;
	}

	void clear() {
		g.clear();
		flow = cost = 0;
	}

	// koliko najvise flowa mozemo da dodamo u ovoj iteraciji
	void run_once(int source, int sink, int flow_limit = INF) {
		// id - labela cvora
		const char POPPED = 2;
		const char QUEUED = 1;
		const char INACTIVE = 0;

		vector<char> label(n, INACTIVE);

		// d - distanca od starta
		// p - prethodni na putu
		// q - red
		vector<int> distance(n, INF), parent(n), quuee(n);
		vector<size_t> parent_edge(n);
		int queue_start = 0, queue_end = 0;

		quuee[queue_end++] = source;
		distance[source] = 0;

		while (queue_start != queue_end) {
			int u = quuee[queue_start++];
			if (queue_start == n) {
				queue_start = 0;
			}
			label[u] = POPPED;
			for (size_t i=0; i<g[u].size(); i++) {
				edge& e = g[u][i];
				int v = e.v;
				// ako ima nezasicena dobra (za najkraci put) grana
				if (e.flow < e.capacity && distance[u] + e.cost < distance[v]) {
					distance[v] = distance[u] + e.cost;
					// sredim distancu
					// pametni algoritam za najkraci put, prvi put dodajem cvor na glavu,
					// svaki sledeci put na rep reda
					if (label[v] == INACTIVE) {
						quuee[queue_end++] = v;
						if (queue_end == n) {
							queue_end = 0;
						}
					} else if (label[v] == POPPED) {
						if (--queue_start == -1) {
							queue_start = n-1;
						}
						quuee[queue_start] = v;
					}
					// oznacim
					label[v] = QUEUED;
					parent[v] = u;
					parent_edge[v] = i;
				}
			}
		}

		if (distance[sink] == INF) {
			return;
		}

		int add_flow = flow_limit;
		int y = sink;
		while (y != source) {
			int x = parent[y];
			size_t i = parent_edge[y];
			add_flow = min(add_flow, g[x][i].capacity - g[x][i].flow);
			y = x;
		}
		y = sink;
		while (y != source) {
			int x = parent[y];
			size_t i = parent_edge[y];
			size_t j = g[x][i].twin;

			g[x][i].flow += add_flow;
			g[y][j].flow -= add_flow;
			cost += g[x][i].cost * add_flow;
			y = x;
		}
		flow += add_flow;
	}

	// jedna od dve realno potrebne funkcije
	void run_to_flow(int source, int sink, int flow_limit) {
		clear_flow();
		while (1) {
			int old_flow = flow;
			run_once(source, sink, flow_limit - flow);
			if (old_flow == flow) {
				return;
			}
		}
	}
};

const int MinCostMaxFlow::INF = 1'000'000'000;

// KRAJ TEMPLATE KODA

MinCostMaxFlow engine(4005);

pair<basic_string<int>, int> collect(int x, int p) {
	basic_string<int> u;
	int umanjenje = 0;
	u += x;
	for (int y : e[x]) {
		if (y == p)
			continue;
		auto rez = collect(y, x);
		u += rez.first;
		umanjenje += rez.second;
	}

	if (q[x] > 0 && q[x] - umanjenje < 0) {
		cout << "-1\n";
		exit(0);
	}

	if (q[x]) {
		// pravi globalni klaster, vrati prazno
		if (x <= n) {
			extraS += ++fn;
			esc += q[x] - umanjenje;
			for (int y : u)
				engine.add_edge(fn, y, 1, 0);
		} else {
			extraT += ++fn;
			etc += q[x] - umanjenje;
			for (int y : u)
				engine.add_edge(y, fn, 1, 0);
		}
		return {{}, q[x]};
	} else {
		return {u, umanjenje};
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x >> y;
	fn = 2*n;
	y += n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		u += n;
		v += n;
		e[u] += v;
		e[v] += u;
	}
	int m;
	cin >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		q[u] = v;
	}
	cin >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		u += n;
		q[u] = v;
	}

	if (q[x] != q[y]) {
		cout << "-1\n";
		return 0;
	}

	collect(x, x);
	collect(y, y);

	for (int i=1; i<=n; i++)
		engine.add_edge(i, i+n, 1, -a[i]);

	int source = 4001;
	int sink = 4002;

	for (int i=0; i<(int)extraS.size(); i++)
		engine.add_edge(source, extraS[i], esc[i], 0);
	for (int i=0; i<(int)extraT.size(); i++)
		engine.add_edge(extraT[i], sink, etc[i], 0);

	engine.run_to_flow(source, sink, n+1);

	cerr << "flow: " << engine.flow << '\n';
	cerr << "cost: " << engine.cost << '\n';

	if (engine.flow != q[x]) {
		cout << "-1\n";
		return 0;
	}

	cout << -engine.cost << '\n';
}