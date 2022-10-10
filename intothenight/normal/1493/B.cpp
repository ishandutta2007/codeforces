#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto mirror = [&](int d){
		switch(d){
			case 0:
			return 0;
			case 1:
			return 1;
			case 2:
			return 5;
			case 3:
			return -1;
			case 4:
			return -1;
			case 5:
			return 2;
			case 6:
			return -1;
			case 7:
			return -1;
			case 8:
			return 8;
			default:
			return -1;
		}
	};
	auto __solve_tc = [&](int __tc_num){
		int h, m;
		string s;
		cin >> h >> m >> s;
		int cur = m * ((s[0] - '0') * 10 + s[1] - '0') + (s[3] - '0') * 10 + s[4] - '0';
		auto ok = [&](){
			auto [x, y] = div(cur, m);
			auto [x0, x1] = div(x, 10);
			auto [y0, y1] = div(y, 10);
			if(!~(x0 = mirror(x0)) || !~(x1 = mirror(x1)) || !~(y0 = mirror(y0)) || !~(y1 = mirror(y1))){
				return false;
			}
			return h > y1 * 10 + y0 && m > x1 * 10 + x0;
		};
		while(!ok()){
			cur = (cur + 1) % (h * m);
		}
		auto [x, y] = div(cur, m);
		cout << x / 10 << x % 10 << ":" << y / 10 << y % 10 << "\n";
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