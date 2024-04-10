#include<bits/stdc++.h>
using namespace std;

int dp[5003][5003] , TA[5003][26] , TB[5003][26] , LA , LB , ans = 0;
string SA , SB;

signed main(){
	cin >> LA >> LB >> SA >> SB; memset(dp , -0x3f , sizeof(dp));
	for(int i = LA - 2 ; ~i ; --i){
		memcpy(TA[i] , TA[i + 1] , sizeof(TA[i]));
		TA[i][SA[i + 1] - 'a'] = i + 1;
	}
	for(int i = LB - 2 ; ~i ; --i){
		memcpy(TB[i] , TB[i + 1] , sizeof(TB[i]));
		TB[i][SB[i + 1] - 'a'] = i + 1;
	}
	for(int i = 0 ; i < LA ; ++i)
		for(int j = 0 ; j < LB ; ++j)
			if(SA[i] == SB[j]){
				dp[i][j] = max(dp[i][j] , i - 1 + j - 1) + 4;
				ans = max(ans , dp[i][j] - i - j);
				for(int k = 0 ; k < 26 ; ++k)
					if(TA[i][k] && TB[j][k])
						dp[TA[i][k]][TB[j][k]] = max(dp[i][j] , dp[TA[i][k]][TB[j][k]]);
			}
	cout << ans;
	return 0;
}