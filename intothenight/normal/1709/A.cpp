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
		int x;
		cin >> x;
		array<int, 3> a;
		for(auto i = 0; i < 3; ++ i){
			cin >> a[i];
		}
		if(!x){
			cout << "NO\n";
			return 0;
		}
		int cnt = 0;
		while(x){
			int y = a[x - 1];
			a[x - 1] = 0;
			++ cnt;
			x = y;
		}
		cnt == 3 ? cout << "YES\n" : cout << "NO\n";
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