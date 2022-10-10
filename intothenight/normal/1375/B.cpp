#include "bits/stdc++.h"
using namespace std;



int solve_testcase(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			cin >> a[i][j];
		}
	}
	if(a[0][0] > 2 || a[0][m - 1] > 2 || a[n - 1][0] > 2 || a[n - 1][m - 1] > 2){
		cout << "NO\n";
		return 0;
	}
	a[0][0] = a[0][m - 1] = a[n - 1][0] = a[n - 1][m - 1] = 2;
	for(auto i = 1; i < n - 1; ++ i){
		if(a[i][0] > 3 || a[i][m - 1] > 3){
			cout << "NO\n";
			return 0;
		}
		a[i][0] = a[i][m - 1] = 3;
	}
	for(auto j = 1; j < m - 1; ++ j){
		if(a[0][j] > 3 || a[n - 1][j] > 3){
			cout << "NO\n";
			return 0;
		}
		a[0][j] = a[n - 1][j] = 3;
	}
	for(auto i = 1; i < n - 1; ++ i){
		for(auto j = 1; j < m - 1; ++ j){
			if(a[i][j] > 4){
				cout << "NO\n";
				return 0;
			}
			a[i][j] = 4;
		}
	}
	cout << "YES\n";
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		solve_testcase();
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