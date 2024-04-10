#include "bits/stdc++.h"
using namespace std;

template<typename P>
int custom_binary_search(int low, int high, P pred, const bool is_left = true){
	while(high - low > 1){
		auto mid = low + (high - low >> 1);
		(pred(mid) == is_left ? low : high) = mid;
	}
	return is_left ? low : high;
}

template<typename T, typename BO>
struct sparse_table{
	int n;
	BO bin_op;
	T id;
	vector<vector<T>> val;
	template<typename IT>
	sparse_table(IT begin, IT end, BO bin_op, T id): n(distance(begin, end)), bin_op(bin_op), id(id), val(1, {begin, end}){
		for(int p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			val.emplace_back(n - (p << 1) + 1);
			for(int j = 0; j < int(val[i].size()); ++ j) val[i][j] = bin_op(val[i - 1][j], val[i - 1][j + p]);
		}
	}
	sparse_table(){ }
	T query(int l, int r){
		if(l >= r) return id;
		int d = __lg(r - l);
		return bin_op(val[d][l], val[d][r - (1 << d)]);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n, n += 2;
	vector<array<int, 2>> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i][0], a[i][1] = a[i][0];
	}
	sparse_table st(a.begin(), a.end(), [&](auto &x, auto &y){ return array<int, 2>{min(x[0], y[0]), max(x[1], y[1])}; }, array<int, 2>{numeric_limits<int>::max() / 2, -1});
	auto pred = [&](int x){
		// dp[i]: i, i+1 distinct courier
		// i->j implies 1(i), 2(i+1), 2, 2, ..., 2(j), 1(j+1)
		// a[i]-x <= min{k: i+1 ~ j}( a[j] ) <= max{k: i+1 ~ j}( a[j] ) <= a[i]+x
		// and abs(a[j] - a[j+1]) <= x
		for(auto i = 0, i_r = 1; i < i_r; ++ i){ // dp[t] = 1 for all t in [i, i_r)
			if(abs(a[i][0] - a[i + 1][0]) <= x){
				auto [low, high] = st.query(i + 1, n);
				if(a[i][0] - x <= low && high <= a[i][0] + x){
					return true;
				}
				auto pred = [&](int i_r){
					auto [low, high] = st.query(i + 1, i_r);
					return a[i][0] - x <= low && high <= a[i][0] + x;
				};
				i_r = max(i_r, custom_binary_search(i + 2, n, pred));
			}
		}
		return false;
	};
	cout << custom_binary_search(abs(a[0][0] - a[1][0]) - 1, 1e9, pred, false) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////