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
		vector<int> a(n), b(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		copy_n(istream_iterator<int>(cin), n, b.begin());
		array<vector<int>, 2> c;
		for(auto i = 0; i < n; ++ i){
			c[a[i]].push_back(b[i]);
		}
		ranges::sort(c[0] | ranges::views::reverse);
		ranges::sort(c[1] | ranges::views::reverse);
		long long res = 0;
		if((int)c[0].size() != (int)c[1].size()){
			if((int)c[0].size() < (int)c[1].size()){
				swap(c[0], c[1]);
			}
			res += accumulate(c[1].begin(), c[1].end(), 0LL) * 2;
			res += accumulate(c[0].begin(), c[0].begin() + (int)c[1].size(), 0LL) * 2 + accumulate(c[0].begin() + (int)c[1].size(), c[0].end(), 0LL);
		}
		else{
			res += accumulate(c[0].begin(), c[0].end(), 0LL) * 2 + accumulate(c[1].begin(), c[1].end(), 0LL) * 2 - min(c[0].back(), c[1].back());
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