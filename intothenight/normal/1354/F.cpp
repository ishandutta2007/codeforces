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



int SOLVE(){
	int n, k;
	cin >> n >> k;
	vector<array<int, 3>> a(n);
	for(auto i = 0; i < n; ++ i){
		for(auto j = 1; j >= 0; -- j){
			cin >> a[i][j];
		}
		a[i][2] = i;
	}
	sort(a.begin(), a.end());
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1)), prev(n + 1, vector<int>(k + 1));
	dp[0][0] = 0;
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j <= min(i, k); ++ j){
			if(dp[i + 1][j] < dp[i][j] + (k - 1) * a[i][0]){
				dp[i + 1][j] = dp[i][j] + (k - 1) * a[i][0];
				prev[i + 1][j] = j;
			}
			if(j < k && dp[i + 1][j + 1] < dp[i][j] + j * a[i][0] + a[i][1]){
				dp[i + 1][j + 1] = dp[i][j] + j * a[i][0] + a[i][1];
				prev[i + 1][j + 1] = j;
			}
		}
	}
	vector<int> used(n);
	for(auto REP = 0, i = n, j = k; REP < n; ++ REP){
		int pj = prev[i][j];
		-- i;
		if(j != pj){
			-- j;
			used[i] = true;
		}
	}
	vector<int> p, np;
	for(auto u = 0; u < n; ++ u){
		used[u] ? p.push_back(u) : np.push_back(u);
	}
	cout << k + 2 * (n - k) << "\n";
	for(auto i = 0; i < k - 1; ++ i){
		cout << a[p[i]][2] + 1 << " ";
	}
	for(auto i: np){
		cout << a[i][2] + 1 << " " << -(a[i][2] + 1) << " ";
	}
	cout << a[p[k - 1]][2] + 1 << "\n";
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		SOLVE();
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