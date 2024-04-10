#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cout << fixed << setprecision(15);
	int n, qn;
	cin >> n >> qn;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	vector<tuple<int, int, double>> query(qn);
	for(auto &[l, r, p]: query){
		cin >> l >> r >> p, -- l;
	}
	sort(query.begin(), query.end(), [&](auto x, auto y){ return get<1>(x) - get<0>(x) < get<1>(y) - get<0>(y); });
	vector<int> ded(qn);
	vector<vector<int>> adj(qn);
	vector<int> val(qn, numeric_limits<int>::min() / 2);
	for(auto u = 0; u < qn; ++ u){
		for(auto v = 0; v < u; ++ v){
			if(!ded[v] && get<0>(query[u]) <= get<0>(query[v]) && get<1>(query[v]) <= get<1>(query[u])){
				adj[u].push_back(v);
				ded[v] = true;
			}
		}
		sort(adj[u].begin(), adj[u].end(), [&](int u, int v){ return get<0>(query[u]) < get<0>(query[v]); });
		if(adj[u].empty()){
			for(auto i = get<0>(query[u]); i < get<1>(query[u]); ++ i){
				ctmax(val[u], a[i]);
			}
		}
		else{
			for(auto i = get<0>(query[u]); i < get<0>(query[adj[u][0]]); ++ i){
				ctmax(val[u], a[i]);
			}
			for(auto t = 1; t < (int)adj[u].size(); ++ t){
				for(auto i = get<1>(query[adj[u][t - 1]]); i < get<0>(query[adj[u][t]]); ++ i){
					ctmax(val[u], a[i]);
				}
			}
			for(auto i = get<1>(query[adj[u].back()]); i < get<1>(query[u]); ++ i){
				ctmax(val[u], a[i]);
			}
		}
	}
	vector<double> dp{1};
	int cur_max = numeric_limits<int>::min() / 2;
	vector<int> rem(n, true);
	for(auto root = 0; root < qn; ++ root){
		if(!ded[root]){
			for(auto i = get<0>(query[root]); i < get<1>(query[root]); ++ i){
				rem[i] = false;
			}
			function<pair<int, vector<double>>(int, int)>
			dfs = [&](int u, int p){
				vector<double> dp{1};
				int cur_max = numeric_limits<int>::min() / 2;
				for(auto v: adj[u]){
					if(v != p){
						auto [umax, dpu] = dfs(v, u);
						int new_max = max(cur_max, umax);
						vector<double> dp_next(max((int)dp.size(), (int)dpu.size()));
						for(auto x = 0; x < (int)dp.size(); ++ x){
							for(auto y = 0; y < (int)dpu.size(); ++ y){
								dp_next[max(cur_max + x, umax + y) - new_max] += dp[x] * dpu[y];
							}
						}
						swap(dp, dp_next);
						swap(cur_max, new_max);
					}
				}
				int new_max = max(cur_max, val[u]);
				vector<double> dp_next((int)dp.size() + 1);
				for(auto x = 0; x < (int)dp.size(); ++ x){
					dp_next[max(x + cur_max, val[u]) - new_max] += dp[x] * (1 - get<2>(query[u]));
					dp_next[max(x + cur_max, val[u]) - new_max + 1] += dp[x] * get<2>(query[u]);
				}
				swap(dp, dp_next);
				swap(cur_max, new_max);
				return pair{cur_max, dp};
			};
			auto [umax, dpu] = dfs(root, -1);
			int new_max = max(cur_max, umax);
			vector<double> dp_next(max((int)dp.size(), (int)dpu.size()));
			for(auto x = 0; x < (int)dp.size(); ++ x){
				for(auto y = 0; y < (int)dpu.size(); ++ y){
					dp_next[max(cur_max + x, umax + y) - new_max] += dp[x] * dpu[y];
				}
			}
			swap(dp, dp_next);
			swap(cur_max, new_max);
		}
	}
	assert(abs(accumulate(dp.begin(), dp.end(), 0.0) - 1) <= 1e-4);
	int rem_max = numeric_limits<int>::min() / 2;
	for(auto i = 0; i < n; ++ i){
		if(rem[i]){
			ctmax(rem_max, a[i]);
		}
	}
	int new_max = max(cur_max, rem_max);
	vector<double> dp_next((int)dp.size());
	for(auto x = 0; x < (int)dp.size(); ++ x){
		dp_next[max(cur_max + x, rem_max) - new_max] += dp[x];
	}
	swap(dp, dp_next);
	swap(cur_max, new_max);
	double res = 0;
	for(auto x = 0; x < (int)dp.size(); ++ x){
		res += (x + cur_max) * dp[x];
	}
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