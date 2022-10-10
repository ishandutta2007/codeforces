#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		long long k;
		cin >> n >> k;
		if(n <= 61 && 1LL << n - 1 < k){
			cout << "-1\n";
			return 0;
		}
		-- k;
		vector<int> res(n);
		iota(res.rbegin(), res.rend(), 1);
		for(auto bit = 0, s = 0; bit <= 60; ++ bit){
			if(~k & 1LL << bit){
				reverse(res.begin() + s, res.begin() + bit + 1);
				s = bit + 1;
			}
		}
		reverse(res.begin(), res.end());
		for(auto x: res){
			cout << x << " ";
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