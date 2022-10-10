#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		int sum = accumulate(a.begin(), a.end(), 0);
		for(auto d = 2; d < sum; ++ d){
			if(sum % d == 0){
				cout << n << "\n";
				for(auto i = 0; i < n; ++ i){
					cout << i + 1 << " ";
				}
				cout << "\n";
				return 0;
			}
		}
		cout << n - 1 << "\n";
		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 0);
		for(auto i = 0; i < n; ++ i){
			if(a[i] & 1){
				ind.erase(ind.begin() + i);
				break;
			}
		}
		for(auto i: ind){
			cout << i + 1 << " ";
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