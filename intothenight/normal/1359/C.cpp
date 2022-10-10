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

template<typename Pred>
long long custom_binary_search(long long low0, long long high0, const long long &step, Pred p, const bool &is_left = true){
	auto low = low0 / step - ((low0 ^ step) < 0 && low0 % step), high = high0 / step + ((high0 ^ step) > 0 && high0 % step);
	const auto rem = low0 - low * step;
	while(high - low > 1){
		auto mid = low + (high - low >> 1);
		(p(mid * step + rem) == is_left ? low : high) = mid;
	}
	return (is_left ? low : high) * step + rem;
}

int SOLVE(){
	int h, c, t;
	cin >> h >> c >> t;
	if(2 * t <= c + h){
		cout << "2\n";
	}
	else{
		long long x, cur;
		auto pred = [&](long long i){
			x = i, cur = h + x / 2 * (c + h);
			return cur >= t * x;
		};
		long long i = custom_binary_search(1, 10000000, 2, pred);
		pred(i + 2);
		long long y = x, next = cur;
		pred(i);
		if(abs(cur * y - t * x * y) <= abs(next * x - t * x * y)){
			cout << x << "\n";
		}
		else{
			cout << x + 2 << "\n";
		}
	}
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		SOLVE();
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