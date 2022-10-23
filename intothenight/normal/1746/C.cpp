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
		vector<vector<int>> res(n);
		res[0].push_back(0);
		for(auto i = 1; i < n; ++ i){
			int d = max(a[i - 1] - a[i] - 1, 0);
			res[d].push_back(i);
		}
		set<int> rem;
		for(auto x = 0; x < n; ++ x){
			rem.insert(res[x].begin(), res[x].end());
			assert(!rem.empty());
			cout << *rem.begin() + 1 << " ";
			rem.erase(rem.begin());
		}
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