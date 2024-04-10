#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(auto &[l, r]: a){
		cin >> l >> r;
	}
	sort(a.begin(), a.end());
	set<pair<int, int>> dp{{numeric_limits<int>::min(), 0}}; // rightmost pos(inc), ans(inc)
	for(auto [x, w]: a){
		auto [y, cnt] = *-- dp.lower_bound({x - w, numeric_limits<int>::max()});
		y = x + w, ++ cnt;
		auto it = dp.lower_bound({y, numeric_limits<int>::max()});
		while(it != dp.end() && cnt >= it->second){
			it = dp.erase(it);
		}
		-- it;
		if(it->second < cnt){
			dp.insert({y, cnt});
		}
	}
	cout << dp.rbegin()->second;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////