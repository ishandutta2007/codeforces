#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T>
struct fenwick_tree_max{
	int n;
	vector<T> data;
	fenwick_tree_max(){ }
	fenwick_tree_max(int n): fenwick_tree_max(vector<T>(n, numeric_limits<T>::min())){ }
	fenwick_tree_max(int n, T init): fenwick_tree_max(vector<T>(n, init)){ }
	fenwick_tree_max(const vector<T> &v): n((int)v.size()), data(v){
		for(auto i = 1; i <= n; ++ i) if(i + (i & -i) <= n) data[i + (i & -i) - 1] = max(data[i + (i & -i) - 1], data[i - 1]);
	}
	// O(log n)
	void update(int p, T x){
		assert(0 <= p && p < n);
		for(++ p; p <= n; p += p & -p) data[p - 1] = max(data[p - 1], x);
	}
	// O(log n)
	T query(int r) const{
		T s = numeric_limits<T>::min();
		for(; r > 0; r -= r & -r) s = max(s, data[r - 1]);
		return s;
	}
	// f(sum[0, r)) is T, T, ..., T, F, F, ..., F, returns max r with T
	// O(log n)
	int max_pref(auto f) const{
		int p = 0;
		T pref = numeric_limits<T>::min();
		for(auto i = __lg(n + 1); i >= 0; -- i) if(p + (1 << i) <= n && f(TT(pref, data[p + (1 << i) - 1]))){
			pref = TT(pref, data[p + (1 << i) - 1]);
			p += 1 << i;
		}
		return p;
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, const fenwick_tree_max<T> &fw){
		out << "[";
		for(auto i = 0; i < fw.n; ++ i){
			out << fw.query(i, i + 1);
			if(i != fw.n - 1) out << ", ";
		}
		return out << ']';
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, _mx, _t;
	auto __solve_tc = [&](auto __tc_num)->int{
		vector<int> b(n);
		copy_n(istream_iterator<int>(cin), n, b.begin());
		auto cmpr = b;
		ranges::sort(cmpr);
		cmpr.erase(unique(cmpr.begin(), cmpr.end()), cmpr.end());
		int mx = (int)cmpr.size();
		int t = min(_t, mx);
		for(auto &x: b){
			x = ranges::lower_bound(cmpr, x) - cmpr.begin();
		}
		fenwick_tree_max<int> fw(mx);
		for(auto rep = t; rep; -- rep){
			for(auto x: b){
				fw.update(x, max(fw.query(x) + 1, 1));
			}
		}
		cout << fw.query(mx) << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt >> n >> _mx >> _t;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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