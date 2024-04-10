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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int qn;
	cin >> qn;
	vector<pair<char, long long>> q(qn);
	vector<long long> a;
	for(auto qi = 0; qi < qn; ++ qi){
		cin >> q[qi].first >> q[qi].second;
		a.push_back(q[qi].second);
	}
	ranges::sort(a);
	a.erase(unique(a.begin(), a.end()), a.end());
	int n = (int)a.size();
	vector<vector<array<int, 2>>> adj(n), radj(n);
	for(auto i = 0; i < n; ++ i){
		for(auto q = 1; ; ++ q){
			auto it = ranges::lower_bound(a, a[i] * q);
			if(it == a.end() || *it != a[i] * q){
				break;
			}
			adj[i].push_back({it - a.begin(), q});
			radj[it - a.begin()].push_back({i, q});
		}
	}
	vector<fenwick_tree_sum<int>> fw(n);
	for(auto i = 0; i < n; ++ i){
		fw[i] = fenwick_tree_sum<int>((int)adj[i].size() + 1, 1);
		fw[i].update(0, -1);
	}
	for(auto [type, _x]: q){
		int i = ranges::lower_bound(a, _x) - a.begin();
		if(type == '+'){
			for(auto [j, q]: radj[i]){
				fw[j].update(q, -1);
			}
		}
		else if(type == '-'){
			for(auto [j, q]: radj[i]){
				fw[j].update(q, 1);
			}
		}
		else{
			int q = fw[i].max_pref([&](int sum){
				return sum == 0;
			});
			cout << q * a[i] << "\n";
		}
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