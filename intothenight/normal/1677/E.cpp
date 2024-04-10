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

template<class T, class U, class F1, class F2, class F3, class F4>
struct lazy_segment_tree{
	int n, size, log;
	vector<T> data;
	vector<U> updates;
	F1 TT; // monoid operation (always adjacent)
	T T_id; // monoid identity
	F2 UU; // semigroup operation (superset, subset)
	F3 U_init; // semigroup default element for the interval [l, r)
	F4 UT; // action of U on T (superset, subset)
	lazy_segment_tree(int n, F1 TT, T T_id, F2 UU, F3 U_init, F4 UT, U _type_deducer): lazy_segment_tree(vector<T>(n, T_id), TT, T_id, UU, U_init, UT, _type_deducer){ }
	lazy_segment_tree(int n, T init, F1 TT, T T_id, F2 UU, F3 U_init, F4 UT, U _type_deducer): lazy_segment_tree(vector<T>(n, init), TT, T_id, UU, U_init, UT, _type_deducer){ }
	lazy_segment_tree(const vector<T> &a, F1 TT, T T_id, F2 UU, F3 U_init, F4 UT, U): n((int)a.size()), TT(TT), T_id(T_id), UU(UU), U_init(U_init), UT(UT){ // O(n)
		log = __lg(max(n - 1, 1)) + 1, size = 1 << log;
		data = vector<T>(size << 1, T_id), updates = vector<U>(size);
		copy(a.begin(), a.end(), data.begin() + size);
		for(auto i = 1; i < size; ++ i){
			int h = log - __lg(i);
			updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
		}
		for(auto i = size - 1; i >= 1; -- i) refresh(i);
	}
	void refresh(int i){
		data[i] = TT(data[i << 1], data[i << 1 | 1]);
	}
	void apply(int i, U f){
		data[i] = UT(f, data[i]);
		if(i < size) updates[i] = UU(f, updates[i]);
	}
	void push(int i){
		apply(i << 1, updates[i]), apply(i << 1 | 1, updates[i]);
		int h = log - __lg(i);
		updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
	}
	// O(log n)
	T query(int p){
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		return data[p];
	}
	// O(log n)
	T query(int l, int r){
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return T_id;
		l += size, r += size;
		for(auto i = log; i >= 1; -- i) {
			if(l >> i << i != l) push(l >> i);
			if(r >> i << i != r) push(r - 1 >> i);
		}
		T res_left = T_id, res_right = T_id;
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) res_left = TT(res_left, data[l ++]);
			if(r & 1) res_right = TT(data[-- r], res_right);
		}
		return TT(res_left, res_right);
	}
	// O(1)
	T query_all(){
		return data[1];
	}
	// O(log n)
	void set(int p, T x){
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		data[p] = x;
		for(auto i = 1; i <= log; ++ i) refresh(p >> i);
	}
	// O(log n)
	void update(int p, U f){
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		data[p] = UT(f, data[p]);
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
	// pred(sum[l, r)) is T, T, ..., T, F, F, ..., F
	// Returns max r with T
	// O(log n)
	int max_pref(int l, auto pred){
		assert(0 <= l && l <= n && pred(T_id));
		if(l == n) return n;
		l += size;
		for(auto i = log; i >= 1; -- i) push(l >> i);
		T sum = T_id;
		do{
			while(~l & 1) l >>= 1;
			if(!pred(TT(sum, data[l]))){
				while(l < size){
					push(l);
					l = l << 1;
					if(pred(TT(sum, data[l]))) sum = TT(sum, data[l ++]);
				}
				return l - size;
			}
			sum = TT(sum, data[l]);
			++ l;
		}while((l & -l) != l);
		return n;
	}
	// pred(sum[l, r)) is F, F, ..., F, T, T, ..., T
	// Returns min l with T
	// O(log n)
	int min_suff(int r, auto pred){
		assert(0 <= r && r <= n && pred(T_id));
		if(r == 0) return 0;
		r += size;
		for(auto i = log; i >= 1; -- i) push(r - 1 >> i);
		T sum = T_id;
		do{
			-- r;
			while(r > 1 && r & 1) r >>= 1;
			if(!pred(TT(data[r], sum))){
				while(r < size){
					push(r);
					r = r << 1 | 1;
					if(pred(TT(data[r], sum))) sum = TT(data[r --], sum);
				}
				return r + 1 - size;
			}
			sum = TT(data[r], sum);
		}while((r & -r) != r);
		return 0;
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, lazy_segment_tree<T, U, F1, F2, F3, F4> seg){
		out << "[";
		for(auto i = 0; i < seg.n; ++ i){
			out << seg.query(i);
			if(i != seg.n - 1) out << ", ";
		}
		return out << ']';
	}
};

