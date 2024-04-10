#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n << 1);
	for(auto i = 0; i < n << 1; ++ i){
		cin >> a[i];
	}
	int res = 0;
	for(auto i = 0; i < n << 1; i += 2){
		int j = i + 1;
		while(a[i] != a[j]){
			++ j;
		}
		for(auto k = j; k >= i + 2; -- k){
			swap(a[k], a[k - 1]);
			++ res;
		}
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