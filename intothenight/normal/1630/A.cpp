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
		if(n == 4 && k == 3){
			cout << "-1\n";
			return 0;
		}
		if(k == 0){
			for(auto i = 0; i < n / 2; ++ i){
				cout << i << " " << (n - 1 ^ i) << "\n";
			}
		}
		else if(k < n - 1){
			vector<int> used(n);
			used[0] = true;
			used[k] = true;
			used[k ^ n - 1] = true;
			used[n - 1] = true;
			cout << "0 " << (k ^ n - 1) << "\n" << k << " " << n - 1 << "\n";
			for(auto i = 0; i < n / 2; ++ i){
				if(!used[i]){
					cout << i << " " << (n - 1 ^ i) << "\n";
				}
			}
		}
		else{
			vector<int> p(n);
			for(auto i = 0; i < n; ++ i){
				p[i] = n - 1 - i;
			}
			swap(p[0], p[n - 2]);
			swap(p[n - 1], p[1]);
			swap(p[n / 2], p[n / 2 + 1]);
			swap(p[n / 2 - 1], p[n / 2 - 2]);
			for(auto i = 0; i < n; ++ i){
				if(i < p[i]){
					cout << i << " " << p[i] << "\n";
				}
			}
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
At least n/2

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////