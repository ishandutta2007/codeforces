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
	vector<array<int, 2>> p(n);
	set<array<int, 2>> appear;
	for(auto i = 0; i < n; ++ i){
		cin >> p[i][0] >> p[i][1];
		appear.insert(p[i]);
	}
	static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	deque<array<int, 2>> dq;
	map<array<int, 2>, array<int, 2>> root;
	for(auto [x, y]: p){
		for(auto [dx, dy]: dr){
			int nx = x + dx, ny = y + dy;
			if(!appear.contains({nx, ny})){
				dq.push_back({nx, ny});
				root[{nx, ny}] = {nx, ny};
			}
		}
	}
	while(!dq.empty()){
		auto [x, y] = dq.front();
		dq.pop_front();
		for(auto [dx, dy]: dr){
			int nx = x + dx, ny = y + dy;
			if(appear.contains({nx, ny}) && !root.contains({nx, ny})){
				root[{nx, ny}] = root[{x, y}];
				dq.push_back({nx, ny});
			}
		}
	}
	for(auto [x, y]: p){
		auto [rx, ry] = root[{x, y}];
		cout << rx << " " << ry << "\n";
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