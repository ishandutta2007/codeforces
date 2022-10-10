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
		int n, k, b;
		long long s;
		cin >> n >> k >> b >> s;
		if(1LL * k * b <= s && s <= 1LL * k * b + 1LL * (k - 1) * n){
			long long rem = s - 1LL * k * b;
			vector<long long> res(n);
			res[0] = 1LL * k * b;
			for(auto i = 0; i < n; ++ i){
				long long x = min<long long>(rem, k - 1);
				rem -= x;
				res[i] += x;
			}
			ranges::copy(res, ostream_iterator<long long>(cout, " "));
			cout << "\n";
		}
		else{
			cout << "-1\n";
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