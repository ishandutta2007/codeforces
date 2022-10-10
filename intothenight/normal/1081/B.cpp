#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<vector<int>> a(n + 1);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		a[n - x].push_back(i);
	}
	vector<int> res(n);
	int t = 0;
	for(auto i = 1; i <= n; ++ i){
		if(int(a[i].size()) % i){
			cout << "Impossible";
			return 0;
		}
		for(auto j = 0; j < int(a[i].size()); ++ j){
			if(j % i == 0){
				++ t;
			}
			res[a[i][j]] = t;
		}
	}
	cout << "Possible\n";
	for(auto x: res){
		cout << x << " ";
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