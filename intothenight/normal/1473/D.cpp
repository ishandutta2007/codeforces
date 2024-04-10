#include <bits/stdc++.h>
using namespace std;

template<class T>
struct sparse_table{
	int n;
	vector<vector<T>> data;
	function<T(T, T)> TT; // monoid operation (must be idempotent)
	T T_id; // monoid identity
	sparse_table(){ }
	sparse_table(const vector<T> &a, function<T(T, T)> TT, T T_id): n((int)a.size()), TT(TT), T_id(T_id), data({a}){ // O(n log n)
		for(auto p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			data.emplace_back(n - (p << 1) + 1);
			for(auto j = 0; j < (int)data[i].size(); ++ j) data[i][j] = TT(data[i - 1][j], data[i - 1][j + p]);
		}
	}
	T query(int l, int r){ // O(1)
		if(l >= r) return T_id;
		int d = __lg(r - l);
		return TT(data[d][l], data[d][r - (1 << d)]);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, qn;
		string s;
		cin >> n >> qn >> s;
		vector<int> sum(n + 1);
		for(auto i = 0; i < n; ++ i){
			sum[i + 1] = sum[i] + (s[i] == '+' ? 1 : -1);
		}
		sparse_table<int> maxq(sum, [&](int x, int y){ return max(x, y); }, 0);
		sparse_table<int> minq(sum, [&](int x, int y){ return min(x, y); }, 0);
		for(auto qi = 0; qi < qn; ++ qi){
			int l, r;
			cin >> l >> r, -- l;
			cout << max(maxq.query(0, l + 1), maxq.query(r, n + 1) - (sum[r] - sum[l])) - min(minq.query(0, l + 1), minq.query(r, n + 1) - (sum[r] - sum[l])) + 1 << "\n";
		}
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