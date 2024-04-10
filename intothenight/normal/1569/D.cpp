#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> x(n), y(m);
		for(auto i = 0; i < n; ++ i){
			cin >> x[i];
		}
		for(auto j = 0; j < m; ++ j){
			cin >> y[j];
		}
		vector<array<int, 2>> person(k);
		vector<vector<int>> xbelong(n + 1), ybelong(m + 1);
		for(auto i = 0; i < k; ++ i){
			cin >> person[i][0] >> person[i][1];
			if(!binary_search(x.begin(), x.end(), person[i][0])){
				xbelong[lower_bound(x.begin(), x.end(), person[i][0]) - x.begin()].push_back(person[i][1]);
			}
			else if(!binary_search(y.begin(), y.end(), person[i][1])){
				ybelong[lower_bound(y.begin(), y.end(), person[i][1]) - y.begin()].push_back(person[i][0]);
			}
		}
		long long res = 0;
		for(auto rep = 2; rep; -- rep){
			for(auto i = 0; i <= n; ++ i){
				sort(xbelong[i].begin(), xbelong[i].end());
				res += (int)xbelong[i].size() * 1LL * ((int)xbelong[i].size() - 1) / 2;
				for(auto l = 0; l < (int)xbelong[i].size(); ){
					int r = l;
					while(r < (int)xbelong[i].size() && xbelong[i][l] == xbelong[i][r]){
						++ r;
					}
					res -= 1LL * (r - l) * (r - l - 1) / 2;
					l = r;
				}
			}
			swap(n, m);
			swap(x, y);
			swap(xbelong, ybelong);
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