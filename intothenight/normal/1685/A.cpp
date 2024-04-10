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
		if(n & 1){
			cout << "NO\n";
			return 0;
		}
		ranges::sort(a);
		vector<int> res;
		for(auto i = 0; i < n; ++ i){
			res.push_back(a[(n >> 1) * (i & 1) + (i >> 1)]);
		}
		for(auto i = 1; i < n; ++ i){
			if(res[i - 1] == res[i]){
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n";
		ranges::copy(res, ostream_iterator<int>(cout, " "));
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