#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, m, x;
		cin >> n >> m >> x;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		int tot = accumulate(a.begin(), a.end(), 0);
		vector<int> h(m);
		set<pair<int, int>> s;
		for(auto i = 0; i < m; ++ i){
			s.insert({h[i], i});
		}
		cout << "YES\n";
		for(auto i = 0; i < n; ++ i){
			int j = s.begin()->second; s.erase(s.begin());
			cout << j + 1 << " ";
			s.insert({h[j] += a[i], j});
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