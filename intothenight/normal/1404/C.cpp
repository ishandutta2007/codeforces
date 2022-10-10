#include <bits/stdc++.h>
using namespace std;

struct recursive_segment_tree{
	using L = int; // Lazy type
	using Q = array<int, 2>; // Query type // min_val, -pos
	L apply_lazy(const L &lazy, const L &x, array<int, 2> r, array<int, 2> rr){ // r is a subset of rr
		return lazy + x;
	} // update lazy node representing r with rr
	Q merge(const Q &lval, const Q &rval, int l, int m, int r){
		return min(lval, rval);
	} // merge two nodes representing the intervals [l, m) and [m, r)
	Q apply(const Q &val, const L &x, array<int, 2> r, array<int, 2> rr){ // r is a subset of rr
		return {val[0] + x, val[1]};
	} // apply to node representing r lazy node representing rr
	pair<L, Q> id{0, {numeric_limits<int>::max() / 2, 0}};
	Q init(int p){
		return id.second;
	}

	int n;
	vector<L> lazy;
	vector<Q> val;
	void push(int u, int l, int r){ // push the internal node u
		if(lazy[u] != id.first && u + 1 < n << 1){
			int m = l + (r - l >> 1), v = u + 1, w = u + (m - l << 1);
			val[v] = apply(val[v], lazy[u], {l, m}, {l, r});
			lazy[v] = apply_lazy(lazy[v], lazy[u], {l, m}, {l, r});
			val[w] = apply(val[w], lazy[u], {m, r}, {l, r});
			lazy[w] = apply_lazy(lazy[w], lazy[u], {m, r}, {l, r});
			lazy[u] = id.first;
		}
	}
	void refresh(int u, int l, int r){
		if(u + 1 < n << 1){
			int m = l + (r - l >> 1), v = u + 1, w = u + (m - l << 1);
			val[u] = merge(val[v], val[w], l, m, r);
		}
		if(lazy[u] != id.first) val[u] = apply(val[u], lazy[u], {l, r}, {l, r});
	}
	template<typename IT>
	recursive_segment_tree(IT begin, IT end): n(end - begin), lazy(n << 1, id.first), val(n << 1, id.second){
		build(begin, end, 0, 0, n);
	}
	recursive_segment_tree(int n): n(n), lazy(n << 1, id.first), val(n << 1, id.second){
		build(0, 0, n);
	}
	template<typename IT>
	void build(IT begin, IT end, int u, int l, int r){
		if(l + 1 == r) val[u] = *begin;
		else{
			int m = l + (r - l >> 1), v = u + 1, w = u + (m - l << 1);
			IT inter = begin + (end - begin >> 1);
			build(begin, inter, v, l, m), build(inter, end, w, m, r);
			val[u] = merge(val[v], val[w], l, m, r);
		}
	}
	void build(int u, int l, int r){
		if(l + 1 == r) val[u] = init(l);
		else{
			int m = l + (r - l >> 1), v = u + 1, w = u + (m - l << 1);
			build(v, l, m), build(w, m, r);
			val[u] = merge(val[v], val[w], l, m, r);
		}
	}
	template<bool First = true>
	void update(int ql, int qr, L x, int u = 0, int l = 0, int r = numeric_limits<int>::max()){
		if(First) r = n;
		if(qr <= l || r <= ql) return;
		if(ql <= l && r <= qr) val[u] = apply(val[u], x, {l, r}, {ql, qr}), lazy[u] = apply_lazy(lazy[u], x, {l, r}, {ql, qr});
		else{
			push(u, l, r);
			int m = l + (r - l >> 1), v = u + 1, w = u + (m - l << 1);
			update<false>(ql, qr, x, v, l, m), update<false>(ql, qr, x, w, m, r);
			refresh(u, l, r);
		}
	} // Apply x to values at [ql, qr)
	template<bool First = true>
	Q query(int ql, int qr, int u = 0, int l = 0, int r = numeric_limits<int>::max()){
		if(First) r = n;
		if(qr <= l || r <= ql) return id.second;
		if(ql <= l && r <= qr) return val[u];
		push(u, l, r);
		int m = l + (r - l >> 1), v = u + 1, w = u + (m - l << 1);
		return merge(query<false>(ql, qr, v, l, m), query<false>(ql, qr, w, m, r), max(ql, l), clamp(m, ql, qr), min(qr, r));
	} // Get the query result for [ql, qr)
};

