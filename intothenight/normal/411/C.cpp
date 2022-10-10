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



int main(){
	cin.tie(0)->sync_with_stdio(0);
	vector<array<int, 2>> a(4);
	for(auto i = 0; i < 4; ++ i){
		for(auto j = 0; j < 2; ++ j){
			cin >> a[i][j];
		}
	}
	for(auto i = 0; i < 2; ++ i){
		if(a[0][i] > max(a[2][!i], a[3][!i]) && a[1][!i] > max(a[2][i], a[3][i])){
			cout << "Team 1";
			return 0;
		}
	}
	for(auto i = 0; i < 2; ++ i){
		if((a[0][i] >= a[2][!i] || a[1][!i] >= a[3][i]) && (a[0][i] >= a[3][!i] || a[1][!i] >= a[2][i])){
			cout << "Draw";
			return 0;
		}
	}
	cout << "Team 2";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////