#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<string> b(n);
	for(auto i = 0; i < n; ++ i){
		cin >> b[i];
	}
	vector<vector<int>> a(n - 1, vector<int>(m - 1));
	vector<vector<int>> pref(n, vector<int>(m));
	for(auto i = 0; i < n - 1; ++ i){
		for(auto j = 0; j < m - 1; ++ j){
			if(b[i + 1][j] == 'X' && b[i][j + 1] == 'X'){
				a[i][j] = 1;
			}
			pref[i + 1][j + 1] = a[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
		}
	}
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int yl, yr;
		cin >> yl >> yr, -- yl, -- yr;
		pref[0][yl] - pref[0][yr] - pref[n - 1][yl] + pref[n - 1][yr] ? cout << "NO\n" : cout << "YES\n";
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