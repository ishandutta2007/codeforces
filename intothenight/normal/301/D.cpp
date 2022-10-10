#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T>
struct fenwick_tree{
	int n;
	vector<T> data;
	fenwick_tree(){ }
	// O(n)
	fenwick_tree(int n): n(n), data(n){ }
	// O(n)
	fenwick_tree(int n, T init): fenwick_tree(vector<T>(n, init)){ }
	// O(n)
	fenwick_tree(const vector<T> &v): n((int)v.size()), data(v){
		for(auto i = 1; i <= n; ++ i) if(i + (i & -i) <= n) data[i + (i & -i) - 1] += data[i - 1];
	}
	fenwick_tree(const fenwick_tree &otr): n(otr.n), data(otr.data){
	}
	// O(log n)
	void update(int p, T x){
		assert(0 <= p && p < n);
		for(++ p; p <= n; p += p & -p) data[p - 1] += x;
	}
	// O(log n)
	T query(int r) const{
		T s{};
		for(; r > 0; r -= r & -r) s += data[r - 1];
		return s;
	}
	// O(log n)
	T query(int l, int r) const{
		assert(0 <= l && l <= r && r <= n);
		return query(r) - query(l);
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
	friend output_stream &operator<<(output_stream &out, const fenwick_tree<T> &fw){
		out << "[";
		for(auto i = 0; i < fw.n; ++ i){
			out << fw.query(i, i + 1);
			if(i != fw.n - 1) out << ", ";
		}
		return out << ']';
	}
};

// Requires fenwick_tree
template<class T>
struct less_than_k_query_solver_offline{
	int n;
	vector<tuple<int, int, T>> event;
	vector<array<int, 4>> queries;
	less_than_k_query_solver_offline(const vector<int> &a, int sigma): less_than_k_query_solver_offline(a, vector<T>(sigma, 1)){ }
	less_than_k_query_solver_offline(const vector<int> &a, const vector<T> &w): n((int)a.size()), event(n){
		for(auto &x: a) assert(0 <= x && x < (int)w.size());
		for(auto i = 0; i < n; ++ i) event[i] = {a[i], i, w[a[i]]};
	}
	void query(int qi, int ql, int qr, int k){
		queries.push_back({k, ql, qr, qi});
	}
	// f(query id, answer)
	// O((n + q) * (log(n) + log(q)))
	void solve(auto f){
		sort(queries.begin(), queries.end());
		sort(event.rbegin(), event.rend());
		fenwick_tree<T> tr(n);
		for(auto &q: queries){
			while(!event.empty() && get<0>(event.back()) < q[0]){
				tr.update(get<1>(event.back()), get<2>(event.back()));
				event.pop_back();
			}
			f(q[3], tr.query(q[1], q[2]));
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<int> pos(n);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		pos[x - 1] = i;
	}
	vector<array<int, 2>> temp;
	for(auto x = 1; x <= n; ++ x){
		for(auto y = x; y <= n; y += x){
			temp.push_back({min(pos[x - 1], pos[y - 1]), max(pos[x - 1], pos[y - 1])});
		}
	}
	ranges::sort(temp);
	vector<int> ax((int)temp.size()), ay((int)temp.size());
	ranges::copy(temp | ranges::views::keys, ax.begin());
	ranges::copy(temp | ranges::views::values, ay.begin());
	less_than_k_query_solver_offline<int> rqs(ay, n);
	for(auto qi = 0; qi < qn; ++ qi){
		int l, r;
		cin >> l >> r, -- l;
		rqs.query(qi, ranges::lower_bound(ax, l) - ax.begin(), ranges::lower_bound(ax, r) - ax.begin(), r);
	}
	vector<int> res(qn);
	rqs.solve([&](int qi, int x){ res[qi] = x; });
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