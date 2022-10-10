#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> a(n);
		array<long long, 2> s{};
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			s[i & 1] += a[i];
		}
		if(s[0] >= s[1]){
			for(auto i = 0; i < n; ++ i){
				if(i & 1){
					cout << "1 ";
				}
				else{
					cout << a[i] << " ";
				}
			}
			cout << "\n";
		}
		else{
			for(auto i = 0; i < n; ++ i){
				if(i & 1){
					cout << a[i] << " ";
				}
				else{
					cout << "1 ";
				}
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