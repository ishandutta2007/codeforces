#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	vector<map<long long, int>> g(61);
	g[0].insert({{}, 0});
	function<int(int, long long)> grundy = [&](int x, long long s){
		if(g[x].count(s)){
			return g[x][s];
		}
		int found = 0;
		for(auto y = 1; y <= x; ++ y){
			if(~s & 1LL << y){
				found |= 1 << grundy(x - y, s | 1LL << y);
			}
		}
		return g[x][s] = __builtin_ffs(~found) - 1;
	};
	for(auto x = 1; x <= 60; ++ x){
		g[x].insert({0, grundy(x, 0)});
	}
	int n, res = 0;
	cin >> n;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		res ^= g[x][0];
	}
	res ? cout << "NO\n" : cout << "YES\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////