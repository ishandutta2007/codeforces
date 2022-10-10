#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<array<int, 2>> dp(n);
	int res = 0;
	function<void(int, int)> dfs = [&](int u, int p){
		int cnt = 0;
		array<int, 2> mx{}, smx{};
		auto update = [&](int t, int x){
			if(x >= mx[t]){
				smx[t] = mx[t];
				mx[t] = x;
			}
			else ctmax(smx[t], x);
		};
		for(auto v: adj[u]){
			if(v != p){
				++ cnt;
				dfs(v, u);
				update(0, dp[v][0]);
				update(1, max(dp[v][0], dp[v][1]));
			}
		}
		dp[u][0] = mx[1] + max(cnt - 1, 0);
		dp[u][1] = mx[0] + 1;
		ctmax(res, max({dp[u][0], dp[u][1], mx[1] + smx[1] + max(cnt - 2, 0) + (u != p), mx[0] + smx[0] + 1}));
	};
	dfs(0, 0);
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