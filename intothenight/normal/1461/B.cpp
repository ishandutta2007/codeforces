#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> dp(n + 1, vector<int>(m + 2, -1));
		deque<array<int, 2>> dq;
		for(auto j = 0; j < m + 2; ++ j){
			dp[0][j] = 0;
			dq.push_back({0, j});
		}
		for(auto i = 0; i < n; ++ i){
			string s;
			cin >> s;
			dp[i + 1][0] = dp[i + 1][m + 1] = 0;
			dq.push_back({i + 1, 0}), dq.push_back({i + 1, m + 1});
			for(auto j = 0; j < m; ++ j){
				if(s[j] == '.'){
					dp[i + 1][j + 1] = 0;
					dq.push_back({i + 1, j + 1});
				}
			}
		}
		static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {0, -1}};
		int res = 0;
		while(!dq.empty()){
			auto [x, y] = dq.front(); dq.pop_front();
			for(auto [dx, dy]: dr){
				int nx = x + dx, ny = y + dy;
				if(nx <= n && 0 <= ny && ny <= m + 1 && !~dp[nx][ny]){
					res += dp[nx][ny] = dp[x][y] + 1;
					dq.push_back({nx, ny});
				}
			}
		}
		cout << res << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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