// For each 0 <= i < n, add weight[i] to all squares within rectangle[i]
// For each 0 <= qi < qn, res[qi] = sum of values of squares within query[qi]
// Rectangles are given in form [xlow, xhigh] x [ylow, yhigh] where 0 <= xlow <= xhigh <= sigma_x and 0 <= ylow <= yhigh
// Requires lazy_segment_tree
// O((n + sigma_x + qn) * log(n + sigma_x + qn))
template<class B, class T>
vector<T> rectangle_add_rectangle_query_solver_offline(const vector<tuple<int, int, B, B>> &rectangle, const vector<T> &weight, const vector<T> &width, int sigma_x, const vector<tuple<int, int, B, B>> &query){
	int n = (int)rectangle.size(), qn = (int)query.size();
	assert((int)weight.size() == n);
	assert((int)width.size() == sigma_x);
	vector<tuple<B, int, int, int, T, T>> event;
	for(auto i = 0; i < n; ++ i){
		auto [xl, xr, yl, yr] = rectangle[i];
		assert(0 <= xl && xl <= xr && xr <= sigma_x);
		assert(0 <= yl && yl <= yr);
		event.push_back({yl, -1, xl, xr, weight[i] * -yl, weight[i]});
		event.push_back({yr, -1, xl, xr, weight[i] * yr, -weight[i]});
	}
	for(auto qi = 0; qi < qn; ++ qi){
		auto [xl, xr, yl, yr] = query[qi];
		assert(0 <= xl && xl <= xr && xr <= sigma_x);
		assert(0 <= yl && yl <= yr);
		event.push_back({yl, qi << 1, xl, xr, 0, 0});
		event.push_back({yr, qi << 1 | 1, xl, xr, 0, 0});
	}
	sort(event.begin(), event.end());
	vector<array<T, 3>> init(sigma_x);
	for(auto x = 0; x < sigma_x; ++ x) init[x][2] = width[x];
	auto TT = [&](const array<T, 3> &x, const array<T, 3> &y)->array<T, 3>{
		return {x[0] + y[0], x[1] + y[1], x[2] + y[2]};
	};
	auto UU = [&](const array<T, 2> &f, const array<T, 2> &g)->array<T, 2>{
		return {f[0] + g[0], f[1] + g[1]};
	};
	auto U_init = [&](int, int)->array<T, 2>{
		return {};
	};
	auto UT = [&](const array<T, 2> &f, const array<T, 3> &x)->array<T, 3>{
		return {x[0] + f[0] * x[2], x[1] + f[1] * x[2], x[2]};
	};
	lazy_segment_tree seg(init, TT, array<T, 3>{}, UU, U_init, UT, array<T, 2>{});
	vector<T> res(qn);
	for(auto [y, t, xl, xr, c0, c1]: event){
		if(!~t) seg.update(xl, xr, {c0, c1});
		else{
			auto q = seg.query(xl, xr);
			res[t >> 1] += (t & 1 ? 1 : -1) * (q[0] + q[1] * y);
		}
	}
	return res;
}
vector<long long> rectangle_add_rectangle_query_solver_offline(const vector<tuple<int, int, int, int>> &rectangle, int sigma_x, const vector<tuple<int, int, int, int>> &query){
	return rectangle_add_rectangle_query_solver_offline<int, long long>(rectangle, vector<long long>((int)rectangle.size(), 1), vector<long long>(sigma_x, 1), sigma_x, query);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<int> a(n), pos(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
		pos[a[i]] = i;
	}
	vector<tuple<int, int, int, int>> query(qn);
	for(auto &[xl, xr, yl, yr]: query){
		int l, r;
		cin >> l >> r, -- l;
		tie(xl, xr, yl, yr) = tuple{l, r + 1, l, r + 1};
	}
	cartesian_tree ct(a, greater<>());
	ct.bfs();
	vector<vector<array<int, 2>>> req(n);
	for(auto x = 1; x <= n; ++ x){
		for(auto y = 1; x * y <= n; ++ y) if(x != y){
			int i = pos[x * y - 1], j = pos[x - 1], k = pos[y - 1];
			int l = min({i, j, k}), r = max({i, j, k}) + 1;
			auto [ll, rr] = ct.range[i];
			if(ll <= l && r <= rr){
				req[i].push_back({l, r});
			}
		}
	}
	vector<tuple<int, int, int, int>> rectangle;
	for(auto i = 0; i < n; ++ i){
		ranges::sort(req[i]);
		vector<array<int, 2>> temp;
		for(auto [l, r]: req[i]){
			while(!temp.empty() && r <= temp.back()[1]){
				temp.pop_back();
			}
			if(temp.empty() || temp.back()[0] < l){
				temp.push_back({l, r});
			}
		}
		auto [ll, rr] = ct.range[i];
		for(auto j = 0; j < (int)temp.size(); ++ j){
			auto [l, r] = temp[j];
			rectangle.push_back({ll, l + 1, r, j + 1 < (int)temp.size() ? temp[j + 1][1] : rr + 1});
		}
	}
	for(auto x: rectangle_add_rectangle_query_solver_offline(rectangle, n + 1, query)){
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