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
	int tt;
	cin >> tt;
	while(tt --){
		int n, m, k;
		string s;
		cin >> n >> m >> k >> s;
		vector<int> cnt(26);
		for(auto c: s){
			++ cnt[c - 'A'];
		}
		static constexpr long long inf = numeric_limits<long long>::max();
		long long res = inf;
		for(int cut = 0; cut < 26; ++ cut){
			vector<bool> dp(n + 1);
			dp[0] = true;
			for(int i = 0; i < 26; ++ i){
				if(i != cut){
					for(int j = n; j >= cnt[i]; -- j){
						if(dp[j - cnt[i]]){
							dp[j] = true;
						}
					}
				}
			}
			for(int i = max(n - cnt[cut], 0); i <= n; ++ i){
				if(dp[i]){
					int rem = k - cnt[cut] - i;
					ctmin(res, 1LL * (n - i) * min(max(m - rem, 0), cnt[cut] - (n - i)));
				}
			}
		}
		cout << res << "\n";
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