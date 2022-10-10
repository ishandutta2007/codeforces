#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, k, a, b, c, d;
	cin >> n >> k >> a >> b >> c >> d;
	if(k <= n || n == 4){
		cout << "-1\n";
		return 0;
	}
	vector<int> t;
	for(auto i = 1; i <= n; ++ i){
		if(i ^ a && i ^ b && i ^ c && i ^ d){
			t.push_back(i);
		}
	}
	cout << a << " " << c << " ";
	for(auto u: t){
		cout << u << " ";
	}
	cout << d << " " << b << "\n" << c << " " << a << " ";
	for(auto u: t){
		cout << u << " ";
	}
	cout << b << " " << d << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////