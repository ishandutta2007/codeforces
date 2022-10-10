#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		const int mx = 10;
		vector<array<int, 3>> two(mx * mx, {-1, -1});
		vector<array<int, 3>> three(mx * mx * mx, {-1, -1, -1});
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			for(auto j = 0; j < m; ++ j){
				if(j + 2 <= m){
					two[a[i][j] - '0' + (a[i][j + 1] - '0') * mx] = {i, j, j + 2};
				}
				if(j + 3 <= m){
					three[a[i][j] - '0' + (a[i][j + 1] - '0') * mx + (a[i][j + 2] - '0') * mx * mx] = {i, j, j + 3};
				}
			}
		}
		string s;
		cin >> s;
		vector<int> dp(m + 1);
		vector<array<int, 3>> prev(m + 1, {-1, -1, -1});
		dp[0] = true;
		for(auto i = 1; i <= m; ++ i){
			if(i >= 2){
				auto t = s.substr(i - 2, 2);
				if(auto [id, l, r] = two[t[0] - '0' + (t[1] - '0') * mx]; ~id && dp[i - (r - l)]){
					dp[i] = true;
					prev[i] = {id, l, r};
					continue;
				}
			}
			if(i >= 3){
				auto t = s.substr(i - 3, 3);
				if(auto [id, l, r] = three[t[0] - '0' + (t[1] - '0') * mx + (t[2] - '0') * mx * mx]; ~id && dp[i - (r - l)]){
					dp[i] = true;
					prev[i] = {id, l, r};
					continue;
				}
			}
		}
		if(!dp[m]){
			cout << "-1\n";
			return 0;
		}
		vector<array<int, 3>> res;
		for(auto i = m; i; ){
			auto [id, l, r] = prev[i];
			i -= r - l;
			res.push_back({id, l, r});
		}
		cout << (int)res.size() << "\n";
		for(auto [i, l, r]: res | ranges::views::reverse){
			cout << l + 1 << " " << r << " " << i + 1 << "\n";
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