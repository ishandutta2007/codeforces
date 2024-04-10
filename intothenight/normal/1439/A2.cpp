#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	vector<vector<array<int, 2>>> shapes{
		{{0, 0}, {0, 1}, {1, 0}}
		, {{0, 0}, {0, 1}, {1, 1}}
		, {{0, 0}, {1, 0}, {1, 1}}
		, {{0, 1}, {1, 0}, {1, 1}}
	};
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		for(auto i = 0; i < n; ++ i){
			string s;
			cin >> s;
			for(auto j = 0; j < m; ++ j){
				a[i][j] = s[j] - '0';
			}
		}
		bool swapped = false;
		if(n % 2 == 0 && m % 2 == 1){
			swapped = true;
			swap(n, m);
			vector<vector<int>> temp(n, vector<int>(m));
			for(auto i = 0; i < n; ++ i){
				for(auto j = 0; j < m; ++ j){
					temp[i][j] = a[j][i];
				}
			}
			a = temp;
		}
		vector<vector<int>> res;
		auto insert = [&](int x, int y, int i){
			res.emplace_back();
			for(auto [dx, dy]: shapes[i]){
				if(swapped){
					res.back().push_back(y + dy);
					res.back().push_back(x + dx);
				}
				else{
					res.back().push_back(x + dx);
					res.back().push_back(y + dy);
				}
				a[x + dx][y + dy] ^= 1;
			}
		};
		auto revert = [&](){
			for(auto i = 0; i < 6; i += 2){
				int x = res.back()[i], y = res.back()[i + 1];
				if(swapped){
					swap(x, y);
				}
				a[x][y] ^= 1;
			}
			res.pop_back();
		};
		for(auto i = 0; i < n - 2; ++ i){
			for(auto j = 0; j + 1 <= m - 1; j += 2){
				if(a[i][j] && !a[i][j + 1]){
					insert(i, j, 2);
				}
				else if(!a[i][j] && a[i][j + 1]){
					insert(i, j, 3);
				}
				else if(a[i][j] && a[i][j + 1]){
					insert(i, j, 0);
				}
			}
		}
		for(auto i = n - 2, j = 0; j + 1 <= m - 1; j += 2){
			for(auto mask = 0; mask < 16; ++ mask){
				for(auto bit = 0; bit < 4; ++ bit){
					if(mask & 1 << bit){
						insert(i, j, bit);
					}
				}
				if(!a[i][j] && !a[i][j + 1] && !a[i + 1][j] && !a[i + 1][j + 1]){
					break;
				}
				for(auto bit = 0; bit < 4; ++ bit){
					if(mask & 1 << bit){
						revert();
					}
				}
			}
		}
		for(auto i = 0, j = m - 2; i < n - 2; ++ i){
			if(a[i][j] && !a[i][j + 1]){
				insert(i, j, 2);
			}
			else if(!a[i][j] && a[i][j + 1]){
				insert(i, j, 3);
			}
			else if(a[i][j] && a[i][j + 1]){
				insert(i, j, 0);
			}
		}
		for(auto i = n - 2, j = m - 2, mask = 0; mask < 16; ++ mask){
			for(auto bit = 0; bit < 4; ++ bit){
				if(mask & 1 << bit){
					insert(i, j, bit);
				}
			}
			if(!a[i][j] && !a[i][j + 1] && !a[i + 1][j] && !a[i + 1][j + 1]){
				break;
			}
			for(auto bit = 0; bit < 4; ++ bit){
				if(mask & 1 << bit){
					revert();
				}
			}
		}
		cout << (int)res.size() << "\n";
		for(auto v: res){
			for(auto x: v){
				cout << x + 1 << " ";
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