#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename BO>
struct sparse_table{
	int N;
	BO bin_op;
	const T id;
	vector<vector<T>> val;
	vector<int> bit;
	template<typename IT>
	sparse_table(IT begin, IT end, BO bin_op, T id): N(distance(begin, end)), bin_op(bin_op), id(id), val(__lg(N) + 1, vector<T>(begin, end)), bit(N + 1){
		for(int i = 1; i <= N; ++ i) bit[i] = __lg(i);
		for(int i = 0; i < __lg(N); ++ i) for(int j = 0; j < N; ++ j){
			val[i + 1][j] = bin_op(val[i][j], val[i][min(N - 1, j + (1 << i))]);
		}
	}
	sparse_table(){ }
	T query(int l, int r){
		if(l >= r) return id;
		int d = bit[r - l];
		return bin_op(val[d][l], val[d][r - (1 << d)]);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> h(n);
	copy_n(istream_iterator<int>(cin), n, h.begin());
	vector<int> right(n), left(n);
	for(int i = 0; i < n; ++ i){
		right[i] = h[i] + i;
		left[i] = h[i] - i;
	}
	sparse_table rst(right.begin(), right.end(), [&](int x, int y){ return min(x, y); }, numeric_limits<int>::max() / 2);
	sparse_table lst(left.begin(), left.end(), [&](int x, int y){ return min(x, y); }, numeric_limits<int>::max() / 2);
	int res = 0;
	for(int i = 0; i < n; ++ i){
		ctmax(res, min({i + 1, n - i, lst.query(0, i) + i, rst.query(i, n) - i}));
	}
	cout << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////