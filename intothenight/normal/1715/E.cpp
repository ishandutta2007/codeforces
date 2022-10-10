#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }

template<class T>
struct graph{
	struct E{
		int from, to;
		T cost;
	};
	int n;
	vector<E> edge;
	vector<vector<int>> adj;
	function<bool(int)> ignore;
	graph(int n = 0): n(n), adj(n){ }
	graph(const vector<vector<int>> &adj, bool undirected = true): n(n){
		if(undirected) for(auto u = 0; u < n; ++ u) for(auto v: adj[u]) if(u < v) link(u, v);
		else for(auto u = 0; u < n; ++ u) for(auto v: adj[u]) orient(u, v);
	}
	graph(const vector<vector<pair<int, T>>> &adj, bool undirected = true): n(n){
		if(undirected) for(auto u = 0; u < n; ++ u) for(auto [v, w]: adj[u]) if(u < v) link(u, v, w);
		else for(auto u = 0; u < n; ++ u) for(auto [v, w]: adj[u]) orient(u, v, w);
	}
	graph(int n, vector<array<int, 2>> &edge, bool undirected = true): n(n){
		for(auto [u, v]: edge) undirected ? link(u, v) : orient(u, v);
	}
	graph(int n, vector<tuple<int, int, T>> &edge, bool undirected = true): n(n){
		for(auto [u, v, w]: edge) undirected ? link(u, v, w) : orient(u, v, w);
	}
	int operator()(int u, int id) const{
		#ifdef LOCAL
		assert(0 <= id && id < (int)edge.size());
		assert(edge[id].from == u || edge[id].to == u);
		#endif
		return u ^ edge[id].from ^ edge[id].to;
	}
	int link(int u, int v, T w = {}){ // insert an undirected edge
		int id = (int)edge.size();
		adj[u].push_back(id), adj[v].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = {}){ // insert a directed edge
		int id = (int)edge.size();
		adj[u].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	graph transposed() const{ // the transpose of the directed graph
		graph res(n);
		for(auto &e: edge) res.orient(e.to, e.from, e.cost);
		res.ignore = ignore;
		return res;
	}
	int degree(int u) const{ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
	vector<vector<int>> get_adjacency_list() const{
		vector<vector<int>> res(n);
		for(auto u = 0; u < n; ++ u) for(auto id: adj[u]){
			if(ignore && ignore(id)) continue;
			auto &e = edge[id];
			int v = u ^ e.from ^ e.to;
			res[u].push_back(v);
		}
		return res;
	}
	void set_ignoration_rule(const function<bool(int)> &f){
		ignore = f;
	}
	void reset_ignoration_rule(){
		ignore = nullptr;
	}
	friend ostream &operator<<(ostream &out, const graph &g){
		for(auto id = 0; id < (int)g.edge.size(); ++ id){
			if(g.ignore && g.ignore(id)) continue;
			auto &e = g.edge[id];
			out << "{" << e.from << ", " << e.to << ", " << e.cost << "}\n";
		}
		return out;
	}
};

template<class T>
struct dijkstra{
	int n;
	vector<T> dist;
	vector<int> pv, pe, was, order;
	dijkstra(int n){ init(n); }
	void init(int n){
		this->n = n;
		dist.assign(n, numeric_limits<T>::max() / 2);
		pv.assign(n, -1);
		pe.assign(n, -1);
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt;
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
	// O((|V| + |E|) * log |V|) where
	// V is the set of vertices reachable from src and
	// E is the set of edges reachable from src
	// Requires graph
	template<class Graph>
	void run(const Graph &g, const vector<pair<int, T>> &src){
		assert(n == g.n);
		++ attempt;
		for(auto [u, x]: src){
			was[u] = attempt;
			pq.push({dist[u] = x, u});
			pv[u] = -1;
			pe[u] = -1;
		}
		order.clear();
		while(!pq.empty()){
			T d;
			int u;
			tie(d, u) = pq.top();
			pq.pop();
			if(d != dist[u]) continue;
			order.push_back(u);
			for(auto id: g.adj[u]){
				if(g.ignore && g.ignore(id)) continue;
				auto &e = g.edge[id];
				int v = u ^ e.from ^ e.to;
				if(was[v] != attempt || dist[u] + e.cost < dist[v]){
					pq.push({dist[v] = dist[u] + e.cost, v});
					pv[v] = u, pe[v] = id, was[v] = attempt;
				}
			}
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, k;
	cin >> n >> m >> k;
	graph<int> g(n);
	for(auto i = 0; i < m; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		g.link(u, v, w);
	}
	dijkstra<long long> D(n);
	D.run(g, {{0, 0}});
	vector<long long> res(n, numeric_limits<long long>::max());
	for(auto u = 0; u < n; ++ u){
		if(D.was[u] == D.attempt){
			res[u] = D.dist[u];
		}
	}
	vector<pair<int, long long>> src(n);
	for(auto u = 0; u < n; ++ u){
		src[u].first = u;
	}
	for(auto rep = 0; rep < k; ++ rep){
		static deque<pair<int, long long>> stack;
		stack.clear();
		auto bad = [&](auto x, auto y, auto z)->bool{
			long long p1 = y.first + x.first + (y.second - x.second) / (y.first - x.first);
			array<long long, 2> q1 = {(y.second - x.second) % (y.first - x.first), y.first - x.first};

			long long p2 = z.first + y.first + (z.second - y.second) / (z.first - y.first);
			array<long long, 2> q2 = {(z.second - y.second) % (z.first - y.first), z.first - y.first};

			if(p1 != p2){
				return p1 >= p2;
			}
			else{
				return __int128_t(q1[0]) * q2[1] >= __int128_t(q2[0]) * q1[1];
			}
		};
		auto insert = [&](int x, long long y)->void{
			while(!stack.empty() && (
				stack.back().second >= y ||
				(int)stack.size() >= 2 && bad(stack.end()[-2], stack.end()[-1], pair<int, long long>{x, y})
			)){
				stack.pop_back();
			}
			stack.push_back({x, y});
		};
		auto calc = [&](pair<int, long long> x, int at)->long long{
			return 1LL * (at - x.first) * (at - x.first) + x.second;
		};
		auto eval = [&](int x)->long long{
			assert(!stack.empty());
			while((int)stack.size() >= 2 && calc(stack[0], x) >= calc(stack[1], x)){
				stack.pop_front();
			}
			return calc(stack[0], x);
		};
		ranges::fill(src | ranges::views::values, numeric_limits<long long>::max());
		for(auto u = 0; u < n; ++ u){
			insert(u, D.dist[u]);
			ctmin(src[u].second, eval(u));
		}
		stack.clear();
		for(auto u = n - 1; u >= 0; -- u){
			insert(-u, D.dist[u]);
			ctmin(src[u].second, eval(-u));
		}
		D.run(g, src);
		for(auto u = 0; u < n; ++ u){
			ctmin(res[u], D.dist[u]);
		}
	}
	ranges::copy(res, ostream_iterator<long long>(cout, " "));
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////