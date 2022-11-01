#include<bits/stdc++.h>
using namespace std;

int T; string s; int dp[100003][2][2];

int main(){
	for(cin >> T ; T ; --T){
		cin >> s; s = " " + s; int L = s.size();
		for(int i = 1 ; i < L ; ++i) for(int j = 0 ; j < 2 ; ++j) for(int k = 0 ; k < 2 ; ++k) dp[i][j][k] = 1e9;
		dp[1][0][0] = 0; dp[1][0][1] = 1; 
		for(int i = 2 ; i < L ; ++i)
			for(int j = 0 ; j < 2 ; ++j)
				for(int k = 0 ; k < 2 ; ++k)
					for(int l = 0 ; l < 2 ; ++l)
						if((j || l || s[i - 2] != s[i]) && (k || l || s[i - 1] != s[i]))
							dp[i][k][l] = min(dp[i][k][l] , dp[i - 1][j][k] + l);
		int ans = 1e9;
		for(int i = 0 ; i < 2 ; ++i) for(int j = 0 ; j < 2 ; ++j) ans = min(ans , dp[L - 1][i][j]);
		cout << ans << endl;
	}
	return 0;
}