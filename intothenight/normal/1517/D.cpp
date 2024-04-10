#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, k;
	cin >> n >> m >> k;
	vector adj(n, vector(m, vector<array<int, 3>>()));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m - 1; ++ j){
			int x;
			cin >> x;
			adj[i][j].push_back({i, j + 1, x});
			adj[i][j + 1].push_back({i, j, x});
		}
	}
	for(auto i = 0; i < n - 1; ++ i){
		for(auto j = 0; j < m; ++ j){
			int x;
			cin >> x;
			adj[i][j].push_back({i + 1, j, x});
			adj[i + 1][j].push_back({i, j, x});
		}
	}
	if(k & 1){
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				cout << "-1 ";
			}
			cout << "\n";
		}
		return 0;
	}
	k >>= 1;
	vector<vector<int>> dp(n, vector<int>(m));
	for(auto rep = 0; rep < k; ++ rep){
		vector<vector<int>> dp_next(n, vector<int>(m, numeric_limits<int>::max()));
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				for(auto [ni, nj, w]: adj[i][j]){
					ctmin(dp_next[i][j], dp[ni][nj] + w);
				}
			}
		}
		swap(dp, dp_next);
	}
	for(auto x: dp){
		for(auto y: x){
			cout << 2 * y << " ";
		}
		cout << "\n";
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