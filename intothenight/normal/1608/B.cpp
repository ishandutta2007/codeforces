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
		int n, a, b;
		cin >> n >> a >> b;
		if(abs(a - b) >= 2 || a + b + 2 > n){
			cout << "-1\n";
			return 0;
		}
		if(a == b){
			vector<int> res(n, 1);
			for(auto sign = 1, i = 1; i < a + b + 2; ++ i, sign *= -1){
				res[i] = res[i - 1] + sign * i;
			}
			int x = 1 - *ranges::min_element(res);
			for(auto &y: res) y += x;
			for(auto i = a + b + 2; i < n; ++ i){
				res[i] = i + 1;
			}
			for(auto x: res){
				cout << x << " ";
			}
			cout << "\n";
		}
		else if(a + 1 == b){
			vector<int> res(n, 1);
			for(auto sign = -1, i = 1; i < a + b + 2; ++ i, sign *= -1){
				res[i] = res[i - 1] + sign * i;
			}
			int x = 1 - *ranges::min_element(res);
			for(auto &y: res) y += x;
			for(auto i = a + b + 2; i < n; ++ i){
				res[i] = i + 1;
			}
			for(auto x: res){
				cout << x << " ";
			}
			cout << "\n";
		}
		else{
			swap(a, b);
			vector<int> res(n, 1);
			for(auto sign = -1, i = 1; i < a + b + 2; ++ i, sign *= -1){
				res[i] = res[i - 1] + sign * i;
			}
			int x = 1 - *ranges::min_element(res);
			for(auto &y: res) y += x;
			for(auto i = a + b + 2; i < n; ++ i){
				res[i] = i + 1;
			}
			for(auto &x: res) x = n + 1 - x;
			for(auto x: res){
				cout << x << " ";
			}
			cout << "\n";
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