#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			cin >> a[i][j];
		}
	}
	for(auto j1 = 0; j1 < m; ++ j1){
		for(auto j2 = j1; j2 < m; ++ j2){
			for(auto i = 0; i < n; ++ i){
				swap(a[i][j1], a[i][j2]);
			}
			for(auto i = 0; i < n; ++ i){
				int cnt = 0;
				for(auto j = 0; j < m; ++ j){
					if(a[i][j] != j + 1){
						++ cnt;
					}
				}
				if(cnt > 2){
					goto FAIL;
				}
			}
			cout << "YES\n";
			return 0;
			FAIL:;
			for(auto i = 0; i < n; ++ i){
				swap(a[i][j1], a[i][j2]);
			}
		}
	}
	cout << "NO\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////