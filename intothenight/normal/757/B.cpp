#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	const int mx = 1e5;
	vector<int> cnt(mx + 1);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		++ cnt[x];
	}
	vector<int> g(mx + 1);
	for(auto x = 1; x <= mx; ++ x){
		for(auto y = x; y <= mx; y += x){
			g[x] += cnt[y];
		}
	}
	g[1] = 1;
	cout << *max_element(g.begin(), g.end()) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////