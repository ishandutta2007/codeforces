#include <bits/stdc++.h>
using namespace std;

template<class T, class U>
struct lazy_segment_tree_range_add_range_min_index{
	int n, size, log;
	T inf = numeric_limits<T>::max() / 2;
	vector<pair<T, int>> data;
	vector<U> updates;
	lazy_segment_tree_range_add_range_min_index(int n): lazy_segment_tree_range_add_range_min_index(vector<T>(n, inf)){ }
	lazy_segment_tree_range_add_range_min_index(int n, T init): lazy_segment_tree_range_add_range_min_index(vector<T>(n, init)){ }
	lazy_segment_tree_range_add_range_min_index(const vector<T> &a): n((int)a.size()){ // O(n)
		log = __lg(max(n - 1, 1)) + 1, size = 1 << log;
		data = vector<pair<T, int>>(size << 1), updates = vector<U>(size);
		for(auto i = 0; i < n; ++ i) data[i + size] = pair<T, int>{a[i], -i};
		for(auto i = size - 1; i >= 1; -- i) refresh(i);
	}
	void refresh(int i){ data[i] = min(data[i << 1], data[i << 1 | 1]); }
	void apply(int i, U f){
		data[i].first += f;
		if(i < size) updates[i] += f;
	}
	void push(int i){
		apply(i << 1, updates[i]), apply(i << 1 | 1, updates[i]);
		updates[i] = 0;
	}
	// O(log n)
	pair<T, int> query(int p){
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		return {data[p].first, -data[p].second};
	}
	// O(log n)
	pair<T, int> query(int l, int r){
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return {inf, -1};
		l += size, r += size;
		for(auto i = log; i >= 1; -- i) {
			if(l >> i << i != l) push(l >> i);
			if(r >> i << i != r) push(r - 1 >> i);
		}
		pair<T, int> res_left{inf, -1}, res_right{inf, -1};
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) res_left = min(res_left, data[l ++]);
			if(r & 1) res_right = min(data[-- r], res_right);
		}
		auto res = min(res_left, res_right);
		return {res.first, -res.second};
	}
	// O(1)
	pair<T, int> query_all(){
		return {data[1].first, -data[1].second};
	}
	// O(log n)
	void set(int p, T x){
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		data[p].first = x;
		for(auto i = 1; i <= log; ++ i) refresh(p >> i);
	}
	// O(log n)
	void update(int p, U f){
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		data[p].first += f;
		for(auto i = 1; i <= log; ++ i) refresh(p >> i);
	}
	// O(log n)
	void update(int l, int r, U f){
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return;
		l += size, r += size;
		for(auto i = log; i >= 1; -- i){
			if(l >> i << i != l) push(l >> i);
			if(r >> i << i != r) push(r - 1 >> i);
		}
		int l2 = l, r2 = r;
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) apply(l ++, f);
			if(r & 1) apply(-- r, f);
		}
		l = l2, r = r2;
		for(auto i = 1; i <= log; ++ i){
			if(l >> i << i != l) refresh(l >> i);
			if(r >> i << i != r) refresh(r - 1 >> i);
		}
	}
	// f(sum[l, r)) is T, T, ..., T, F, F, ..., F, returns min r with F (n + 1 if no such r)
	// O(log n)
	int max_pref(int l, auto g){
		assert(0 <= l && l <= n);
		if(!g(pair<T, int>{inf, -1})) return l;
		// if(l == n) return n + 1; // is this needed?
		l += size;
		for(auto i = log; i >= 1; -- i) push(l >> i);
		pair<T, int> sm{inf, -1};
		do{
			while(~l & 1) l >>= 1;
			if(!g(min(sm, data[l]))){
				while(l < size){
					push(l);
					l = l << 1;
					if(g(min(sm, data[l]))) sm = min(sm, data[l ++]);
				}
				return l - size + 1;
			}
			sm = min(sm, data[l]);
			++ l;
		}while((l & -l) != l);
		return n + 1;
	}
	// f(sum[l, r)) is F, F, ..., F, T, T, ..., T, returns max l with F (-1 if no such l)
	// O(log n)
	int min_suff(int r, auto g){
		assert(0 <= r && r <= n);
		if(!g(pair<T, int>{inf, -1})) return r;
		// if(r == 0) return -1; // is this needed?
		r += size;
		for(auto i = log; i >= 1; -- i) push(r - 1 >> i);
		pair<T, int> sm{inf, -1};
		do{
			-- r;
			while(r > 1 && r & 1) r >>= 1;
			if(!g(min(data[r], sm))){
				while(r < size){
					push(r);
					r = r << 1 | 1;
					if(g(min(data[r], sm))) sm = min(data[r --], sm);
				}
				return r - size;
			}
			sm = min(data[r], sm);
		}while((r & -r) != r);
		return -1;
	}
};

