#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T>
struct fenwick_tree_sum{
	int n;
	vector<T> data;
	fenwick_tree_sum(){ }
	// O(n)
	fenwick_tree_sum(int n): n(n), data(n){ }
	// O(n)
	fenwick_tree_sum(int n, T init): fenwick_tree_sum(vector<T>(n, init)){ }
	// O(n)
	fenwick_tree_sum(const vector<T> &v): n((int)v.size()), data(v){
		for(auto i = 1; i <= n; ++ i) if(i + (i & -i) <= n) data[i + (i & -i) - 1] += data[i - 1];
	}
	fenwick_tree_sum(const fenwick_tree_sum &otr): n(otr.n), data(otr.data){
	}
	// O(log n)
	void update(int p, T x){
		assert(0 <= p && p < n);
		for(++ p; p <= n; p += p & -p) data[p - 1] += x;
	}
	// O(log n)
	T pref(int r) const{
		assert(0 <= r && r <= n);
		T s{};
		for(; r > 0; r -= r & -r) s += data[r - 1];
		return s;
	}
	// O(log n)
	T query(int l, int r) const{
		assert(l <= r);
		return pref(r) - pref(l);
	}
	// O(log n)
	T query(int p) const{
		return pref(p + 1) - pref(p);
	}
	// pred(sum[0, r)) is T, T, ..., T, F, F, ..., F
	// Returns max r with T
	// O(log n)
	int max_pref(auto pred) const{
		assert(pred({}));
		int p = 0;
		T sum{};
		for(auto pw = 1 << __lg(n + 1); pw; pw >>= 1) if(p + pw <= n && pred(sum + data[p + pw - 1])){
			sum += data[p + pw - 1];
			p += pw;
		}
		return p;
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, const fenwick_tree_sum<T> &fw){
		out << "[";
		for(auto i = 0; i < fw.n; ++ i){
			out << fw.query(i);
			if(i != fw.n - 1) out << ", ";
		}
		return out << ']';
	}
};

template<class T>
struct value_range_query_solver_offline{
	int n;
	vector<tuple<int, int, T>> event;
	vector<array<int, 4>> queries;
	value_range_query_solver_offline(const vector<int> &a): value_range_query_solver_offline(a, vector<T>(a.size(), 1)){ }
	value_range_query_solver_offline(const vector<int> &a, const vector<T> &w): n((int)a.size()), event(n){
		assert(n == (int)w.size());
		for(auto i = 0; i < n; ++ i) event[i] = {a[i], i, w[i]};
	}
	value_range_query_solver_offline &operator=(const value_range_query_solver_offline &vrq){
		n = vrq.n;
		event = vrq.event;
		queries = vrq.queries;
		return *this;
	}
	void query(int qi, int ql, int qr, int k){
		assert(0 <= ql && ql <= qr && qr <= n);
		queries.push_back({k, ql, qr, qi});
	}
	// init(n) Initialize DS over identity array A of length n
	// set(p, x): A[p] <- x, A[p] is always identity beforehand
	// query(l, r): return sum in A[l:r)
	// answer(qi, x): answer to query qi is sum of w[i] over all i with
	//  ql <= i < qr and a[i] < k
	// O(init() + n * (log(n) + update()) + q * (log(q) + query() + answer()))
	void solve_less(auto init, auto update, auto query, auto answer){
		sort(queries.begin(), queries.end());
		sort(event.begin(), event.end());
		init(n);
		auto i = 0;
		for(auto &q: queries){
			while(i < (int)event.size() && get<0>(event[i]) < q[0]){
				update(get<1>(event[i]), get<2>(event[i]));
				++ i;
			}
			answer(q[3], query(q[1], q[2]));
		}
	}
	// init(n) Initialize DS over identity array A of length n
	// update(p, x): A[p] <- x, A[p] is always identity beforehand
	// query(l, r): return sum in A[l:r)
	// answer(qi, x): answer to query qi is sum of w[i] over all i with
	//  ql <= i < qr and a[i] < k
	// O(init() + n * (log(n) + update()) + q * (log(q) + query() + answer()))
	void solve_equal_or_greater(auto init, auto update, auto query, auto answer){
		sort(queries.rbegin(), queries.rend());
		sort(event.rbegin(), event.rend());
		init(n);
		auto i = 0;
		for(auto &q: queries){
			while(i < (int)event.size() && q[0] <= get<0>(event[i])){
				update(get<1>(event[i]), get<2>(event[i]));
				++ i;
			}
			answer(q[3], query(q[1], q[2]));
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string s;
	int qn;
	cin >> s >> qn;
	int n = (int)s.size();
	vector<int> stack, match(n, n);
	for(auto i = n - 1; i >= 0; -- i){
		if(s[i] == ')'){
			stack.push_back(i);
		}
		else if(!stack.empty()){
			match[i] = stack.back();
			stack.pop_back();
		}
	}
	value_range_query_solver_offline<int> vrqs(match);
	for(auto qi = 0; qi < qn; ++ qi){
		int l, r;
		cin >> l >> r, -- l;
		vrqs.query(qi, l, r, r);
	}
	vector<int> res(qn, -1);
	fenwick_tree_sum<int> fw(n);
	vrqs.solve_less([&](int n){ fw = {n}; }, [&](int i, int x){ fw.update(i, x); }, [&](int l, int r){ return fw.query(l, r); }, [&](int qi, int x){ res[qi] = 2 * x; });
	ranges::copy(res, ostream_iterator<int>(cout, "\n"));
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////