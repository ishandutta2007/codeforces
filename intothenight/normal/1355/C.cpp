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
	vector<int> a(4);
	for(auto i = 0; i < 4; ++ i){
		cin >> a[i];
	}
	long long res = 0;
	for(auto d = 0; d <= a[3] - a[1]; ++ d){
		res += 1LL * (min(a[2], a[3] - d) - max(a[1], a[2] - d) + 1) * max(a[1] - max(a[0], d + 1) + 1, 0);
	}
	cout << res << "\n";
	return 0;
}

/*
A <= x <= B
B <= y <= C
C <= z <= D

max(A, d + 1) <= x <= B
z < x + y
z - y < x
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////