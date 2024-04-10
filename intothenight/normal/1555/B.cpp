#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int W, H, x1, y1, x2, y2, w, h;
		cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
		if(x2 - x1 + w > W && y2 - y1 + h > H){
			cout << "-1\n";
			return 0;
		}
		int res = numeric_limits<int>::max();
		if(x2 - x1 + w <= W){
			ctmin(res, min(w - (W - x2), w - x1));
		}
		if(y2 - y1 + h <= H){
			ctmin(res, min(h - (H - y2), h - y1));
		}
		cout << max(res, 0) << "\n";
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