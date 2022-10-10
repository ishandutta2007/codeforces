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

template<typename IT, typename T = int>
auto kadane(IT begin, IT end, T init = 0){
	typename iterator_traits<IT>::value_type lm = init, gm = init;
	for(; begin != end; ++ begin) lm = max(*begin, *begin + lm), gm = max(gm, lm);
	return gm;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	int res = 0;
	for(auto x = -30; x <= 30; ++ x){
		for(auto i = 0; i < n; ){
			int j = i;
			while(j < n && a[j] <= x){
				++ j;
			}
			ctmax(res, kadane(a.begin() + i, a.begin() + j, numeric_limits<int>::min() / 2) - x);
			i = j + 1;
		}
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