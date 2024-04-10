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
		int n, m, sx, sy, ox, oy;
		cin >> n >> m >> sx >> sy >> ox >> oy, -- sx, -- sy, -- ox, -- oy;
		int dx = 1, dy = 1, res = 0;
		while(sx != ox && sy != oy){
			if(clamp(sx + dx, 0, n - 1) != sx + dx){
				dx = -dx;
			}
			if(clamp(sy + dy, 0, m - 1) != sy + dy){
				dy = -dy;
			}
			sx += dx;
			sy += dy;
			++ res;
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

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////