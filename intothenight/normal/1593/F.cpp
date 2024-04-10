#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, a, b;
		string s;
		cin >> n >> a >> b >> s;
		vector dp(n + 1, vector(a, vector(b, vector<int>(2 * n + 1))));
		vector prev(n + 1, vector(a, vector(b, vector(2 * n + 1, array<int, 2>{-1, -1}))));
		dp[0][0][0][n] = true;
		for(auto i = 0; i < n; ++ i){
			int x = s[i] - '0';
			for(auto ra = 0; ra < a; ++ ra){
				for(auto rb = 0; rb < b; ++ rb){
					for(auto d = 0; d <= 2 * n; ++ d){
						if(dp[i][ra][rb][d]){
							dp[i + 1][(ra * 10 + x) % a][rb][d + 1] = true;
							prev[i + 1][(ra * 10 + x) % a][rb][d + 1] = {0, ra};
							dp[i + 1][ra][(rb * 10 + x) % b][d - 1] = true;
							prev[i + 1][ra][(rb * 10 + x) % b][d - 1] = {1, rb};
						}
					}
				}
			}
		}
		pair<int, int> mindif{numeric_limits<int>::max(), {}};
		for(auto d = 1; d < 2 * n; ++ d){
			if(dp[n][0][0][d]){
				mindif = min(mindif, pair{abs(d - n), d});
			}
		}
		if(mindif.first < numeric_limits<int>::max()){
			int ra = 0, rb = 0, d = mindif.second;
			string res;
			for(auto i = n; i > 0; -- i){
				auto &p = prev[i][ra][rb][d];
				if(p[0] == 0){
					res.push_back('R');
					ra = p[1];
					-- d;
				}
				else{
					res.push_back('B');
					rb = p[1];
					++ d;
				}
			}
			reverse(res.begin(), res.end());
			cout << res << "\n";
		}
		else{
			cout << "-1\n";
		}
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