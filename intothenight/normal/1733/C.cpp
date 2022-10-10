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
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		array<vector<int>, 2> pos;
		for(auto i = 0; i < n; ++ i){
			pos[a[i] & 1].push_back(i);
		}
		cout << n - 1 << "\n";
		for(auto i: pos[a[0] & 1] | ranges::views::take((int)pos[a[0] & 1].size() - 1)){
			cout << i + 1 << " " << pos[a[0] & 1].back() + 1 << "\n";
		}
		for(auto i: pos[~a[0] & 1]){
			cout << "1 " << i + 1 << "\n";
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