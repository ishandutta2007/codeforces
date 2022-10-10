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
		vector<int> order(n);
		iota(order.begin(), order.end(), 0);
		ranges::sort(order, [&](int i, int j){ return a[i] > a[j]; });
		long long time = 0;
		vector<int> res(n);
		for(auto i = 0; i < n; ++ i){
			res[order[i]] = (i + 2 >> 1) * (i & 1 ? -1 : 1);
			time += 2LL * a[order[i]] * abs(res[order[i]]);
		}
		res.insert(res.begin(), 0);
		cout << time << "\n";
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