#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	map<int, int> cntx, cnty;
	map<array<int, 2>, int> cntxy;
	for(auto i = 0; i < n; ++ i){
		int x, y;
		cin >> x >> y;
		++ cntx[x], ++ cnty[y], ++ cntxy[{x, y}];
	}
	long long res = 0;
	for(auto [ignore, c]: cntx){
		res += 1LL * c * (c - 1) / 2;
	}
	for(auto [ignore, c]: cnty){
		res += 1LL * c * (c - 1) / 2;
	}
	for(auto [ignore, c]: cntxy){
		res -= 1LL * c * (c - 1) / 2;
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////