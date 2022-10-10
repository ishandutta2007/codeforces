#include <bits/stdc++.h>
using namespace std;

template<class T>
struct persistent_segment_tree{
	int n;
	vector<int> left, right;
	vector<T> data;
	function<T(T, T)> TT; // monoid operation (always adjacent)
	T T_id; // monoid identity
	persistent_segment_tree(int n, function<T(T, T)> TT, T T_id): persistent_segment_tree(vector<T>(n, T_id), TT, T_id){ }
	persistent_segment_tree(int n, T init, function<T(T, T)> TT, T T_id): persistent_segment_tree(vector<T>(n, init), TT, T_id){ }
	persistent_segment_tree(const vector<T> &a, function<T(T, T)> TT, T T_id): n((int)a.size()), TT(TT), T_id(T_id){
		build(a);
	}
	int last_state(){
		return (int)data.size() - 1;
	}
	int new_state(int l, int r, T x){
		left.push_back(l), right.push_back(r), data.push_back(x);
		return last_state();
	}
	int build(const vector<T> &a){
		function<int(int, int)> recurse = [&](int l, int r){
			if(r - l == 1) return new_state(-1, -1, a[l]);
			int m = l + (r - l >> 1);
			int v = recurse(l, m), w = recurse(m, r);
			return new_state(v, w, TT(data[v], data[w]));
		};
		return recurse(0, (int)a.size());
	}
	int set(int u, int p, T x){ // set v[p] = x at state u, O(log n)
		function<int(int, int, int)> recurse = [&](int u, int l, int r){
			if(r - l == 1) return new_state(-1, -1, x);
			int m = l + (r - l >> 1), v = left[u], w = right[u];
			if(p < m) v = recurse(v, l, m);
			else w = recurse(w, m, r);
			return new_state(v, w, TT(data[v], data[w]));
		};
		return recurse(u, 0, n);
	}
	T query(int u, int ql, int qr){ // find sum{ql<=i<qr}(v[i]) at state u, O(log n)
		function<T(int, int, int)> recurse = [&](int u, int l, int r){
			if(qr <= l || r <= ql) return T_id;
			if(ql <= l && r <= qr) return data[u];
			int m = l + (r - l >> 1);
			return TT(recurse(left[u], l, m), recurse(right[u], m, r));
		};
		return recurse(u, 0, n);
	}
};

// Requires persistent_segment_tree
template<int TYPE, class T, class Compare = less<>>
struct relative_query_solver_online{ // TYPE: {0: distinct value query, 1: less-than-k query}
	int n;
	Compare cmp;
	vector<int> pos;
	persistent_segment_tree<int> ds;
	vector<T> cmpr;
	relative_query_solver_online(): ds(1, plus<>(), 0){ }
	relative_query_solver_online(const vector<T> &a, Compare cmp = less<>()): n((int)a.size()), pos(n + 1), ds(n, plus<>(), 0), cmp(cmp){
		vector<array<int, 2>> event(n);
		if(!TYPE){
			map<T, int, Compare> q(cmp);
			for(auto i = 0; i < n; ++ i){
				event[i] = {(q.count(a[i]) ? q[a[i]] : -1), i};
				q[a[i]] = i;
			}
		}
		else{
			cmpr = a;
			sort(cmpr.begin(), cmpr.end(), cmp), cmpr.erase(unique(cmpr.begin(), cmpr.end()), cmpr.end());
			for(auto i = 0; i < n; ++ i) event[i] = {std::lower_bound(cmpr.begin(), cmpr.end(), a[i], cmp) - cmpr.begin(), i};
		}
		sort(event.begin(), event.end(), greater<>());
		for(auto i = 0; i <= n; ++ i){
			while(!event.empty() && event.back()[0] < i){
				ds.set(ds.last_state(), event.back()[1], 1);
				event.pop_back();
			}
			pos[i] = ds.last_state();
		}
	}
	// Rescalling function for less-than-k query
	int lower_bound(T k){ // exclusive
		return std::lower_bound(cmpr.begin(), cmpr.end(), k, cmp) - cmpr.begin();
	}
	int upper_bound(T k){ // inclusive
		return std::upper_bound(cmpr.begin(), cmpr.end(), k, cmp) - cmpr.begin();
	}
	// For distinct value query
	int count_distinct(int ql, int qr){
		return assert(!TYPE), ds.query(pos[ql], ql, qr);
	}
	// For comparison query
	int count_less(int ql, int qr, T k){
		return assert(TYPE), ds.query(pos[lower_bound(k)], ql, qr);
	}
	int count_equal_or_less(int ql, int qr, T k){
		return assert(TYPE), ds.query(pos[upper_bound(k)], ql, qr);
	}
	int count_greater(int ql, int qr, T k){
		return assert(TYPE), qr - ql - ds.query(pos[upper_bound(k)], ql, qr);
	}
	int count_equal_or_greater(int ql, int qr, T k){
		return assert(TYPE), qr - ql - ds.query(pos[lower_bound(k)], ql, qr); 
	}
	int count_within(int ql, int qr, T kl, T kr){ // Count # of elements within [kl, kr)
		return assert(TYPE), ds.query(pos[lower_bound(kr)], ql, qr) - ds.query(pos[lower_bound(kl)], ql, qr);
	}
	// TODO: Finish binary search with petro camp problem
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> profit(n);
	for(auto u = 0; u < n; ++ u){
		cin >> profit[u];
	}
	string s;
	cin >> s;
	vector<vector<int>> adj(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<array<int, 26>> next(n + 1);
	for(auto x = 0; x <= n; ++ x){
		next[x].fill(-1);
	}
	int cur = 1;
	vector<int> label(n), pos(n), end(n), order;
	function<void(int, int)> dfs = [&](int u, int p){
		pos[u] = (int)order.size();
		order.push_back(label[u]);
		for(auto v: adj[u]){
			if(v != p){
				label[v] = ~next[label[u]][s[v] - 'a'] ? next[label[u]][s[v] - 'a'] : next[label[u]][s[v] - 'a'] = cur ++;
				dfs(v, u);
			}
		}
		end[u] = (int)order.size();
	};
	dfs(0, -1);
	relative_query_solver_online<0, int> rqs(order);
	array<int, 2> res{numeric_limits<int>::min(), -1};
	for(auto u = 0; u < n; ++ u){
		int x = profit[u] + rqs.count_distinct(pos[u], end[u]);
		if(res[0] == x){
			++ res[1];
		}
		else if(res[0] < x){
			res = {x, 1};
		}
	}
	cout << res[0] << "\n" << res[1] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////