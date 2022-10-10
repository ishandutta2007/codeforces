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
		int n, x, y;
		string s, t;
		cin >> n >> x >> y >> s >> t;
		x = min(x, 2 * y);
		vector<int> a(n), pos;
		for(auto i = 0; i < n; ++ i){
			a[i] = s[i] != t[i];
			if(a[i]){
				pos.push_back(i);
			}
		}
		if((int)pos.size() & 1){
			cout << "-1\n";
			return 0;
		}
		long long res = 0;
		if(x >= y){
			for(auto i = 0; i < (int)pos.size() / 2; ++ i){
				res += pos[i] + 1 == pos[i + (int)pos.size() / 2] ? x : y;
			}
		}
		else{
			assert(false);
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