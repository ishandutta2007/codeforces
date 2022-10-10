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
		array<int, 2> cnt{};
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x;
			++ cnt[x & 1];
		}
		if(cnt[1] % 4 == 0){
			cout << "Alice\n";
		}
		else if(cnt[1] % 4 == 2){
			cout << "Bob\n";
		}
		else if(cnt[1] % 4 == 1){
			if(cnt[0] % 2){
				cout << "Alice\n";
			}
			else{
				cout << "Bob\n";
			}
		}
		else{
			cout << "Alice\n";
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