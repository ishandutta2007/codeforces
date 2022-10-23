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
		if(abs(accumulate(a.begin(), a.end(), 0)) & 1){
			cout << "-1\n";
			return 0;
		}
		vector<array<int, 2>> res;
		for(auto i = 0; i < n; ){
			while(i < n && !a[i]){
				res.push_back({i, i + 1});
				++ i;
			}
			if(i == n){
				break;
			}
			int j = i + 1;
			while(j < n && !a[j]){
				++ j;
			}
			assert(j < n);
			if(a[i] != a[j] && j - i & 1){
				res.push_back({i, j});
				res.push_back({j, j + 1});
			}
			else if(a[i] == a[j] && j - i + 1 & 1){
				res.push_back({i, j - 1});
				res.push_back({j - 1, j + 1});
			}
			else{
				res.push_back({i, j + 1});
			}
			i = j + 1;
		}
		cout << (int)res.size() << "\n";
		for(auto [l, r]: res){
			cout << l + 1 << " " << r << "\n";
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