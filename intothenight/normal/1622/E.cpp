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
		vector<int> exp(n);
		for(auto i = 0; i < n; ++ i){
			cin >> exp[i];
		}
		vector<string> adjm(n);
		for(auto i = 0; i < n; ++ i){
			cin >> adjm[i];
		}
		vector<int> weight(m), order(m), p(m);
		iota(begin(order), end(order), 0);
		pair<long long, vector<int>> res{numeric_limits<long long>::min(), vector<int>(m)};
		for(auto mask = 0; mask < 1 << n; ++ mask){
			long long cur = 0;
			ranges::fill(weight, 0);
			for(auto i = 0; i < n; ++ i){
				if(mask & 1 << i){
					cur += exp[i];
					for(auto j = 0; j < m; ++ j){
						if(adjm[i][j] & 1){
							-- weight[j];
						}
					}
				}
				else{
					cur -= exp[i];
					for(auto j = 0; j < m; ++ j){
						if(adjm[i][j] & 1){
							++ weight[j];
						}
					}
				}
			}
			ranges::sort(order, [&](int i, int j){ return weight[i] < weight[j]; });
			for(auto t = 0; t < m; ++ t){
				cur += (p[order[t]] = t + 1) * weight[order[t]];
			}
			if(res.first < cur){
				res.first = cur;
				ranges::copy(p, begin(res.second));
			}
		}
		ranges::copy(res.second, ostream_iterator<int>(cout, " "));
		cout << "\n";
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