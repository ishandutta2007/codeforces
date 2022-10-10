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
		int n;
		cin >> n;
		vector<int> c(n);
		cin >> c[0], -- c[0];
		for(auto i = 1; i < n; ++ i){
			cin >> c[n - i], -- c[n - i];
		}
		auto it = ranges::find(c, 0);
		if(it == c.end()){
			cout << "NO\n";
			return 0;
		}
		ranges::rotate(c, it + 1);
		for(auto i = n - 2; i >= 0; -- i){
			if(c[i] == 0 || c[i] > c[i + 1] + 1){
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n";
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