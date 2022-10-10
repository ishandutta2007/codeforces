#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 2>> res;
	auto apply = [&](int i, int j){
		res.push_back({i, j});
	};
	for(auto rep = 0, s = 0; rep < 2; ++ rep, s = n - (1 << __lg(n))){
		for(auto bit = 0; bit < __lg(n); ++ bit){
			for(auto i = 0; i < 1 << __lg(n); ++ i){
				if(!(i & 1 << bit)){
					apply(i + s, (i ^ 1 << bit) + s);
				}
			}
		}
	}
	cout << (int)res.size() << "\n";
	for(auto [x, y]: res){
		cout << x + 1 << " " << y + 1 << "\n";
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