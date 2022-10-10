#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i][0] >> a[i][1];
	}
	const int sz = 1e3;
	vector block(sz, vector<vector<int>>(sz));
	for(auto i = 0; i < n; ++ i){
		block[min(a[i][0] / sz, sz - 1)][min(a[i][1] / sz, sz - 1)].push_back(i);
	}
	vector<array<int, 2>> order;
	for(auto i = 0; i < sz; ++ i){
		int t = (int)order.size();
		for(auto j = 0; j < sz; ++ j){
			if(~i & 1){
				sort(block[i][j].begin(), block[i][j].end());
			}
			else{
				sort(block[i][j].rbegin(), block[i][j].rend());
			}
			if(!block[i][j].empty()){
				order.push_back({i, j});
			}
		}
		if(i & 1){
			reverse(order.begin() + t, order.end());
		}
	}
	for(auto [i, j]: order){
		for(auto ind: block[i][j]){
			cout << ind + 1 << " ";
		}
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////