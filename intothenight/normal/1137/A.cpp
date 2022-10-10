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
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m)), row(n), col(m);
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			cin >> a[i][j];
			row[i].push_back(a[i][j]);
			col[j].push_back(a[i][j]);
		}
	}
	for(auto i = 0; i < n; ++ i){
		sort(row[i].begin(), row[i].end()), row[i].erase(unique(row[i].begin(), row[i].end()), row[i].end());
	}
	for(auto j = 0; j < m; ++ j){
		sort(col[j].begin(), col[j].end()), col[j].erase(unique(col[j].begin(), col[j].end()), col[j].end());
	}
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			auto rit = lower_bound(row[i].begin(), row[i].end(), a[i][j]);
			auto cit = lower_bound(col[j].begin(), col[j].end(), a[i][j]);
			cout << max(rit - row[i].begin(), cit - col[j].begin()) + max(row[i].end() - rit, col[j].end() - cit) << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////