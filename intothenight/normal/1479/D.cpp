#include <bits/stdc++.h>
using namespace std;

template<class T>
struct graph{
	struct edge{
		int from, to;
		T cost;
	};
	int n;
	vector<edge> edges;
	vector<vector<int>> adj;
	function<bool(int)> ignore; // edge ignoration rule
	graph(int n): n(n), adj(n){ }
	int link(int u, int v, T w = 1){ // insert an undirected edge
		int id = (int)edges.size();
		adj[u].push_back(id), adj[v].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = 1){ // insert a directed edge
		int id = (int)edges.size();
		adj[u].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	graph transposed() const{ // the transpose of the directed graph
		graph res(n);
		for(auto &e: edges) res.orient(e.to, e.from, e.cost);
		res.ignore = ignore;
		return res;
	}
	int degree(int u){ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
};

template<class T>
struct sparse_table{
	int n;
	vector<vector<T>> data;
	function<T(T, T)> TT; // monoid operation (must be idempotent)
	T T_id; // monoid identity
	sparse_table(){ }
	sparse_table(const vector<T> &a, function<T(T, T)> TT, T T_id): n((int)a.size()), TT(TT), T_id(T_id), data({a}){ // O(n log n)
		for(auto p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			data.emplace_back(n - (p << 1) + 1);
			for(auto j = 0; j < (int)data[i].size(); ++ j) data[i][j] = TT(data[i - 1][j], data[i - 1][j + p]);
		}
	}
	T query(int l, int r){ // O(1)
		if(l >= r) return T_id;
		int d = __lg(r - l);
		return TT(data[d][l], data[d][r - (1 << d)]);
	}
};

// Requires graph and sparse_table
struct lca_solver{
	int n;
	vector<int> pos, depth, order, porder;
	sparse_table<int> rmq;
	template<class T>
	lca_solver(const graph<T> &g, const vector<int> &roots = {0}): n(g.n), depth(n), pos(n, -1){
		int it = 0;
		function<void(int, int)> dfs = [&](int u, int pe){
			pos[u] = it ++;
			for(auto id: g.adj[u]) if(id != pe){
				if(g.ignore && g.ignore(id)) continue;
				order.push_back(u), porder.push_back(pos[u]);
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				depth[v] = depth[u] + 1;
				dfs(v, id);
			}
		};
		for(auto root: roots) if(!~pos[root]) dfs(root, -1);
		rmq = {porder, [&](int x, int y){ return min(x, y); }, numeric_limits<int>::max() / 2};
	}
	int query(int u, int v){
		if(u == v) return u;
		tie(u, v) = minmax(pos[u], pos[v]);
		return order[rmq.query(u, v)];
	}
	int steps(int u, int v, int w = -1){ return depth[u] + depth[v] - 2 * depth[~w ? w : query(u, v)]; }
};

// Reorder N 2D points with max_x - min_x <= X, max_y - min_y <= Y
// so that sum(abs(xi - x(i+1)) + abs(yi - y(i+1)) is small
// and process queries on the new order.
// O(N BX) inc_x and dec_x calls, O(X Y / BX) inc_y and dec_y calls
// set BX = O(sqrt(X Y / N)) to achieve O(sqrt(X Y N)) calls, 2 * sqrt(X Y / N) works well in general
template<int BX>
struct mo_2d{
	vector<array<int, 3>> points; // x, y, ind
	void insert(int x, int y, int id){
		points.push_back({x, y, id});
	}
	void solve( // starting from (0, 0), access each points and execute queries
		function<void()> inc_x, function<void()> dec_x,
		function<void()> inc_y, function<void()> dec_y,
		function<void(int)> process
	){
		auto cmp = [&](const auto &p, const auto &q)->bool{
			return p[0] / BX != q[0] / BX ? p[0] < q[0] : p[0] / BX & 1 ^ p[1] < q[1];
		};
		sort(points.begin(), points.end(), cmp);
		int x = 0, y = 0;
		for(auto &[qx, qy, id]: points){
			while(qx < x) dec_x(), -- x;
			while(y < qy) inc_y(), ++ y;
			while(x < qx) inc_x(), ++ x;
			while(qy < y) dec_y(), -- y;
			process(id);
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<int> val(n);
	for(auto u = 0; u < n; ++ u){
		cin >> val[u], -- val[u];
	}
	graph<int> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v);
	}
	lca_solver lca(g);
	vector<int> end(n), order;
	function<void(int, int)> dfs = [&](int u, int pe){
		order.push_back(val[u]);
		for(auto id: g.adj[u]){
			if(id == pe || g.ignore && g.ignore(id)) continue;
			auto &e = g.edges[id];
			int v = u ^ e.from ^ e.to;
			dfs(v, id);
		}
		end[u] = (int)order.size();
		order.push_back(val[u]);
	};
	dfs(0, -1);
	vector<array<int, 4>> query(qn);
	mo_2d<(int)(sqrt(3e5) * 2)> mo;
	for(auto i = 0; i < qn; ++ i){
		int u, v, l, r;
		cin >> u >> v >> l >> r, -- u, -- v, -- l;
		if(end[u] > end[v]){
			swap(u, v);
		}
		query[i] = {u, v, l, r};
		mo.insert(end[u], end[v], i);
	}

	const int block = 1 << 8;
	const int block_cnt = (n + block - 1) / block + 1;
	vector<int> bag_size(block_cnt);
	vector<int> state(n);
	auto flip = [&](int x){
		bag_size[x / block] -= state[x];
		bag_size[x / block] += state[x] ^= 1;
	};

	int left = 0, right = 0;
	auto inc_x = [&](){
		flip(order[left ++]);
	};
	auto dec_x = [&](){
		flip(order[-- left]);
	};
	auto inc_y = [&](){
		flip(order[right ++]);
	};
	auto dec_y = [&](){
		flip(order[-- right]);
	};
	vector<int> res(qn, -1);
	auto process = [&](int qid){
		auto [u, v, l, r] = query[qid];
		flip(val[lca.query(u, v)]);
		if(auto idl = l / block, idr = r / block; idl == idr){
			for(auto x = l; x < r; ++ x){
				if(state[x]){
					res[qid] = x + 1;
					break;
				}
			}
		}
		else{
			for(auto x = (l / block + 1) * block - 1; x >= l; -- x){
				if(state[x]){
					res[qid] = x + 1;
					goto DONE;
				}
			}
			for(auto x = r / block * block; x < r; ++ x){
				if(state[x]){
					res[qid] = x + 1;
					goto DONE;
				}
			}
			for(auto id = idl + 1; id < idr; ++ id){
				if(bag_size[id]){
					for(auto x = id * block, high = x + block; x < high; ++ x){
						if(state[x]){
							res[qid] = x + 1;
							goto DONE;
						}
					}
				}
			}
			DONE:;
		}
		flip(val[lca.query(u, v)]);
	};
	mo.solve(inc_x, dec_x, inc_y, dec_y, process);
	for(auto x: res){
		cout << x << "\n";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////