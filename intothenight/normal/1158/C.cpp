#include <bits/stdc++.h>
using namespace std;

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
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> next(n);
		for(auto i = 0; i < n; ++ i){
			cin >> next[i];
			if(~next[i]){
				-- next[i];
			}
		}
		range_minmax_query_solver rmaxq(next, greater<>(), numeric_limits<int>::min());
		vector<int> cnt(n + 1);
		for(auto i = 0; i < n; ++ i){
			if(~next[i]){
				if(rmaxq.query(i + 1, next[i]) > next[i]){
					cout << "-1\n";
					return 0;
				}
				++ cnt[i + 1], -- cnt[next[i]];
			}
		}
		for(auto i = 1; i < n; ++ i){
			cnt[i] += cnt[i - 1];
		}
		vector<vector<int>> order(n + 1);
		for(auto i = 0; i < n; ++ i){
			order[cnt[i]].push_back(i);
		}
		vector<int> ord;
		for(auto x = n; x >= 0; -- x){
			for(auto i: order[x]){
				ord.push_back(i);
			}
		}
		vector<int> p(n);
		for(auto t = 0; t < n; ++ t){
			p[ord[t]] = t;
		}
		for(auto x: p){
			cout << x + 1 << " ";
		}
		cout << "\n";
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

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////