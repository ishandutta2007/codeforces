#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	const int mx = 502;
	const int mxval = 1 << 10;
	vector<bitset<mxval>> dp(mx);
	for(auto x = 0; x < mx; ++ x){
		dp[x].set(0);
	}
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		for(auto y = 0; y < mx; ++ y){
			if(dp[x][y]){
				dp[x + 1].set(x ^ y);
			}
		}
		for(auto y = x + 2; y < mx; ++ y){
			dp[y] |= dp[y - 1];
		}
	}
	vector<int> res;
	for(auto x = 0; x < mxval; ++ x){
		for(auto y = 0; y < mx; ++ y){
			if(dp[y][x]){
				res.push_back(x);
				break;
			}
		}
	}
	cout << (int)res.size() << "\n";
	for(auto x: res){
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