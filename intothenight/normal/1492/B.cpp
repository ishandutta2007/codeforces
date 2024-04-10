#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> a(n), s;
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			if(s.empty() || a[s.back()] < a[i]){
				s.push_back(i);
			}
		}
		s.push_back(n);
		for(auto t = (int)s.size() - 2; t >= 0; -- t){
			for(auto i = s[t]; i < s[t + 1]; ++ i){
				cout << a[i] << " ";
			}
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