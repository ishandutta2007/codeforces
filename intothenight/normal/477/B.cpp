#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	cout << k * (6 * n - 1) << "\n";
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < 3; ++ j){
			cout << (6 * (i + 1) - 1 - 2 * j) * k << " ";
		}
		cout << (6 * (i + 1) - 4) * k << "\n";
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