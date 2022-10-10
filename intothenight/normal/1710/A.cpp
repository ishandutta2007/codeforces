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
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(k);
		copy_n(istream_iterator<int>(cin), k, a.begin());
		for(auto rep = 2; rep; -- rep){
			vector<int> cnt;
			for(auto x: a){
				if(x >= 2 * n){
					cnt.push_back(x / n);
				}
			}
			if(cnt.empty() || ranges::max(cnt) == 2 && m & 1){
				swap(n, m);
				continue;
			}
			if(accumulate(cnt.begin(), cnt.end(), 0LL) >= m){
				cout << "Yes\n";
				return 0;
			}
			swap(n, m);
		}
		cout << "No\n";
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
3 3 2
8 8
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////