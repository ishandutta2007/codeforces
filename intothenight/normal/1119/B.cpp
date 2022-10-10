#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, h;
	cin >> n >> h;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	for(auto k = 0; k < n; ++ k){
		vector<int> b = {a.begin(), a.begin() + k + 1};
		sort(b.rbegin(), b.rend());
		int ch = 0;
		for(auto i = 0; i < (int)b.size(); i += 2){
			ch += b[i];
		}
		if(h < ch){
			cout << k << "\n";
			return 0;
		}
	}
	cout << n << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////