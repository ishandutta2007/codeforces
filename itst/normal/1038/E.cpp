#include<bits/stdc++.h>
using namespace std;

int dp[101][101][5][5] , l[101] , r[101] , w[101];

int main(){
	int N;
	cin >> N;
	for(int i = 1 ; i <= N ; i++)
		cin >> l[i] >> w[i] >> r[i];
	memset(dp , -0x3f , sizeof(dp));
	for(int i = 1 ; i <= N ; i++)
		dp[i][i][l[i]][r[i]] = dp[i][i][r[i]][l[i]] = w[i];
	for(int i = N - 1 ; i ; i--)
		for(int j = i + 1 ; j <= N ; j++)
			for(int p = 1 ; p <= 4 ; p++)
				for(int q = 1 ; q <= 4 ; q++)
					for(int k = i ; k < j ; k++){
						dp[i][j][p][q] = max(dp[i][j][p][q] , max(dp[i][k][p][q] , dp[k + 1][j][p][q]));
						for(int l = 1 ; l <= 4 ; l++)
							dp[i][j][p][q] = max(dp[i][j][p][q] , max(dp[i][k][p][l] + dp[k + 1][j][l][q] , dp[i][k][l][q] + dp[k + 1][j][p][l]));
					}
	int all = 0;
	for(int i = 1 ; i <= 4 ; i++)
		for(int j = 1 ; j <= 4 ; j++)
			all = max(all , dp[1][N][i][j]);
	cout << all;
	return 0;
}