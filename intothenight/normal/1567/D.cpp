#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		string s;
		int m;
		cin >> s >> m;
		reverse(s.begin(), s.end());
		int n = (int)s.size();
		vector<int> a(n);
		int sum = 0;
		for(auto i = 0; i < n; ++ i){
			sum += a[i] = s[i] - '0';
		}
		while(sum < m){
			int i = 1;
			while(!a[i] || a[i - 1] + 10 > 9 * m){
				++ i;
			}
			-- a[i];
			a[i - 1] += 10;
			sum += 9;
		}
		vector<vector<int>> res(m, vector<int>(n));
		for(auto i = 0, p = 0; i < n; ++ i){
			for(auto rep = m; rep && a[i]; -- rep){
				-- a[i];
				res[p = (p + 1) % m][i] = 1;
			}
			if(a[i]){
				for(auto p = 0; p < m; ++ p){
					res[p][i] += min(a[i], 8);
					a[i] -= min(a[i], 8);
				}
			}
		}
		for(auto i = 0; i < m; ++ i){
			while(!res[i].back()){
				res[i].pop_back();
			}
			reverse(res[i].begin(), res[i].end());
			for(auto x: res[i]){
				cout << x;
			}
			cout << "\n";
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