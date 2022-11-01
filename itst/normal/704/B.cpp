#include<bits/stdc++.h>
using namespace std;

const int _ = 5003;
int val[5][_] , N , s , e; long long dp[_][_];
void chkmin(long long &a , long long b){a = a < b ? a : b;}

int main(){
	scanf("%d %d %d" , &N , &s , &e); dp[0][0] = 1;
	for(int i = 0 ; i < 5 ; ++i)
		for(int j = 1 ; j <= N ; ++j) scanf("%d" , &val[i][j]);
	memset(dp , 0x3f , sizeof(dp)); dp[1][1] = -val[0][1] - val[0][1] + val[4][1] + val[2][1];
	int flg = s == 1 ? 1 : (e == 1 ? 2 : 0);
	for(int i = 2 ; i <= N - 1 ; ++i){
		for(int j = 1 ; j < i ; ++j)
			for(int p = i == e && !flg ; p < 2 - (i == e && flg) ; ++p)
				for(int q = i == s && !flg ; q < 2 - (i == s && flg) ; ++q)
					if((p + q + j - 1) && (i == e || flg != 1 || p + j - 1) && (i == s || flg != 2 || q + j - 1))
						chkmin(dp[i][j + p + q - 1] , dp[i - 1][j] + val[3 + p][i] + val[1 + q][i] + (p + q - 1) * -2 * val[0][i]);
		if(i == s) flg = flg ? 0 : 1; else if(i == e) flg = flg ? 0 : 2;
	}
	long long ans = dp[N - 1][1] + val[0][N] + val[0][N] + val[3][N] + val[1][N];
	if(s < e) ans -= 0ll + val[0][e] - val[0][s] + val[3][e] + val[2][s];
	else ans -= 0ll + val[0][s] - val[0][e] + val[4][e] + val[1][s];
	cout << ans; return 0;
}