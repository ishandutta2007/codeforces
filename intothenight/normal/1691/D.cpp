#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

// Source: https://en.wikipedia.org/wiki/Cartesian_tree#Efficient_construction
// Tie broken by index (smaller index has lower depth)
template<class T, class Compare = less<>>
struct cartesian_tree{
	int n = 0, root = -1;
	vector<T> data;
	vector<int> pv;
	vector<array<int, 2>> adj;
	Compare cmp;
	cartesian_tree(const vector<T> &data = {}, Compare cmp = less<>()): cmp(cmp){
		extend(data);
	}
	cartesian_tree &operator=(const cartesian_tree &ct){
		n = ct.n;
		root = ct.root;
		data = ct.data;
		pv = ct.pv;
		adj = ct.adj;
	}
	void extend(const vector<T> &a){
		for(auto x: a) extend(x);
	}
	// Amortized O(1)
	void extend(T x){
		data.push_back(x);
		pv.push_back(-1);
		adj.push_back({-1, -1});
		int u = n - 1;
		while(~u && cmp(x, data[u])) u = pv[u];
		if(!~u && ~root || ~u && ~adj[u][1]){
			int v = ~u ? adj[u][1] : root;
			pv[v] = n;
			adj[n][0] = v;
		}
		if(~u){
			adj[u][1] = n;
			pv[n] = u;
		}
		if(!~u) root = n;
		++ n;
	}
	// Warning: calling extend() invalidates the bfs states
	vector<int> order;
	vector<int> pos;
	vector<int> size;
	vector<int> depth;
	vector<array<int, 2>> range;
	vector<int> q;
	void bfs(){
		order.clear();
		pos.assign(n, -1);
		size.assign(n, 1);
		depth.assign(n, 0);
		range.assign(n, {});
		q = {root};
		for(auto l = 0; l < (int)q.size(); ++ l){
			int u = q[l];
			pos.push_back((int)order.size());
			order.push_back(u);
			for(auto v: adj[u]) if(~v){
				depth[v] = depth[u] + 1;
				q.push_back(v);
			}
		}
		for(auto i = (int)order.size() - 1; i >= 0; -- i){
			int u = order[i];
			for(auto v: adj[u]) if(~v) size[u] += size[v];
			range[u] = {u, u + 1};
			if(~adj[u][0]) range[u][0] -= size[adj[u][0]];
			if(~adj[u][1]) range[u][1] += size[adj[u][1]];
			assert(range[u][1] - range[u][0] == size[u]);
		}
	}
};

template<class T, class F>
struct segment_tree{
	int n, size, log;
	vector<T> data;
	F TT; // monoid operation (always adjacent)
	T T_id; // monoid identity
	// O(n)
	segment_tree(int n, F TT, T T_id): segment_tree(vector<T>(n, T_id), TT, T_id){}
	// O(n)
	segment_tree(int n, T init, F TT, T T_id): segment_tree(vector<T>(n, init), TT, T_id){}
	// O(n)
	segment_tree(const vector<T> &a, F TT, T T_id): n((int)a.size()), TT(TT), T_id(T_id){ // O(n)
		log = __lg(max(n - 1, 1)) + 1, size = 1 << log;
		data = vector<T>(size << 1, T_id);
		copy(a.begin(), a.end(), data.begin() + size);
		for(auto i = size - 1; i >= 1; -- i) refresh(i);
	}
	// O(1)
	void refresh(int i){
		data[i] = TT(data[i << 1], data[i << 1 | 1]);
	}
	// O(log n)
	void set(int p, T x){
		assert(0 <= p && p < n);
		data[p += size] = x;
		for(auto i = 1; i <= log; ++ i) refresh(p >> i);
	}
	// O(log n)
	void update(int p, T x){
		assert(0 <= p && p < n);
		p += size;
		data[p] = TT(data[p], x);
		for(auto i = 1; i <= log; ++ i) refresh(p >> i);
	}
	// O(1)
	T query(int p) const{
		assert(0 <= p && p < n);
		return data[p + size];
	}
	// O(log n)
	T query(int l, int r) const{
		assert(0 <= l && l <= r && r <= n);
		T res_left = T_id, res_right = T_id;
		for(l += size, r += size; l < r; l >>= 1, r >>= 1){
			if(l & 1) res_left = TT(res_left, data[l ++]);
			if(r & 1) res_right = TT(data[-- r], res_right);
		}
		return TT(res_left, res_right);
	}
	// O(1)
	T query_all() const{
		return data[1];
	}
	// pred(sum[l, r)) is T, T, ..., T, F, F, ..., F
	// Returns max r with T
	// O(log n)
	int max_pref(int l, auto pred) const{
		assert(0 <= l && l <= n && pred(T_id));
		if(l == n) return n;
		l += size;
		T sm = T_id;
		do{
			while(~l & 1) l >>= 1;
			if(!pred(TT(sm, data[l]))){
				while(l < size){
					l = l << 1;
					if(pred(TT(sm, data[l]))) sm = TT(sm, data[l ++]);
				}
				return l - size;
			}
			sm = TT(sm, data[l ++]);
		}while((l & -l) != l);
		return n;
	}
	// pred(sum[l, r)) is F, F, ..., F, T, T, ..., T
	// Returns min l with T
	// O(log n)
	int min_suff(int r, auto pred) const{
		assert(0 <= r && r <= n && pred(T_id));
		if(r == 0) return 0;
		r += size;
		T sm = T_id;
		do{
			-- r;
			while(r > 1 && r & 1) r >>= 1;
			if(!pred(TT(data[r], sm))){
				while(r < size){
					r = r << 1 | 1;
					if(pred(TT(data[r], sm))) sm = TT(data[r --], sm);
				}
				return r + 1 - size;
			}
			sm = TT(data[r], sm);
		}while((r & -r) != r);
		return 0;
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, const segment_tree<T, F> &seg){
		out << "[";
		for(auto i = 0; i < seg.n; ++ i){
			out << seg.query(i);
			if(i != seg.n - 1) out << ", ";
		}
		return out << ']';
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		cartesian_tree c(a, greater<>());
		c.bfs();
		using T = array<long long, 3>;
		vector<T> init(n);
		for(auto i = 0; i < n; ++ i){
			init[i] = {a[i], max(a[i], 0), max(a[i], 0)};
		}
		auto TT = [&](T x, T y)->T{
			return {
				x[0] + y[0],
				max(x[1], x[0] + y[1]),
				max(x[2] + y[0], y[2])
			};
		};
		segment_tree seg(init, TT, T{});
		for(auto i = 0; i < n; ++ i){
			auto [l, r] = c.range[i];
			if(seg.query(l, i)[2] + seg.query(i + 1, r)[1] > 0){
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
	}
	return 0;
}

/*
-4 5 -1 -1 4 
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////