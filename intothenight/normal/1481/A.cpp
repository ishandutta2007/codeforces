#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	vector<int> convert(300);
	convert['U'] = 1, convert['L'] = 2, convert['D'] = 3;
	auto __solve_tc = [&](int __tc_num){
		int px, py;
		cin >> px >> py;
		string s;
		cin >> s;
		int minx = 0;
		int miny = 0;
		int maxx = 0;
		int maxy = 0;
		for(auto c: s){
			auto [dx, dy] = dr[convert[c]];
			if(dx) dx > 0 ? ++ maxx : -- minx;
			if(dy) dy > 0 ? ++ maxy : -- miny;
		}
		minx <= px && px <= maxx && miny <= py && py <= maxy ? cout << "YES\n" : cout << "NO\n";
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