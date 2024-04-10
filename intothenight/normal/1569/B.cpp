#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		string s;
		cin >> n >> s;
		if(n - count(s.begin(), s.end(), '1') == 1 || n - count(s.begin(), s.end(), '1') == 2){
			cout << "NO\n";
			return 0;
		}
		vector<int> twos;
		for(auto i = 0; i < n; ++ i){
			if(s[i] == '2'){
				twos.push_back(i);
			}
		}
		vector<string> res(n, string(n, '='));
		for(auto i = 0; i < n; ++ i){
			res[i][i] = 'X';
		}
		for(auto l = 0; l < (int)twos.size(); ++ l){
			int r = (l + 1) % (int)twos.size();
			res[twos[l]][twos[r]] = '+';
			res[twos[r]][twos[l]] = '-';
		}
		cout << "YES\n";
		for(auto s: res){
			cout << s << "\n";
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