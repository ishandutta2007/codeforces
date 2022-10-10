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
	graph(int n): n(n), adj(n), ignore(nullptr){
	}
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
	graph reversed() const{ // returns the transpose of the directed graph
		graph res(n);
		for(auto &e: edges){
			res.orient(e.to, e.from, e.cost);
		}
		return res;
	}
};

// Requires graph
template<class T, T (*merge)(T, T), T (*identity)()>
struct dfs_forest_base{
	int n;
	vector<T> dist;
	vector<int> pv, pe, order, pos, end, sz, root, depth, min_depth, was;
	dfs_forest_base(int n){ init(n); }
	void init(int n){
		this->n = n;
		pv.assign(n, -1);
		pe.assign(n, -1);
		order.clear();
		pos.assign(n, -1);
		end.assign(n, -1);
		sz.assign(n, 0);
		root.assign(n, -1);
		depth.assign(n, -1);
		min_depth.assign(n, -1);
		dist.assign(n, identity());
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt;
	void dfs(graph<T> &g, int u, bool clear_order = true){
		++ attempt;
		depth[u] = 0;
		dist[u] = identity();
		root[u] = u;
		pv[u] = pe[u] = -1;
		if(clear_order) order.clear();
		function<void(int)> recurse = [&](int u){
			was[u] = attempt;
			pos[u] = (int)order.size();
			order.push_back(u);
			sz[u] = 1;
			min_depth[u] = depth[u];
			for(auto id: g.adj[u]){
				if(id == pe[u] || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = e.from ^ e.to ^ u;
				if(was[v] == attempt){
					min_depth[u] = min(min_depth[u], depth[v]);
					continue;
				}
				depth[v] = depth[u] + 1;
				dist[v] = merge(dist[u], e.cost);
				pv[v] = u;
				pe[v] = id;
				root[v] = ~root[u] ? root[u] : v;
				recurse(v);
				sz[u] += sz[v];
				min_depth[u] = min(min_depth[u], min_depth[v]);
			}
			end[u] = (int)order.size();
		};
		recurse(u);
	}
	void dfs_all(graph<T> &g){
		for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs(u, false);
	}
};
int add_merge(int x, int y){
	return x + y;
}
int add_id(){
	return {};
}
using dfs_forest = dfs_forest_base<int, add_merge, add_id>;

struct line_type{
	long long d, k, p;
	long long eval(long long x){ return d * x + k; }
};
template<bool GET_MAX = true>
struct sorted_line_container: deque<line_type>{
	static constexpr long long inf = numeric_limits<long long>::max();
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	long long div(long long a, long long b){ return a / b - ((a ^ b) < 0 && a % b); }
	bool isect_front(iterator x, iterator y){
		if(y == end()){ x->p = inf; return false; }
		else{ x->p = div(y->k - x->k, x->d - y->d); return x->p >= y->p; }
	}
	bool isect_back(reverse_iterator x, reverse_iterator y){
		if(x == rend()) return false;
		else{ x->p = div(y->k - x->k, x->d - y->d); return x->p >= y->p; }
	}
	template<bool First = true>
	void inc_push(line_type L){ // slopes should increase monotonously
		if(First && !GET_MAX){
			dec_push<false>({-L.d, -L.k});
			return;
		}
		assert(empty() || back().d <= L.d);
		if(empty() || back().d < L.d || back().k < L.k){
			if(!empty() && L.d == back().d) erase(-- end());
			L.p = inf, push_back(L); isect_back(++ rbegin(), rbegin());
			while((int)size() >= 2 && isect_back(++ ++ rbegin(), ++ rbegin())) erase(-- -- end()), isect_back(++ rbegin(), rbegin());
		}
	}
	template<bool First = true>
	void dec_push(line_type L){ // slopes should decrease monotonously
		if(First && !GET_MAX){
			inc_push<false>({-L.d, -L.k});
			return;
		}
		assert(empty() || L.d <= front().d);
		if(empty() || L.d < front().d || front().k < L.k){
			if(!empty() && L.d == front().d) erase(begin());
			L.p = 0, push_front(L), isect_front(begin(), ++ begin());
			while((int)size() >= 2 && isect_front(begin(), ++ begin())) erase(++ begin());
		}
	}
	long long dec_query(long long x){ // O(1), but other queries should not be called and x should be decreasing
		while((int)size() >= 2 && rbegin()->eval(x) <= (++ rbegin())->eval(x)) pop_back(); rbegin()->p = inf;
		return rbegin()->eval(x) * (GET_MAX ? 1 : -1);
	}
	long long inc_query(long long x){ // O(1) but other queries should not be called and x should be increasing
		while((int)size() >= 2 && begin()->eval(x) <= (++ begin())->eval(x)) pop_front();
		return begin()->eval(x) * (GET_MAX ? 1 : -1);
	}
	long long query(long long x){ // O(log n) but other queries should not be called
		if((int)size() == 1) return begin()->eval(x) * (GET_MAX ? 1 : -1);
		int low = 0, high = (int)size() - 1;
		if(begin()->eval(x) >= (++ begin())->eval(x)) return begin()->eval(x) * (GET_MAX ? 1 : -1);
		while(high - low > 1){
			int mid = low + high >> 1;
			(*this)[mid].eval(x) < (*this)[mid + 1].eval(x) ? low = mid : high = mid;
		}
		return (*this)[low + 1].eval(x) * (GET_MAX ? 1 : -1);
	}
};
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	graph<int> g(n);
	vector<int> par(n, -1);
	vector<pair<int, int>> val(n);
	for(auto u = 1; u < n; ++ u){
		cin >> par[u], -- par[u];
		g.orient(par[u], u);
	}
	for(auto u = 0; u < n; ++ u){
		cin >> val[u].first;
		if(u){
			val[u].first += val[par[u]].first;
		}
	}
	for(auto u = 0; u < n; ++ u){
		cin >> val[u].second;
		if(u){
			val[u].second += val[par[u]].second;
		}
	}
	dfs_forest df(n);
	df.dfs(g, 0);
	const int sz = 100, bcnt = (n + sz - 1) / sz;
	vector<pair<long long, long long>> coef(n); // B[u], A[u]*B[u]
	for(auto u = 0; u < n; ++ u){
		coef[u] = {val[u].second, 1LL * val[u].first * val[u].second};
	}
	vector<vector<int>> sorted_order(bcnt);
	for(auto b = 0; b < bcnt; ++ b){
		int l = b * sz, r = min(l + sz, n);
		sorted_order[b].assign(r - l, 0);
		for(auto i = l; i < r; ++ i){
			sorted_order[b][i - l] = df.order[i];
		}
		sort(sorted_order[b].begin(), sorted_order[b].end(), [&](int u, int v){ return coef[u] < coef[v]; });
	}
	vector<long long> xval(bcnt);
	vector<sorted_line_container<true>> lc1(bcnt);
	vector<sorted_line_container<false>> lc2(bcnt);
	auto rebuild = [&](int b){
		lc1[b].clear();
		lc2[b].clear();
		for(auto u: sorted_order[b]){
			lc1[b].inc_push({coef[u].first, coef[u].second});
			lc2[b].inc_push({coef[u].first, coef[u].second});
		}
	};
	for(auto b = 0; b < bcnt; ++ b){
		rebuild(b);
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 1){
			int u, x;
			cin >> u >> x, -- u;
			int l = df.pos[u], r = df.end[u] - 1;
			int lb = l / sz, rb = r / sz;
			if(lb == rb){
				for(auto i = l; i <= r; ++ i){
					coef[df.order[i]].second += x * coef[df.order[i]].first;
				}
				rebuild(lb);
			}
			else{
				for(auto i = l; i < (lb + 1) * sz; ++ i){
					coef[df.order[i]].second += x * coef[df.order[i]].first;
				}
				rebuild(lb);
				for(auto b = lb + 1; b <= rb - 1; ++ b){
					xval[b] += x;
				}
				for(auto i = rb * sz; i <= r; ++ i){
					coef[df.order[i]].second += x * coef[df.order[i]].first;
				}
				rebuild(rb);
			}
		}
		else{
			int u;
			cin >> u, -- u;
			int l = df.pos[u], r = df.end[u] - 1;
			int lb = l / sz, rb = r / sz;
			long long res = 0;
			if(lb == rb){
				for(auto i = l; i <= r; ++ i){
					ctmax(res, abs(coef[df.order[i]].first * xval[lb] + coef[df.order[i]].second));
				}
			}
			else{
				for(auto i = l; i < (lb + 1) * sz; ++ i){
					ctmax(res, abs(coef[df.order[i]].first * xval[lb] + coef[df.order[i]].second));
				}
				for(auto b = lb + 1; b <= rb - 1; ++ b){
					ctmax(res, max(lc1[b].inc_query(xval[b]), -lc2[b].inc_query(xval[b])));
				}
				for(auto i = rb * sz; i <= r; ++ i){
					ctmax(res, abs(coef[df.order[i]].first * xval[rb] + coef[df.order[i]].second));
				}
			}
			cout << res << "\n";
		}
	}
	return 0;
}

/*
Q(2B + N/B)
2BQ = NQ/B
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////