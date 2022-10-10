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
	vector<vector<int>> reach(n, vector<int>(n));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < n; ++ j){
			if(gcd(a[i], a[j]) > 1){
				reach[i][j] = true;
			}
		}
	}
	vector left(n, vector<int>(n)), right(n, vector<int>(n));
	for(auto i = 0; i < n; ++ i){
		left[i][i] = right[i][i] = true;
	}
	for(auto len = 1; len < n; ++ len){
		for(auto i = len; i < n; ++ i){
			for(auto j = i - len; j < i; ++ j){
				if(reach[i][j] && left[j][i - len] && right[j][i - 1]){
					left[i][i - len] = true;
				}
			}
		}
		for(auto i = 0; i < n - len; ++ i){
			for(auto j = i + 1; j < n; ++ j){
				if(reach[i][j] && left[j][i + 1] && right[j][i + len]){
					right[i][i + len] = true;
				}
			}
		}
	}
	for(auto i = 0; i < n; ++ i){
		if(left[i][0] && right[i][n - 1]){
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////