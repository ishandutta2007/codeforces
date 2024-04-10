/*	author:  Kite_kuma
	created: 2020.09.07 15:33:15 */

#include <bits/stdc++.h>
using namespace std;

template <typename flow_t>
struct Dinic {
   private:
	const flow_t INF = numeric_limits<flow_t>::max() / 10;
	struct edge {
		int to;
		flow_t cap;
		int rev;
		bool isrev;
		int idx;
	};
	vector<vector<edge>> graph;
	vector<int> min_cost, iter;

	bool bfs(int s, int t) {
		min_cost.assign(graph.size(), -1);
		queue<int> que;
		min_cost[s] = 0;
		que.push(s);
		while(!que.empty() && min_cost[t] == -1) {
			int p = que.front();
			que.pop();
			for(auto &e : graph[p]) {
				if(e.cap > 0 && min_cost[e.to] == -1) {
					min_cost[e.to] = min_cost[p] + 1;
					que.push(e.to);
				}
			}
		}
		return min_cost[t] != -1;
	}

	flow_t dfs(int idx, const int t, flow_t flow) {
		if(idx == t) return flow;
		for(int &i = iter[idx]; i < (int)graph[idx].size(); i++) {
			edge &e = graph[idx][i];
			if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
				flow_t d = dfs(e.to, t, min(flow, e.cap));
				if(d > 0) {
					e.cap -= d;
					graph[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

   public:
	Dinic(int v = 0) : graph(v) {}

	void add_edge(int from, int to, flow_t cap, int idx = -1) {
		graph[from].emplace_back(edge{to, cap, (int)graph[to].size(), false, idx});
		graph[to].emplace_back(edge{from, 0, (int)graph[from].size() - 1, true, idx});
	}

	flow_t max_flow(int s, int t) {
		flow_t flow = 0;
		while(bfs(s, t)) {
			iter.assign(graph.size(), 0);
			flow_t f = 0;
			while((f = dfs(s, t, INF)) > 0) flow += f;
		}
		return flow;
	}

	void resize(int x) { graph.resize(x); }

	int size() { return (int)graph.size(); }
};

template <typename T>
struct ProjectSelectionProblem {
   private:
	int n;
	const T INF;
	T res = 0;
	Dinic<T> dinic;

   public:
	//n(true), n+1(false)
	ProjectSelectionProblem(int n_) : n(n_), INF(numeric_limits<T>::max()) { dinic.resize(n + 2); }

	void x_and_noty_loss(int x, int y, T loss) {
		assert(loss >= 0);
		dinic.add_edge(x, y, loss);
	}

	void x_xor_y_loss(int x, int y, T loss) {
		x_and_noty_loss(x, y, loss);
		x_and_noty_loss(y, x, loss);
	}

	void x_get(int x, T get) {
		if(get < 0) {
			dinic.add_edge(x, n + 1, -get);
			return;
		}
		res += get;
		notx_loss(x, get);
	}

	void x_loss(int x, T loss) {
		if(loss < 0) {
			x_get(x, -loss);
			return;
		}
		dinic.add_edge(x, n + 1, loss);
	}

	void notx_get(int x, T get) {
		if(get < 0) {
			dinic.add_edge(n, x, -get);
			return;
		}
		res += get;
		x_loss(x, get);
	}

	void notx_loss(int x, T loss) {
		if(loss < 0) {
			notx_get(x, -loss);
			return;
		}
		dinic.add_edge(n, x, loss);
	}

	void x_and_y_get(int x, int y, T get) {
		assert(get >= 0);
		res += get;
		dinic.resize(dinic.size() + 1);
		int w = dinic.size() - 1;
		dinic.add_edge(n, w, get);
		dinic.add_edge(w, x, INF);
		dinic.add_edge(w, y, INF);
	}

	void x_nor_y_get(int x, int y, T get) {
		assert(get >= 0);
		res += get;
		dinic.resize(dinic.size() + 1);
		int w = dinic.size() - 1;
		dinic.add_edge(w, n + 1, get);
		dinic.add_edge(x, w, INF);
		dinic.add_edge(y, w, INF);
	}

	void x_equal_y_get(int x, int y, T get) {
		x_and_y_get(x, y, get);
		x_nor_y_get(x, y, get);
	}

	//
	T solve() { return dinic.max_flow(n, n + 1) - res; }
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(15);
	srand((unsigned)time(NULL));

	int n, m;
	cin >> n >> m;
	vector<vector<char>> c(n, vector<char>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}

	auto conv = [&](int a, int b) { return a * m + b; };

	//1,0

	ProjectSelectionProblem<int> psp(n * m);
	using vi = vector<int>;
	using vvi = vector<vi>;
	vvi a(n, vi(m));
	int sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			a[i][j] = (c[i][j] == '#');
			sum += a[i][j];
		}
	}

	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < m; j++) {
			if(a[i][j] && a[i + 1][j]) {
				int k = conv(i, j), l = (conv(i + 1, j));
				psp.x_nor_y_get(k, l, 1);
			}
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m - 1; j++) {
			if(a[i][j] && a[i][j + 1]) {
				int k = conv(i, j), l = (conv(i, j + 1));
				psp.x_and_y_get(k, l, 1);
			}
		}

	sum += psp.solve();
	cout << sum << endl;

	return 0;
}