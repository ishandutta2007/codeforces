#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> t(n);
	for(auto i = 0; i < n; ++ i){
		cin >> t[i];
	}
	function<vector<pair<int, int>>(int)> draw = [&](int i){
		if(i == n){
			return vector<pair<int, int>>{};
		}
		vector<pair<int, int>> res;
		if(i & 1){
			for(auto x = 0; x < t[i]; ++ x){
				res.push_back({x, x});
			}
			for(auto [x, y]: draw(i + 1)){
				res.push_back({x + t[i], y + t[i] - 1});
				res.push_back({y + t[i] - 1, x + t[i]});
			}
		}
		else{
			for(auto x = 0; x < t[i]; ++ x){
				res.push_back({x, 0});
			}
			for(auto [x, y]: draw(i + 1)){
				res.push_back({x + t[i], y + 1});
				res.push_back({x + t[i], -y - 1});
			}
		}
		sort(res.begin(), res.end()), res.erase(unique(res.begin(), res.end()), res.end());
		return res;
	};
	cout << (int)draw(0).size() << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////