// Given an array of distinct integers,
// a subarray S is said to be consecutive if max(S) - min(S) = len(S), and
// a consecutive subarray S is said to be primitive if for any other consecutive subarray T, either S and T are disjoint or one contains the other
// A consecutive subarray can be partitioned uniquely into maximum primitive consecutive subarrays.
// There are O(n) primitive consecutive subarrays.
// They form a forest of arboresence according to inclusion relation
// Cut: Childs of the node are not sorted in either order. Here, any consecutive interval of childs of length >= 2 is not a consecutive subarray.
// Join: Childs of the node are sorted in either order. Here, any consecutive interval of childs form a consecutive subarray
// Requires lazy_segment_tree_range_add_range_min_index
template<class T>
struct cut_join_tree{
	int n = 0;
	// 0: leaf, 1: cut, 2: join(increasing), 3: join(decreasing)
	vector<int> type;
	// index range of a node u
	vector<array<int, 2>> index_range;
	// value range of a node u
	vector<array<T, 2>> value_range;
	// childs of a node u
	vector<vector<int>> adj;
	// set of root of the forest
	vector<int> root;
	cut_join_tree(int mx): ds(mx){ }
	cut_join_tree(const vector<T> &a): ds((int)a.size()){
		for(auto x: a) extend(x);
	}
	vector<pair<T, int>> min_stack, max_stack;
	lazy_segment_tree_range_add_range_min_index<T, T> ds;
	int new_node(int t, array<int, 2> ind, array<T, 2> val){
		int u = (int)type.size();
		type.push_back(t);
		index_range.push_back(ind);
		value_range.push_back(val);
		adj.emplace_back();
		return u;
	}
	// Assumes x has never been inserted before
	// Amortized O(log n)
	void extend(T x){
		assert(n < ds.n);
		ds.update(0, (int)root.size(), -1);
		while(!min_stack.empty() && min_stack.back().first > x){
			auto [px, r] = min_stack.back();
			min_stack.pop_back();
			ds.update(min_stack.empty() ? 0 : min_stack.back().second + 1, r + 1, px - x);
		}
		min_stack.push_back({x, (int)root.size()});
		while(!max_stack.empty() && max_stack.back().first < x){
			auto [px, r] = max_stack.back();
			max_stack.pop_back();
			ds.update(max_stack.empty() ? 0 : max_stack.back().second + 1, r + 1, x - px);
		}
		max_stack.push_back({x, (int)root.size()});
		int u = new_node(0, {n, n + 1}, {x, x + 1});
		while(!root.empty()){
			int v = root.back();
			if(type[v] == 2 && value_range[v][1] == value_range[u][0]){
				adj[v].push_back(u);
				index_range[v][1] = n + 1;
				value_range[v][1] = value_range[u][1];
				u = v;
				root.pop_back();
			}
			else if(type[root.back()] == 3 && value_range[u][1] == value_range[v][0]){
				adj[v].push_back(u);
				index_range[v][1] = n + 1;
				value_range[v][0] = value_range[u][0];
				u = v;
				root.pop_back();
			}
			else if(auto [minval, i] = ds.query(0, (int)root.size()); !minval){
				if(i == (int)root.size() - 1){
					int w = new_node(2 + (value_range[v][0] > value_range[u][0]), {index_range[v][0], n + 1}, {min(value_range[v][0], value_range[u][0]), max(value_range[v][1], value_range[u][1])});
					adj[w] = {v, u};
					u = w;
					root.pop_back();
				}
				else{
					int w = new_node(1, {index_range[root[i]][0], n + 1}, accumulate(root.begin() + i, root.end(), value_range[u], [&](array<T, 2> val, int u){ return array<T, 2>{min(val[0], value_range[u][0]), max(val[1], value_range[u][1])}; }));
					adj[w] = {root.begin() + i, root.end()};
					adj[w].push_back(u);
					u = w;
					root.resize(i);
				}
			}
			else break;
		}
		root.push_back(u);
		T last = -1;
		while(!min_stack.empty() && (int)root.size() <= min_stack.back().second){
			last = min_stack.back().first;
			min_stack.pop_back();
		}
		if(~last) min_stack.push_back({last, (int)root.size() - 1});
		last = -1;
		while(!max_stack.empty() && (int)root.size() <= max_stack.back().second){
			last = max_stack.back().first;
			max_stack.pop_back();
		}
		if(~last) max_stack.push_back({last, (int)root.size() - 1});
		ds.set((int)root.size() - 1, (value_range[u][1] - value_range[u][0]) - (index_range[u][1] - index_range[u][0]));
		++ n;
	}
	int size() const{
		return (int)type.size();
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> p(n);
	for(auto i = 0; i < n; ++ i){
		int x, y;
		cin >> x >> y, -- x, -- y;
		p[x] = y;
	}
	cut_join_tree<int> cjt(n);
	for(auto i = 0; i < n; ++ i){
		cjt.extend(p[i]);
	}
	long long res = (int)cjt.size();
	for(auto u = 0; u < (int)cjt.size(); ++ u){
		if(cjt.type[u] >= 2){
			res += 1LL * (int)cjt.adj[u].size() * ((int)cjt.adj[u].size() - 1) / 2 - 1;
		}
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////