#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	long long n, k, a, b;
	cin >> n >> k >> a >> b;
	pair<long long, long long> res{numeric_limits<long long>::max(), numeric_limits<long long>::min()};
	auto solve = [&](long long x){
		for(int t = 0; t < n; ++ t){
			ctmin(res.first, n * k / max(1LL, gcd(x + t * k, n * k)));
			ctmax(res.second, n * k / max(1LL, gcd(x + t * k, n * k)));
		}
	};
	solve(abs(a - b)), solve(a + b);
	cout << res.first << " " << res.second;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////