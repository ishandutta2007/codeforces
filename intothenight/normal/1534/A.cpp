#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		array<array<bool, 2>, 2> found{};
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			for(auto j = 0; j < m; ++ j){
				if(a[i][j] != '.'){
					found[i + j & 1][a[i][j] == 'R'] = true;
				}
			}
		}
		if(found[0][0] && found[1][0] || found[0][1] && found[1][1] || found[0][0] && found[0][1] || found[1][0] && found[1][1]){
			cout << "NO\n";
			return 0;
		}
		char c = 'R';
		if(found[0][1] || found[1][0]){
			c = 'W';
		}
		cout << "YES\n";
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				i + j & 1 ? cout << c : cout << char(c ^ 'R' ^ 'W');
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