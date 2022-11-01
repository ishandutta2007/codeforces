#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7 , MOD = 1e9 + 7;
void inc(int &a , int b){a = (a + b) % MOD;}
int dp[_][2][2][2] , N , P , col[_];

int main(){
	cin >> N >> P; for(int i = 1 ; i <= N ; ++i) cin >> col[i];
	if(col[1] != 1) dp[1][1][0][1] = 1;
	if(col[1] != 0) dp[1][0][1][1] = 1;
	int tms = 1;
	for(int i = 2 ; i <= N ; ++i , tms = (tms * 2) % MOD)
		for(int j = 0 ; j < 2 ; ++j)
			for(int k = 0 ; k < 2 ; ++k)
				for(int l = 0 ; l < 2 ; ++l){
					int val = 1ll * dp[i - 1][j][k][l] * tms % MOD;
					if(col[i] != 1){
						inc(dp[i][1][k][l ^ 1] , val); inc(dp[i][j | !k][k][l ^ !k] , val);
					}
					if(col[i] != 0){
						inc(dp[i][j][1][l ^ 1] , val); inc(dp[i][j][k | !j][l ^ !j] , val);
					}
				}
	
	int sum = 0;
	for(int i = 0 ; i < 2 ; ++i) for(int j = 0 ; j < 2 ; ++j) inc(sum , dp[N][i][j][P]);
	cout << sum; return 0;
}