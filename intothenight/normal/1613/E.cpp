#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		deque<array<int, 2>> dq;
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			for(auto j = 0; j < m; ++ j){
				if(a[i][j] == 'L'){
					dq.push_back({i, j});
				}
			}
		}
		auto check = [&](int i, int j)->bool{
			int cnt = 0;
			for(auto [di, dj]: dr){
				int ni = i + di, nj = j + dj;
				if(0 <= min(ni, nj) && ni < n && nj < m && a[ni][nj] == '.'){
					++ cnt;
				}
			}
			return cnt <= 1;
		};
		while(!dq.empty()){
			auto [i, j] = dq.front();
			dq.pop_front();
			for(auto [di, dj]: dr){
				int ni = i + di, nj = j + dj;
				if(0 <= min(ni, nj) && ni < n && nj < m && a[ni][nj] == '.' && check(ni, nj)){
					a[ni][nj] = '+';
					dq.push_back({ni, nj});
				}
			}
		}
		for(auto s: a){
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