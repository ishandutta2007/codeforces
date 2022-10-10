#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename BO>
struct sparse_table{
	int n;
	BO bin_op;
	T id;
	vector<vector<T>> val;
	template<typename IT>
	sparse_table(IT begin, IT end, BO bin_op, T id): n(distance(begin, end)), bin_op(bin_op), id(id), val(__lg(n) + 1, vector<T>(begin, end)){
		for(int i = 0; i < __lg(n); ++ i) for(int j = 0; j < n; ++ j){
			val[i + 1][j] = bin_op(val[i][j], val[i][min(n - 1, j + (1 << i))]);
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
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	vector<int> t(n);
	iota(t.begin(), t.end(), 0);
	auto bo = [&](int i, int j){
		return a[i] >= a[j] ? i : j;
	};
	sparse_table st(t.begin(), t.end(), bo, -1);
	int j = n;
	vector<int> h(n);
	while(j){
		int i = st.query(0, j);
		for(auto k = i; k < j; ++ k){
			h[k] = a[i] + 1;
		}
		j = i;
	}
	for(auto i = n - 2; i >= 0; -- i){
		if(h[i] < h[i + 1] - 1){
			h[i] = h[i + 1] - 1;
		}
	}
	long long res = 0;
	for(auto i = 0; i < n; ++ i){
		res += h[i] - a[i] - 1;
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