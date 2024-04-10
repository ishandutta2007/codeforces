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
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<string> init(n);
	for(auto &s: init){
		cin >> s;
	}
	vector<string> init2(m, string(n, 'z'));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			init2[j][i] = init[i][j];
		}
	}
	pair<int, vector<string>> res{numeric_limits<int>::max(), {}};
	string convert("ACGT");
	for(auto ii = 0; ii < 4; ++ ii){
		for(auto jj = ii + 1; jj < 4; ++ jj){
			for(int REP = 0; REP < 2; ++ REP){
				int kk = 0, ll = 0;
				while(ii == kk || jj == kk){
					++ kk;
				}
				while(ii == ll || jj == ll || kk == ll){
					++ ll;
				}
				string c = {convert[ii], convert[jj], convert[kk], convert[ll]};
				int cur = 0;
				vector<string> cur_res(n, string(m, 'z'));
				for(auto i = 0; i < n; ++ i){
					vector<int> ans(2);
					for(auto t = 0; t < 2; ++ t){
						for(auto j = 0; j < m; ++ j){
							ans[t] += (init[i][j] != c[2 * (i & 1) + (j & 1 ^ t)]);
						}
					}
					int t = min_element(ans.begin(), ans.end()) - ans.begin();
					cur += ans[t];
					for(auto j = 0; j < m; ++ j){
						cur_res[i][j] = c[2 * (i & 1) + (j & 1 ^ t)];
					}
				}
				if(REP){
					vector<string> cur_res2(m, string(n, 'z'));
					for(auto i = 0; i < n; ++ i){
						for(auto j = 0; j < m; ++ j){
							cur_res2[j][i] = cur_res[i][j];
						}
					}
					swap(cur_res, cur_res2);
				}
				ctmin(res, pair<int, vector<string>>(cur, cur_res));
				swap(n, m);
				swap(init, init2);
			}
		}
	}
	for(auto s: res.second){
		cout << s << "\n";
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