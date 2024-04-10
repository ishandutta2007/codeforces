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
		ranges::sort(a);
		if(a[2] < 0 || a[n - 3] > 0){
			cout << "NO\n";
			return 0;
		}
		vector<int> b;
		for(auto i = 0; i < min(n, 6); ++ i){
			b.push_back(a[i]);
		}
		for(auto i = max(n - 6, 6); i < n; ++ i){
			b.push_back(a[i]);
		}
		ranges::sort(b);
		n = (int)b.size();
		for(auto i = 0; i < n; ++ i){
			for(auto j = i + 1; j < n; ++ j){
				for(auto k = j + 1; k < n; ++ k){
					if(!ranges::binary_search(b, 0LL + b[i] + b[j] + b[k])){
						cout << "NO\n";
						return 0;
					}
				}
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