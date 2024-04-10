#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	int res = numeric_limits<int>::max();
	for(auto i = 0; i < m; ++ i){
		int l, r;
		cin >> l >> r, -- l;
		res = min(res, r - l);
	}
	cout << res << "\n";
	for(auto i = 0; i < n; ++ i){
		cout << i % res << " ";
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