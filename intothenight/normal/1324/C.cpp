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
	int tt;
	cin >> tt;
	while(tt --){
		string s;
		cin >> s;
		int n = int(s.size());
		s.insert(s.begin(), 'R');
		auto test = [&](int jump){
			vector<int> dp(n + 2);
			int x = 0;
			while(x != n + 1){
				if(dp[x]){
					break;
				}
				dp[x] = true;
				if(s[x] == 'R'){
					x = min(x + jump, n + 1);
				}
				else{
					-- x;
				}
			}
			return x == n + 1;
		};
		int l = 0, r = n + 1;
		while(r - l > 1){
			int m = l + r >> 1;
			test(m) ? r = m : l = m;
		}
		cout << r << "\n";
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