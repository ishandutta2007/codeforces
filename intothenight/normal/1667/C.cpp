#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	if(n == 1){
		cout << "1\n1 1\n";
		return 0;
	}
	int step = (n - 2) / 3, rem = (n - 2) % 3;
	vector<array<int, 2>> res;
	for(auto x = step - 1; x >= 0; -- x){
		res.push_back({x, step - 1 - x});
	}
	for(auto x = step * 2; x >= step; -- x){
		res.push_back({x, step * 3 - x});
	}
	for(auto r = 0; r < rem; ++ r){
		res.push_back({step, step * 2 + 1 + r});
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