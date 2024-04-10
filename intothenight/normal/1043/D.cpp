#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(m, vector<int>(n)), pos(m, vector<int>(n));
	for(auto i = 0; i < m; ++ i){
		for(auto j = 0; j < n; ++ j){
			cin >> a[i][j], -- a[i][j];
			pos[i][a[i][j]] = j;
		}
	}
	vector<int> dp(n);
	dp[0] = 1;
	for(auto i = 1; i < n; ++ i){
		bool ok = true;
		for(auto j = 1; j < m; ++ j){
			if(pos[j][a[0][i - 1]] + 1 != pos[j][a[0][i]]){
				ok = false;
				break;
			}
		}
		dp[i] = ok ? dp[i - 1] + 1 : 1;
	}
	cout << accumulate(dp.begin(), dp.end(), 0LL) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////