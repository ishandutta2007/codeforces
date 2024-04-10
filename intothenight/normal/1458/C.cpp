#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, qn;
		cin >> n >> qn;
		vector<array<int, 3>> a;
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < n; ++ j){
				int x;
				cin >> x, -- x;
				a.push_back({i, j, x});
			}
		}
		array<int, 3> val{}, state{0, 1, 2};
		string s;
		cin >> s;
		for(auto c: s){
			switch(c){
				case 'R':
				++ val[1];
				break;
				case 'L':
				-- val[1];
				break;
				case 'D':
				++ val[0];
				break;
				case 'U':
				-- val[0];
				break;
				case 'I':
				swap(val[1], val[2]);
				swap(state[1], state[2]);
				break;
				default:
				swap(val[0], val[2]);
				swap(state[0], state[2]);
			}
		}
		auto normalize = [&](int x){
			x %= n;
			if(x < 0) x += n;
			return x;
		};
		vector<vector<int>> res(n, vector<int>(n));
		for(auto v: a){
			res[normalize(v[state[0]] + val[0])][normalize(v[state[1]] + val[1])] = normalize(v[state[2]] + val[2]) + 1;
		}
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < n; ++ j){
				cout << res[i][j] << " ";
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