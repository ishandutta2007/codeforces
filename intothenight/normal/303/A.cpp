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
	if(~n & 1){
		cout << "-1\n";
		return 0;
	}
	for(auto i = 0; i < 2; ++ i){
		for(auto i = 0; i < n; ++ i){
			cout << i << " ";
		}
		cout << "\n";
	}
	for(auto i = 0; i < n; ++ i){
		cout << (i << 1) % n << " ";
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