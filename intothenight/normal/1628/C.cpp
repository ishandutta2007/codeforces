#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<vector<int>> a(n, vector<int>(n));
		vector<vector<int>> used(n, vector<int>(n));
		static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		auto safe = [&](int i, int j)->bool{
			if(min(i, j) < 0 || max(i, j) >= n){
				return false;
			}
			for(auto [di, dj]: dr){
				int ni = i + di, nj = j + dj;
				if(0 <= min(ni, nj) && max(ni, nj) < n && used[ni][nj]){
					return false;
				}
			}
			return true;
		};
		int res = 0;
		auto set = [&](int i, int j)->void{
			res ^= a[i][j];
			for(auto [di, dj]: dr){
				int ni = i + di, nj = j + dj;
				if(0 <= min(ni, nj) && max(ni, nj) < n){
					assert(!used[ni][nj]);
					used[ni][nj] = true;
				}
			}
		};
		for(auto &x: a | ranges::views::join){
			cin >> x;
		}
		if(~n & 2){
			set(0, 0);
			set(1, 0);
		}
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < n; ++ j){
				if(safe(i, j)){
					if(j + 1 < n && safe(i, j + 1)){
						set(i, j);
						set(i, j + 1);
					}
					else if(i + 1 < n && safe(i + 1, j)){
						set(i, j);
						set(i + 1, j);
					}
				}
			}
		}
		cout << res << "\n";
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
2x2
o.
o.

4x4
oo..
...o
...o
oo..

6x6
o..oo.
o.....
..o..o
..o..o
o.....
o..oo.

8x8
oo..oo..
.......o
..oo...o
o....o..
o....o..
..oo...o
.......o
oo..oo..

10x10
o..oo..oo.
o.........
..o..oo..o
..o......o
o...o..o..
o...o..o..
..o......o
..o..oo..o
o.........
o..oo..oo.
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////