#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	auto query = [&](int u)->vector<int>{
		cout << "? " << u + 1 << endl;
		vector<int> dist(n);
		for(auto u = 0; u < n; ++ u){
			cin >> dist[u];
		}
		return dist;
	};
	auto answer = [&](const vector<array<int, 2>> &edges)->void{
		cout << "!\n";
		for(auto [u, v]: edges){
			cout << u + 1 << " " << v + 1 << "\n";
		}
	};
	auto dist = query(0);
	vector<array<int, 2>> res;
	array<vector<int>, 2> g{};
	for(auto u = 1; u < n; ++ u){
		if(dist[u] == 1){
			res.push_back({0, u});
		}
		g[dist[u] & 1].push_back(u);
	}
	for(auto u: g[(int)g[0].size() >= (int)g[1].size()]){
		auto dist = query(u);
		for(auto v = 0; v < n; ++ v){
			if(dist[v] == 1){
				res.push_back({min(u, v), max(u, v)});
			}
		}
	}
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	answer(res);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////