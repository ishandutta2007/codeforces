#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	vector<vector<int>> res(n);
	for(auto i = 0; i < n; ++ i){
		res[i].resize(i + 1, -1);
	}
	for(auto i = 0; i < n; ++ i){
		int x = i, y = i;
		for(auto rep = 0; rep < a[i]; ++ rep){
			res[x][y] = a[i];
			if(y && !~res[x][y - 1]){
				-- y;
			}
			else{
				++ x;
			}
		}
	}
	for(auto x: res){
		for(auto y: x){
			cout << y << " ";
		}
		cout << "\n";
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