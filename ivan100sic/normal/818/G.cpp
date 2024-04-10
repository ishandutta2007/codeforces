#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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
// KOD ZA TESTIRANJE

void test() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) {
		cin >> x;
	}

	auto good = [&](int i, int j) {
		return abs(a[i] - a[j]) == 1 || (a[i] - a[j]) % 7 == 0;
	};

	// resi "rucno" jednu iteraciju, dodaj u flow graph
	vector<int> next(n, -1);
	int last, first, chosen = 0;
	{
		vector<int> prev(n, -1), d(n, 1);
		for (int i=0; i<n; i++) {
			for (int j=0; j<i; j++) {
				if (good(i, j)) {
					if (d[j] + 1 > d[i]) {
						d[i] = d[j] + 1;
						prev[i] = j;
					}
				}
			}
		}
		int y = max_element(d.begin(), d.end()) - d.begin();
		last = y;
		while (y != -1) {
			first = y;
			chosen++;
			int x = prev[y];
			next[x] = y;
			y = x;
		}
	}


	int source = 2*n;
	int sink = 2*n+1;

	// napravi "cvorove"
	MinCostMaxFlow solver(2*n+2);
	for (int i=0; i<n; i++) {
		int entry = 2*i;
		int exit = 2*i+1;

		if (i == last) {
			solver.add_edge(exit, sink, 1, 0, 1);
		} else {
			solver.add_edge(exit, sink, 1, 0);
		}

		if (i == last || next[i] != -1) {
			solver.add_edge(entry, exit, 1, -1, 1);
		} else {
			solver.add_edge(entry, exit, 1, -1);
		}

		if (i == first) {
			solver.add_edge(source, entry, 1, 0, 1);
		} else {
			solver.add_edge(source, entry, 1, 0);
		}		

		for (int j=i+1; j<n; j++) {
			int next_entry = 2*j;
			int next_exit = 2*j+1;

			if (good(i, j)) {
				if (next[i] == j) {
					solver.add_edge(exit, next_entry, 1, 0, 1);
				} else {
					solver.add_edge(exit, next_entry, 1, 0);
				}
			}
		}
	}

	solver.flow = 1;
	solver.cost = -chosen;

	cerr << "Added edges\n";
	solver.run_once(source, sink); cerr << "Ran once\n";
	solver.run_once(source, sink); cerr << "Ran once\n";
	solver.run_once(source, sink); cerr << "Ran once\n";

	// solver.run_to_flow(source, sink, 4);
	cout << -solver.cost << '\n';
}

int main() {
	test();
}