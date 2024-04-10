#include <bits/stdc++.h>
using namespace std;

// given threshold and pairs of {profit, bound}, profit >= 0 and bound >= 0,
// find the maximum profit obtainable equal or less than the threshold
// O(n * th) time
// O(n * th) memory if recover_choices, otherwise O(th)
pair<int, vector<int>>
profit_bounded_knapsack(int th, const vector<array<int, 2>> &items, bool recover_choices = false){
	int n = (int)items.size();
	if(recover_choices){
		vector<vector<bool>> dp(n + 1);
		dp[0] = {true};
		for(auto i = 0; i < n; ++ i){
			auto [profit, bound] = items[i];
			if(!profit || !bound || profit > th){
				dp[i + 1] = dp[i];
				continue;
			}
			long long len = 1LL * profit * bound;
			int cth = (int)dp[i].size() - 1, ncth = min<long long>(th, cth + len);
			dp[i + 1].resize(ncth + 1);
			for(auto rem = 0; rem < profit; ++ rem){
				int sum = 0;
				for(auto x = rem; x <= ncth; x += profit){
					if(x <= cth) sum += dp[i][x];
					dp[i + 1][x] = sum;
					if(len <= x) sum -= dp[i][x - len];
				}
			}
		}
		int mxprofit = min(th, (int)dp[n].size() - 1);
		while(!dp[n][mxprofit]) -- mxprofit;
		vector<int> counts(n);
		for(auto i = n - 1, cth = mxprofit; i >= 0; -- i) while(cth >= (int)dp[i].size() || !dp[i][cth]) cth -= items[i][0], ++ counts[i];
		return {mxprofit, counts};
	}
	else{
		vector<bool> dp{true};
		for(auto i = 0; i < n; ++ i){
			auto [profit, bound] = items[i];
			if(!profit || !bound || profit > th) continue;
			long long len = 1LL * profit * bound;
			int cth = (int)dp.size() - 1, ncth = min<long long>(th, cth + len);
			vector<bool> dp_next(ncth + 1);
			for(auto rem = 0; rem < profit; ++ rem){
				int sum = 0;
				for(auto x = rem; x <= ncth; x += profit){
					if(x <= cth) sum += dp[x];
					dp_next[x] = sum;
					if(len <= x) sum -= dp[x - len];
				}
			}
			swap(dp, dp_next);
		}
		int mxprofit = min(th, (int)dp.size() - 1);
		while(!dp[mxprofit]) -- mxprofit;
		return {mxprofit, {}};
	}
}

// given threshold and items with profit, profit >= 0,
// find the maximum profit obtainable equal or less than the threshold
// O(distinct_value_cnt * th) time
// O(distinct_value_cnt * th) memory if recover_choices, otherwise O(th)
// Requires profit_bound_knapsack
pair<int, vector<bool>>
profit_bounded_zero_one_knapsack_with_duplicates(int th, const vector<int> &items, bool recover_choices = false){
	int n = (int)items.size();
	vector<array<int, 2>> items2(th + 1);
	for(auto x = 0; x <= th; ++ x) items2[x][0] = x;
	for(auto x: items) if(x <= th) ++ items2[x][1];
	items2.erase(remove_if(items2.begin(), items2.end(), [&](const auto &v){ return !v[1]; }), items2.end());
	auto [mxprofit, counts2] = profit_bounded_knapsack(th, items2, recover_choices);
	if(!recover_choices) return {mxprofit, {}};
	vector<int> counts(th + 1);
	for(auto i = 0; i < (int)items2.size(); ++ i) counts[items2[i][0]] = counts2[i];
	vector<bool> picked(n);
	for(auto i = 0; i < n; ++ i) if(items[i] <= th && counts[items[i]]) -- counts[items[i]], picked[i] = true;
	return {mxprofit, picked};
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, x;
	cin >> n >> x;
	vector<vector<int>> adj(n);
	for(auto u = 1; u < n; ++ u){
		int p;
		cin >> p, -- p;
		adj[p].push_back(u);
	}
	vector<int> depth(n);
	vector<vector<int>> nodes_at(n);
	function<void(int)> dfs = [&](int u){
		nodes_at[depth[u]].push_back(u);
		for(auto v: adj[u]){
			depth[v] = depth[u] + 1;
			dfs(v);
		}
	};
	dfs(0);
	vector<int> depth_cnt(n);
	for(auto u = 0; u < n; ++ u){
		++ depth_cnt[depth[u]];
	}
	string res(n, 'b');
	if(auto [mx, picked] = profit_bounded_zero_one_knapsack_with_duplicates(x, depth_cnt, true); mx == x){
		for(auto d = 0; d < n; ++ d){
			if(picked[d]){
				for(auto u: nodes_at[d]){
					res[u] = 'a';
				}
			}
		}
		cout << *max_element(depth.begin(), depth.end()) + 1 << "\n" << res << "\n";
		return 0;
	}
	else{
		array<int, 2> rem{x, n - x};
		for(auto d = 0; d < n; ++ d){
			if(rem[0] >= (int)nodes_at[d].size()){
				rem[0] -= (int)nodes_at[d].size();
				for(auto u: nodes_at[d]){
					res[u] = 'a';
				}
			}
			else if(rem[1] >= (int)nodes_at[d].size()){
				rem[1] -= (int)nodes_at[d].size();
			}
			else{
				int i = min_element(rem.begin(), rem.end()) - rem.begin();
				for(auto u: nodes_at[d]){
					if(adj[u].empty()){
						if(rem[i]){
							res[u] = i + 'a';
							-- rem[i];
						}
						else{
							assert(rem[!i]);
							res[u] = !i + 'a';
							-- rem[!i];
						}
					}
					else{
						assert(rem[!i]);
						res[u] = !i + 'a';
						-- rem[!i];
					}
				}
				assert(!rem[i]);
				for(++ d; d < n; ++ d){
					for(auto u: nodes_at[d]){
						res[u] = !i + 'a';
					}
				}
				cout << *max_element(depth.begin(), depth.end()) + 2 << "\n" << res << "\n";
				return 0;
			}
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