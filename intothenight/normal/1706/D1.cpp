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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		vector<int> p(n, 1);
		set<pair<int, int>, greater<>> s;
		for(auto i = 0; i < n; ++ i){
			s.insert({a[i] / p[i], -i});
		}
		int res = s.begin()->first - s.rbegin()->first;
		while(true){
			auto [q, i] = *s.begin();
			s.erase(s.begin());
			i = -i;
			p[i] = a[i] / (a[i] / p[i]) + 1;
			if(p[i] > min(a[i], k)){
				break;
			}
			s.insert({a[i] / p[i], -i});
			res = min(res, s.begin()->first - s.rbegin()->first);
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