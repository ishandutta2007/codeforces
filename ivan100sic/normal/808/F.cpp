#include <bits/stdc++.h>
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


const int SITO_MAX = 200000;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

struct card {
	int p, c, l;
};

int n, k;
vector<card> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	a.resize(n);

	for (card& c : a) {
		cin >> c.p >> c.c >> c.l;
	}

	for (int level=1; level<=n; level++) { // moze i binarna
		// radimo sa ovim nivoom
		map<int, int> layer0, layer1;

		for (card& c : a) {
			if (c.l <= level) {
				if (c.c == 1) {
					layer1[1] = max(layer1[1], c.p);
				} else if (c.c % 2 == 1) {
					layer1[c.c] += c.p;
				} else {
					layer0[c.c] += c.p;
				}
			}
		}

		vector<pair<int, int>> vec0(layer0.begin(), layer0.end());
		vector<pair<int, int>> vec1(layer1.begin(), layer1.end());

		int u = vec0.size();
		int v = vec1.size();
		int source = u + v;
		int sink = source + 1;

		MinCostMaxFlow engine(u + v + 2);

		for (int i=0; i<u; i++) {
			for (int j=0; j<v; j++) {
				int sum = vec0[i].first + vec1[j].first;
				if (f[sum] == sum) {
					// cerr << "grana " << i << ' ' << j << '\n';
					// spoji granom
					engine.add_edge(i, u+j, 1'000'000'000, 1);
				}
			}
		}

		int total = 0;

		for (int i=0; i<u; i++) {
			engine.add_edge(source, i, vec0[i].second, 1);
			total += vec0[i].second;
		}

		for (int j=0; j<v; j++) {
			engine.add_edge(u+j, sink, vec1[j].second, 1);
			total += vec1[j].second;
		}

		engine.run_to_flow(source, sink, 1'000'000'000);

		// cerr << level << ' ' << engine.flow << '\n';

		if (total - engine.flow >= k) {
			cout << level;
			return 0;
		}		
	}

	cout << -1;
}