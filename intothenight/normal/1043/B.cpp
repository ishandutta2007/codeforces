#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(auto i = 1; i <= n; ++ i){
		cin >> a[i];
	}
	vector<int> res;
	for(auto k = 1; k <= n; ++ k){
		bool ok = true;
		for(auto i = k; i < n; ++ i){
			if(a[i + 1] - a[i] != a[i + 1 - k] - a[i - k]){
				ok = false;
				break;
			}
		}
		if(ok){
			res.push_back(k);
		}
	}
	cout << int(res.size()) << "\n";
	for(auto k: res){
		cout << k << " ";
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