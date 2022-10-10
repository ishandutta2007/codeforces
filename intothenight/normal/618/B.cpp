#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < n; ++ j){
			cin >> a[i][j];
		}
	}
	vector<int> p(n, -1);
	for(auto x = 1; x <= n; ++ x){
		for(auto i = 0; i < n; ++ i){
			if(!~p[i] && *max_element(a[i].begin(), a[i].end()) <= x){
				p[i] = x;
				break;
			}
		}
	}
	for(auto x: p){
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