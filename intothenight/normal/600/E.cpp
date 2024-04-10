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
	int link(int u, int v, T w = {}){ // insert an undirected edge
		int id = (int)edges.size();
		adj[u].push_back(id), adj[v].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = {}){ // insert a directed edge
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

// O(log n) applications of insert() and erase(), O(n) applications of answer()
// Requires graph
template<class T>
struct small_to_large_on_forest{
	int n;
	graph<T> g;
	vector<int> roots, sz, order, pos, end;
	small_to_large_on_forest(const graph<T> &g, vector<int> roots = {}): n(g.n), g(g), sz(n, 1), pos(n, -1), end(n, -1){
		function<void(int, int)> dfs = [&](int u, int pe){
			pos[u] = (int)order.size();
			order.push_back(u);
			for(auto id: g.adj[u]){
				if(id == pe || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				dfs(v, id);
				sz[u] += sz[v];
			}
			end[u] = (int)order.size();
		};
		if(roots.empty()){
			for(auto u = 0; u < n; ++ u) if(!~pos[u]){
				roots.push_back(u);
				dfs(u, -1);
			}
		}
		else{
			this->roots = roots;
			for(auto u: roots) assert(!~pos[u]), dfs(u, -1);
		}
	}
	void solve(int root, function<void(int)> insert, function<void(int)> erase, function<void(int)> answer){
		function<void(int, int, bool)> dfs = [&](int u, int pe, bool keep){
			int hv = -1, hid = -1;
			for(auto id: g.adj[u]){
				if(id == pe || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(!~hv || sz[hv] < sz[v]) hv = v, hid = id;
			}
			for(auto id: g.adj[u]){
				if(id == pe || id == hid || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				dfs(v, id, false);
			}
			if(~hid) dfs(hv, hid, true);
			for(auto id: g.adj[u]){
				if(id == pe || id == hid || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				for(auto i = pos[v]; i < end[v]; ++ i) insert(order[i]);
			}
			insert(u);
			answer(u);
			if(!keep){
				for(auto i = pos[u]; i < end[u]; ++ i) erase(order[i]);
			}
		};
		dfs(root, -1, false);
	}
	void solve_all(function<void(int)> insert, function<void(int)> erase, function<void(int)> answer){
		for(auto r: roots) solve(r, insert, erase, answer);
	}
};

struct unital_sorter{
	int n, m; // # of items, maximum possible freq
	vector<int> order, pos, freq; // items sorted by freq, position of items in the order
	vector<array<int, 2>> bound; // bound[x] represents the range in the order for freq x
	unital_sorter(int n, int m): n(n), m(m), order(n), pos(n), freq(n), bound(m + 1, {n, n}){
		bound[0] = {0, n};
		iota(order.begin(), order.end(), 0);
		iota(pos.begin(), pos.end(), 0);
	}
	unital_sorter(int n, int m, const vector<int> &freq): n(n), m(m), pos(n), freq(freq), bound(m + 1){
		iota(order.begin(), order.end(), 0);
		vector<vector<int>> occur(m + 1);
		for(auto i = 0; i < n; ++ i) occur[freq[i]].push_back(i);
		for(auto f = 0; f <= m; ++ f){
			bound[f][0] = (int)order.size();
			order.insert(order.end(), occur[f].begin(), occur[f].end());
			bound[f][1] = (int)order.size();
			for(auto t = bound[f][0]; t < bound[f][1]; ++ t) pos[order[t]] = t;
		}
	}
	void insert(int x){
		assert(freq[x] + 1 <= m);
		-- bound[freq[x]][1];
		-- bound[freq[x] + 1][0];
		int y = order[bound[freq[x] ++][1]];
		swap(pos[x], pos[y]);
		swap(order[pos[x]], order[pos[y]]);
	}
	void erase(int x){
		assert(freq[x]);
		int y = order[bound[freq[x] - 1][1]];
		swap(pos[x], pos[y]);
		swap(order[pos[x]], order[pos[y]]);
		++ bound[freq[x]][0];
		++ bound[-- freq[x]][1];
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> color(n);
	for(auto u = 0; u < n; ++ u){
		cin >> color[u];
	}
	graph<int> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v);
	}
	vector<long long> res(n);
	vector<long long> sum(n); // sum of colors of occurence i
	unital_sorter sorter(n + 1, n);
	auto insert = [&](int c){
		c = color[c];
		sum[sorter.freq[c]] -= c;
		sorter.insert(c);
		sum[sorter.freq[c]] += c;
	};
	auto erase = [&](int c){
		c = color[c];
		sum[sorter.freq[c]] -= c;
		sorter.erase(c);
		sum[sorter.freq[c]] += c;
	};
	auto answer = [&](int u){
		res[u] = sum[sorter.freq[sorter.order.back()]];
	};
	small_to_large_on_forest solver(g, {0});
	solver.solve_all(insert, erase, answer);
	for(auto x: res){
		cout << x << " ";
	}
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