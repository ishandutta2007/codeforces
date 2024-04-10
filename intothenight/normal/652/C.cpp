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
	int n, m;
	cin >> n >> m;
	vector<int> pos(n);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		pos[x - 1] = i;
	}
	vector<int> reach(n, n - 1); // max pos reachable from i
	for(auto i = 0; i < m; ++ i){
		int x, y;
		cin >> x >> y;
		x = pos[x - 1], y = pos[y - 1];
		ctmin(reach[min(x, y)], max(x, y) - 1);
	}
	long long res = 0;
	for(auto i = n - 1, j = n - 1; i >= 0; -- i){
		ctmin(j, reach[i]);
		res += j - i + 1;
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