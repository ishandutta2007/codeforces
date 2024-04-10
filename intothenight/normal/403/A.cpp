#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, p;
		cin >> n >> p;
		vector<array<int, 2>> res;
		for(auto u = 0; u < n; ++ u){
			int v = (u + 1) % n;
			res.push_back({u, v});
			v = (v + 1) % n;
			res.push_back({u, v});
		}
		for(auto u = 0; u < n; ++ u){
			for(auto i = 3; i <= n / 2; ++ i){
				for(auto &[u, v]: res){
					if(u > v){
						swap(u, v);
					}
				}
				sort(res.begin(), res.end()), res.erase(unique(res.begin(), res.end()), res.end());
				if((int)res.size() < 2 * n + p){
					int v = (u + i) % n;
					res.push_back({u, v});
				}
			}
		}
		for(auto [u, v]: res){
			cout << u + 1 << " " << v + 1 << "\n";
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