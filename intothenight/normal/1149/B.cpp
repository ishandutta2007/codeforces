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
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	string s;
	cin >> n >> q >> s;
	const int mx = 1 << 8;
	vector<vector<int>> go(n + 1, vector<int>(mx, n));
	for(auto i = n - 1; i >= 0; -- i){
		static vector<int> last(mx, n);
		last[s[i]] = i;
		go[i] = last;
	}
	vector<string> cur(3);
	vector<int> sz(3);
	vector<vector<vector<int>>> dp(251, vector<vector<int>>(251, vector<int>(251, n)));
	dp[0][0][0] = -1;
	auto get_dp = [&](int i, int j, int k){
		dp[i][j][k] = min({
			  i ? go[min(dp[i - 1][j][k] + 1, n)][cur[0][i - 1]] : n
			, j ? go[min(dp[i][j - 1][k] + 1, n)][cur[1][j - 1]] : n
			, k ? go[min(dp[i][j][k - 1] + 1, n)][cur[2][k - 1]] : n
		});
	};
	for(int it = 0; it < q; ++ it){
		char type;
		cin >> type;
		if(type == '+'){
			int i;
			char c;
			cin >> i >> c, -- i;
			cur[i].push_back(c);
			++ sz[i];
			if(i == 0){
				for(auto j = 0; j <= sz[1]; ++ j){
					for(auto k = 0; k <= sz[2]; ++ k){
						get_dp(sz[0], j, k);
					}
				}
			}
			else if(i == 1){
				for(auto i = 0; i <= sz[0]; ++ i){
					for(auto k = 0; k <= sz[2]; ++ k){
						get_dp(i, sz[1], k);
					}
				}
			}
			else{
				for(auto i = 0; i <= sz[0]; ++ i){
					for(auto j = 0; j <= sz[1]; ++ j){
						get_dp(i, j, sz[2]);
					}
				}
			}
		}
		else{
			int i;
			cin >> i, -- i;
			cur[i].pop_back();
			-- sz[i];
		}
		/*cout << "IT = " << it << "\n";
		for(auto i = 0; i <= sz[0]; ++ i){
			for(auto j = 0; j <= sz[1]; ++ j){
				for(auto k = 0; k <= sz[2]; ++ k){
					cout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << "\n";
				}
			}
		}*/
		dp[sz[0]][sz[1]][sz[2]] < n ? cout << "YES\n" : cout << "NO\n";
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