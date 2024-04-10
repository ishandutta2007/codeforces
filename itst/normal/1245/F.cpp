#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<cmath>
#include<cassert>
#include<algorithm>
using namespace std;

#define int long long
int T , L , R , dp[103][2][2];
int solve(int l , int r){
	if(l == -1) return 0;
	memset(dp , 0 , sizeof(dp));
	dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = dp[0][1][1] = 1;
	for(int i = 1 ; i <= 32 ; ++i){
		dp[i][0][0] = dp[i - 1][0][0] * 3;
		if(r >> (i - 1) & 1) dp[i][0][1] = dp[i - 1][0][0] * 2 + dp[i - 1][0][1];
		else dp[i][0][1] = dp[i - 1][0][1] * 2;
		if(l >> (i - 1) & 1) dp[i][1][0] = dp[i - 1][0][0] * 2 + dp[i - 1][1][0];
		else dp[i][1][0] = dp[i - 1][1][0] * 2;
		for(int p = 0 ; p <= 1 ; ++p)
			for(int q = 0 ; q <= 1 ; ++q)
				if(p + q < 2 && (p <= (l >> (i - 1) & 1)) && (q <= (r >> (i - 1) & 1))){
					int x = p ^ (l >> (i - 1) & 1) ^ 1 , y = q ^ (r >> (i - 1) & 1) ^ 1;
					dp[i][1][1] += dp[i - 1][x][y];
				}
	}
	return dp[32][1][1];
}

signed main(){
	for(cin >> T ; T ; --T){
		cin >> L >> R;
		cout << solve(R , R) - 2 * solve(L - 1 , R) + solve(L - 1 , L - 1) << endl;
	}
	return 0;
}