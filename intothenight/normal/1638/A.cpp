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
		vector<int> p(n);
		for(auto i = 0; i < n; ++ i){
			cin >> p[i];
		}
		for(auto i = 0; i < n; ++ i){
			if(p[i] != i + 1){
				int j = find(p.begin(), p.end(), i + 1) - p.begin();
				ranges::reverse(p | ranges::views::take(j + 1) | ranges::views::drop(i));
				ranges::copy(p, ostream_iterator<int>(cout, " "));
				cout << "\n";
				return 0;
			}
		}
		ranges::copy(p, ostream_iterator<int>(cout, " "));
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