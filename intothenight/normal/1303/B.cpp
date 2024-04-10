#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template<typename Pred>
long long custom_binary_search(long long low, long long high, Pred p, bool is_left = true){
	assert(low < high);
	if(is_left){
		while(high - low > 1){
			long long mid = low + (high - low >> 1);
			p(mid) ? low = mid : high = mid;
		}
		return low;
	}
	else{
		while(high - low > 1){
			long long mid = low + (high - low >> 1);
			p(mid) ? high = mid : low = mid;
		}
		return high;
	}
}
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		long long n, g, b;
		cin >> n >> g >> b;
		if(g >= b){
			cout << n << "\n";
		}
		else{
			auto pred = [&](long long x){
				long long q = x / (g + b), r = x % (g + b);
				long long gg = q * g + min(r, g), bb = q * b + max(0LL, r - g);
				return gg + min(bb, gg) >= n;
			};
			cout << custom_binary_search(0, 2e18, pred, false) << "\n";
		}
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