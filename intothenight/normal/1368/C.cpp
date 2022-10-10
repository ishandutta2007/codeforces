#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	cout << 4 + 3 * n << "\n";
	for(auto x = 0; x < 2; ++ x){
		for(auto y = 0; y < 2; ++ y){
			cout << x << " " << y << "\n";
		}
	}
	for(auto i = 1; i <= n; ++ i){
		for(auto x = 0; x < 2; ++ x){
			for(auto y = 0; y < 2; ++ y){
				if(x || y){
					cout << i + x << " " << i + y << "\n";
				}
			}
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