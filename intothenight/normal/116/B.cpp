#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(auto &s: a){
		cin >> s;
	}
	int res = 0;
	static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(a[i][j] == 'W'){
				for(auto [dx, dy]: dr){
					int x = dx + i, y = dy + j;
					if(0 <= x && x < n && 0 <= y && y < m && a[x][y] == 'P'){
						++ res;
						goto done;
					}
				}
			}
			done:;
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