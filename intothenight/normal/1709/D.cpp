#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

// Specialization of sparse_table
// Range min query by default. Set cmp = greater for max query
template<class T, class Compare = less<>>
struct range_minmax_query_solver{
	int n;
	vector<vector<T>> data;
	Compare cmp;
	T T_id;
	range_minmax_query_solver(){ }
	// O(n log n)
	range_minmax_query_solver(const vector<T> &a, Compare cmp = less<>(), T T_id = numeric_limits<T>::max()): n((int)a.size()), cmp(cmp), T_id(T_id), data({a}){ // O(n log n)
		for(auto p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			data.emplace_back(n - (p << 1) + 1);
			for(auto j = 0; j < (int)data[i].size(); ++ j) data[i][j] = cmp(data[i - 1][j], data[i - 1][j + p]) ? data[i - 1][j] : data[i - 1][j + p];
		}
	}
	// O(1)
	T query(int l, int r) const{
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return T_id;
		int d = __lg(r - l);
		return cmp(data[d][l], data[d][r - (1 << d)]) ? data[d][l] : data[d][r - (1 << d)];
	}
};



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	copy_n(istream_iterator<int>(cin), m, a.begin());
	range_minmax_query_solver rmaxq(a, greater<>(), numeric_limits<int>::min());
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int x1, y1, x2, y2, k;
		cin >> x1 >> y1 >> x2 >> y2 >> k, -- x1, -- y1, -- x2, -- y2;
		if(x1 % k != x2 % k || y1 % k != y2 % k){
			cout << "NO\n";
			continue;
		}
		if(y1 > y2){
			swap(x1, x2);
			swap(y1, y2);
		}
		int h = x1 + (n - 1 - x1) / k * k;
		rmaxq.query(y1, y2 + 1) <= h ? cout << "YES\n" : cout << "NO\n";
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