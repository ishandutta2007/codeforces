#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	array<array<int, 2>, 3> a;
	array<int, 3> x, y;
	for(auto i = 0; i < 3; ++ i){
		for(auto j = 0; j < 2; ++ j){
			cin >> a[i][j];
		}
		x[i] = a[i][0], y[i] = a[i][1];
	}
	sort(x.begin(), x.end()), sort(y.begin(), y.end());
	int mx = x[1], my = y[1];
	vector<array<int, 2>> res{{mx, my}};
	for(auto [x, y]: a){
		while(x > mx){
			res.push_back({x --, y});
		}
		while(x < mx){
			res.push_back({x ++, y});
		}
		while(y > my){
			res.push_back({x, y --});
		}
		while(y < my){
			res.push_back({x, y ++});
		}
	}
	cout << (int)res.size() << "\n";
	for(auto [x, y]: res){
		cout << x << " " << y << "\n";
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