#include<bits/stdc++.h>
using namespace std;

int dp[503][503]; char str[503]; int N;

int main(){
	scanf("%d %s" , &N , str + 1);
	for(int i = N ; i ; --i)
		for(int j = i ; j <= N ; ++j){
			dp[i][j] = 1e9;
			for(int k = i ; k <= j ; ++k)
				if(str[i] == str[k])
					dp[i][j] = min(dp[i][j] , dp[k + (i == k)][j] + dp[i + 1][k - 1] + (i == k));
		}
	cout << dp[1][N];
	return 0;
}