#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	int k = *max_element(a.begin(), a.end());
	while(true){
		int p = 0, q = 0;
		for(auto x: a){
			p += k - x, q += x;
		}
		if(p > q){
			break;
		}
		++ k;
	}
	cout << k << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////