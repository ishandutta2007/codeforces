#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> pv(n + 1, -1);
	vector<multiset<int, greater<>>> dp(n + 1, {0, 0});
	for(auto s = 1; s <= n; ++ s){
		cin >> pv[s], -- pv[s];
		for(auto u = pv[s], v = s; ~u; v = u, u = pv[u]){
			int cur_push = max(*dp[u].begin(), 1 + *next(dp[u].begin()));
			int pushed = max(*dp[v].begin(), 1 + *next(dp[v].begin()));
			if(auto it = dp[u].find(pushed - 1); it != dp[u].end()){
				dp[u].erase(it);
			}
			dp[u].insert(pushed);
			int new_push = max(*dp[u].begin(), 1 + *next(dp[u].begin()));
			if(cur_push == new_push){
				break;
			}
			assert(new_push == cur_push + 1);
		}
		cout << *dp[0].begin() << " ";
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