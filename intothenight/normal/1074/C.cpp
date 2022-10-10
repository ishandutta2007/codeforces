#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int max_x = numeric_limits<int>::min(), min_x = numeric_limits<int>::max();
	int max_y = numeric_limits<int>::min(), min_y = numeric_limits<int>::max();
	vector<array<int, 2>> a(n);
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < 2; ++ j){
			cin >> a[i][j];
		}
		ctmin(min_x, a[i][0]), ctmax(max_x, a[i][0]);
		ctmin(min_y, a[i][1]), ctmax(max_y, a[i][1]);
	}
	for(auto [x, y]: a){
		if((x == min_x || x == max_x) && (y == min_y || y == max_y)){
			for(auto i = 0; i < n - 2; ++ i){
				cout << 2 * (max_x + max_y - min_x - min_y) << " ";
			}
			cout << "\n";
			return 0;
		}
	}
	int res = 0;
	for(auto [x, y]: a){
		ctmax(res, 2 * (max(max_x - x, x - min_x) + max(max_y - y, y - min_y)));
	}
	cout << res << " ";
	for(auto i = 0; i < n - 3; ++ i){
		cout << 2 * (max_x + max_y - min_x - min_y) << " ";
	}
	cout << "\n";
	return 0;
}

/*
2 * (max_x - min_x + max_y - min_y)
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////