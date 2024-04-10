#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string a[105], b[105];

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

int razlika(string a, string b) {

	if (a.size() != b.size())
		return 123123;

	int z = 0;

	for (int i=0; i<(int)a.size(); i++)
		z += a[i] != b[i];

	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];

	MinCostMaxFlow engine(2*n+2);
	int source = 2*n, sink = 2*n+1;
	for (int i=0; i<n; i++)
		engine.add_edge(source, i, 1, 0);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			engine.add_edge(i, n+j, 1, razlika(a[i], b[j]));
	for (int j=0; j<n; j++)
		engine.add_edge(n+j, sink, 1, 0);

	engine.run_to_flow(source, sink, 2*n);

	cout << engine.cost << '\n';
}