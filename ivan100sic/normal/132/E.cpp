#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 1'000'000'000;

struct MinCostMaxFlow {

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

	pair<int, int> add_edge(int u, int v, int capacity, int cost, int flow=0) {
		edge e1 = {v, capacity, cost, flow, g[v].size()};
		edge e2 = {u, 0, -cost, -flow, g[u].size()};
		pair<int, int> result = {g[u].size(), g[v].size()};
		g[u].push_back(e1);
		g[v].push_back(e2);
		return result;
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


const int N = 251;

int n, m, h;
int a[N];
int b[N];
vector<int> aa;

inline int izmenjivac(int x) {
	return n*h + x;
}

inline int source() {
	return n*h + n + 0;
}

inline int sink() {
	return n*h + n + 1;
}

inline int cvor(int x, int y) {
	return x*h + y;
}

inline int cena(int x) {
	return __builtin_popcount(aa[x]);
}

struct promena {
	int i, x, y;
};

basic_string<int> w[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];

	aa = vector<int>(a, a+n);
	sort(aa.begin(), aa.end());
	h = unique(aa.begin(), aa.end()) - aa.begin();
	aa.resize(h);
	for (int i=0; i<n; i++)
		b[i] = lower_bound(aa.begin(), aa.end(), a[i]) - aa.begin();

	MinCostMaxFlow eng(n*(h+1) + n + 2);

	eng.add_edge(source(), izmenjivac(0), m, 0);
	for (int i=0; i<h; i++)
		eng.add_edge(izmenjivac(0), cvor(0, i), INF, cena(i));
	for (int i=0; i<n; i++) {
		if (i != n-1) {
			for (int j=0; j<h; j++) {
				eng.add_edge(cvor(i, j), cvor(i+1, j), INF, 0);
				eng.add_edge(cvor(i, j), izmenjivac(i+1), INF, 0);
				eng.add_edge(izmenjivac(i+1), cvor(i+1, j), INF, cena(j));
			}
			eng.add_edge(source(), izmenjivac(i+1), 1, 0);
			eng.add_edge(izmenjivac(i+1), cvor(i+1, b[i]), 1, 0);
		}
		eng.add_edge(cvor(i, b[i]), sink(), 1, 0).first;
	}
	// for (int j=0; j<=h; j++)
	// 	eng.add_edge(cvor(n-1, j), sink(), INF, 10000);

	eng.run_to_flow(source(), sink(), n);
	cerr << "flow " << eng.flow << '\n';
	cerr << "cost " << eng.cost << '\n';

	// gledamo sta sve ulazi u ovaj cvor
	for (int i=0; i<n; i++) {
		for (int j=0; j<h; j++) {
			for (auto e : eng.g[cvor(i, j)]) {
				if (e.flow < 0)
					w[i] += basic_string<int>(-e.flow, aa[j]);
			}
		}

		// for (int x : w[i])
		// 	cerr << x << ' ';
		// cerr << '\n';
	}

	vector<string> sol;
	map<char, int> curr;
	for (int i=0; i<m; i++)
		curr['a' + i] = 0;

	for (int i=0; i<n; i++) {
		vector<pair<char, int>> xd(curr.begin(), curr.end());
		map<char, int> nx = curr;
		basic_string<int> unalloc;
		for (int x : w[i]) {
			auto it = find_if(xd.begin(), xd.end(), [&](auto p) {
				return p.second == x;
			});
			if (it == xd.end())
				unalloc += x;
			else
				xd.erase(it);
		}
		for (int x : unalloc) {
			sol.push_back(string(1, xd.back().first) + "=" + to_string(x));
			nx[xd.back().first] = x;
			xd.pop_back();
		}
		for (auto p : nx) {
			if (p.second == a[i]) {
				sol.push_back(string("print(") + p.first + ")");
			}
		}
		swap(nx, curr);
	}

	cout << sol.size() << ' ' << eng.cost << '\n';
	for (auto s : sol)
		cout << s << '\n';
}