/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/push_back_ds/assoc_container.hpp>
// #include <ext/push_back_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_push_backds;
// using namespace __gnu_cxx;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
		freopen(fileerr.c_str(), "w", stderr);
#endif
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	FAST_IO("input.inp", "output.out", "error.err");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
#endif
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

struct flowEdge {
	int u, v;
	long long c, f, cost;
	flowEdge(int u, int v, long long c, long long cost)
		: u(u), v(v), c(c), f(0), cost(cost) {}
};
 
struct mcf {
	const long long inf = 4e18;

	int n, m, s, t;
	vector<flowEdge> e;
	vector<int> g[3005];
	// g[i] actualong longy stores the edge IDs, not the vertices themselves
	long long d[3005], pi[3005];
	int p[3005];
 	

	void init(int n) {
		this->n = n; m = 0;
		e.clear();
		for (int i = 0; i <= n; ++i) g[i].clear();
	}

	void addEdge(int u, int v, long long c, long long cost) {
		g[u].push_back(e.size()); e.emplace_back(u, v, c, cost);
		g[v].push_back(e.size()); e.emplace_back(v, u, 0, -cost);
		m = e.size();
	}
 
	void bellman() {
		for (int i = 0; i <= n; ++i) pi[i] = inf;
 
		pi[s] = 0;
		for (int iter = 1; iter <= n - 1; ++iter) {
			for (auto x : e) {
				int u = x.u, v = x.v; long long w = x.cost;
				if (pi[u] == inf) continue;
				if (x.c - x.f >= 1 && pi[u] + w < pi[v])
					pi[v] = pi[u] + w;
			}
		}
	}
 
	bool dijkstra() {
		for (int i = 0; i <= n; ++i) d[i] = inf, p[i] = -1;
 
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
		pq.push({0, s});
		d[s] = 0;
 
		while (!pq.empty()) {
			auto [dist, u] = pq.top();
			pq.pop();
 
			if (dist != d[u]) continue;
			for (auto id : g[u]) {
				int v = e[id].v; long long w = e[id].cost + pi[u] - pi[v];
				if (e[id].c - e[id].f >= 1 && d[u] + w < d[v]) {
					p[v] = id;
					d[v] = d[u] + w;
					pq.push({d[v], v});
				}
			}
		}
		return d[t] != inf;
	}
 
	long long mncost(int s, int t, long long k) {
		this->s = s; this->t = t;
 
		bellman();
		long long totflow = 0, totcost = 0;
		while (totflow < k) {
			if (!dijkstra()) break;
			for (int i = 0; i <= n; ++i) pi[i] = min(inf, pi[i] + d[i]);
		
			long long flow = k - totflow;
			for (int cur = t; cur != s; cur = e[p[cur]].u)
				flow = min(flow, e[p[cur]].c - e[p[cur]].f);
 
			totflow += flow;
			totcost += flow*pi[t];
			for (int cur = t; cur != s; cur = e[p[cur]].u) {
				e[p[cur]].f += flow;
				e[p[cur] ^ 1].f -= flow;
			}
		}
		return (totflow < k) ? -1 : totcost;
	}
} mcmf;

int n, k;

void Hollwo_Pelw() {
	cin >> n >> k;
	mcmf.init(n + 1);
	for (int i = 1, x; i <= n; i++)
		cin >> x, mcmf.addEdge(0, i, 1, x);
	for (int i = 1, x; i <= n; i++)
		cin >> x, mcmf.addEdge(i, n + 1, 1, x);
	for (int i = 1; i < n; i++)
		mcmf.addEdge(i, i + 1, k, 0);
	cout << mcmf.mncost(0, n + 1, k);
}