template<typename T, typename BO, typename IO>
struct fenwick_tree{
	int n;
	BO bin_op;
	IO inv_op;
	T id;
	vector<T> val;
	template<typename IT>
	fenwick_tree(IT begin, IT end, BO bin_op, IO inv_op, T id): n(end - begin), bin_op(bin_op), inv_op(inv_op), id(id), val(n + 1, id){
		for(int i = 0; i < n; ++ i) update(i, *(begin ++));
	}
	fenwick_tree(int n, BO bin_op, IO inv_op, T id): n(n), bin_op(bin_op), inv_op(inv_op), id(id), val(n + 1, id){ }
	fenwick_tree(){ }
	template<bool increment = true>
	void update(int p, T x){
		if(!increment) x = inv_op(x, query(p, p + 1));
		for(++ p; p <= n; p += p & -p) val[p] = bin_op(val[p], x);
	}
	T sum(int p){ // returns the sum [0, p]
		T res = id;
		for(++ p; p > 0; p -= p & -p) res = bin_op(res, val[p]);
		return res;
	}
	T query(int l, int r){ // returns the sum [l, r)
		return inv_op(sum(r - 1), sum(l - 1));
	}
};

template<int TYPE, typename T, typename Compare = less<>>
struct offline_less_than_k_query{ // TYPE: {0: distinct value query, 1: less-than-k query}
	int n;
	Compare cmp;
	vector<T> cmpr;
	vector<array<int, 2>> event;
	vector<array<int, 4>> queries;
	template<typename IT>
	offline_less_than_k_query(IT begin, IT end, Compare cmp = less<>()): n(end - begin), event(n), cmp(cmp){
		if(!TYPE){
			map<T, int, Compare> q(cmp);
			for(int i = 0; begin != end; ++ begin, ++ i){
				event[i] = {(q.count(*begin) ? q[*begin] : -1), i};
				q[*begin] = i;
			}
		}
		else{
			cmpr = {begin, end};
			sort(cmpr.begin(), cmpr.end(), cmp), cmpr.erase(unique(cmpr.begin(), cmpr.end()), cmpr.end());
			for(int i = 0; begin != end; ++ begin, ++ i) event[i] = {std::lower_bound(cmpr.begin(), cmpr.end(), *begin, cmp) - cmpr.begin(), i};
		}
	}
	// For distinct value query
	void query(int i, int ql, int qr){
		assert(!TYPE), queries.push_back({ql, ql, qr, i});
	}
	// For less-than-k query
	int lower_bound(T k){
		return assert(TYPE), std::lower_bound(cmpr.begin(), cmpr.end(), k, cmp) - cmpr.begin();
	}
	int upper_bound(T k){
		return assert(TYPE), std::upper_bound(cmpr.begin(), cmpr.end(), k, cmp) - cmpr.begin();
	}
	void query(int i, int ql, int qr, int k){ // k must be the result of lower_bound or upper_bound
		assert(TYPE), queries.push_back({k, ql, qr, i});
	}
	template<typename Action>
	void solve(Action ans){ // ans(index, answer)
		sort(queries.begin(), queries.end()), sort(event.begin(), event.end(), greater<>());
		fenwick_tree tr(n, plus<>(), minus<>(), 0);
		for(auto &[k, ql, qr, i]: queries){
			while(!event.empty() && event.back()[0] < k) tr.update(event.back()[1], 1), event.pop_back();
			ans(i, tr.query(ql, qr));
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qq;
	cin >> n >> qq;
	vector<int> a(n);
	vector<array<int, 2>> temp(n);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		a[i] = i + 1 - x;
		if(a[i] < 0){
			a[i] = numeric_limits<int>::max() / 2;
		}
		temp[i] = {a[i], -i};
	}
	recursive_segment_tree tr(temp.begin(), temp.end());
	vector<int> req(n, -1);
	for(auto i = n - 1; i >= 0; -- i){
		if(!a[i]){
			req[i] = i;
			tr.update(i, i + 1, numeric_limits<int>::max() / 2);
			tr.update(i + 1, n, -1);
			while(!tr.query(i + 1, n)[0]){
				int j = -tr.query(i + 1, n)[1];
				req[j] = i;
				tr.update(j, j + 1, numeric_limits<int>::max() / 2);
				tr.update(j + 1, n, -1);
			}
		}
	}
	offline_less_than_k_query<1, int> ltk(req.begin(), req.end());
	vector<int> res(qq);
	for(auto i = 0; i < qq; ++ i){
		int l, r;
		cin >> l >> r, r = n - r;
		ltk.query(i, l, r, ltk.lower_bound(l));
		res[i] = r - l;
	}
	auto F = [&](int i, int ans){
		res[i] -= ans;
	};
	ltk.solve(F);
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