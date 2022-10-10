#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	long long w;
	vector<long long> cnt(9);
	cin >> w;
	long long tot = 0;
	for(int i = 1; i <= 8; ++ i){
		cin >> cnt[i];
		tot += i * cnt[i];
	}
	if(w >= tot){
		cout << tot;
		return 0;
	}
	const int mx = 840;
	vector<int> dp(mx + 1);
	dp[0] = true;
	for(int i = 1; i <= 8; ++ i){
		for(int j = 0; j < min<long long>(mx / i, cnt[i]); ++ j){
			for(int k = mx; k >= i; -- k){
				if(dp[k - i]){
					dp[k] = true;
				}
			}
		}
	}
	if(tot <= w + mx){
		int rem = tot - w;
		while(!dp[rem]){
			++ rem;
		}
		cout << tot - rem;
	}
	else{
		int rem = w % mx;
		for(; ; -- rem){
			if(dp[rem]){
				break;
			}
		}
		cout << w / mx * mx + rem;
	}
	return 0;
}

/*
lcm(1, 2, 3, 4, 5, 6, 7, 8) = 8 * 3 * 5 * 7 = 840
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////