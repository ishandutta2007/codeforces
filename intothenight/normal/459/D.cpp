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
	int n;
	cin >> n;
	map<int, int> q;
	vector<int> a(n), left(n), right(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		++ q[a[i]];
		left[i] = q[a[i]];
	}
	q.clear();
	for(auto i = n - 1; i >= 0; -- i){
		++ q[a[i]];
		right[i] = q[a[i]];
	}
	Tree<array<int, 2>> t;
	long long res = 0;
	for(auto i = n - 1; i >= 0; -- i){
		res += t.order_of_key({left[i], numeric_limits<int>::min()});
		t.insert({right[i], i});
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////