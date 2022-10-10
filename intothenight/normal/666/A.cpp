#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<array<bool, 2>> dp(n + 1);
	vector<string> res;
	if(n >= 7){
		dp[n - 2][0] = true;
		res.push_back(s.substr(n - 2, 2));
	}
	if(n >= 8){
		dp[n - 3][1] = true;
		res.push_back(s.substr(n - 3, 3));
	}
	for(auto i = n - 4; i >= 5; -- i){
		if(dp[i + 2][1] || dp[i + 2][0] && s.substr(i, 2) != s.substr(i + 2, 2)){
			dp[i][0] = true;
			res.push_back(s.substr(i, 2));
		}
		if(dp[i + 3][0] || dp[i + 3][1] && s.substr(i, 3) != s.substr(i + 3, 3)){
			dp[i][1] = true;
			res.push_back(s.substr(i, 3));
		}
	}
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	cout << (int)res.size() << "\n";
	for(auto s: res){
		cout << s << "\n";
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