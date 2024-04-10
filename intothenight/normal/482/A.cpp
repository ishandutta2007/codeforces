#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	for(auto x = 1; x <= n - k; ++ x){
		cout << x << " ";
	}
	int x = n - k;
	for(auto d = k, sign = 1; d >= 1; -- d, sign *= -1){
		x += sign * d;
		cout << x << " ";
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