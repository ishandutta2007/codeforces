#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	if(n * k > n * (n - 1) / 2){
		cout << "-1\n";
		return 0;
	}
	cout << n * k << "\n";
	for(auto u = 0; u < n; ++ u){
		for(auto v = u + 1; v <= u + k; ++ v){
			cout << u + 1 << " " << v % n + 1 << "\n";
		}
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