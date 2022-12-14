#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e9 + 7;
const int NS = (int)3004;
int T, N;
int a[NS];
int dp[NS][NS];

signed main(){
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 1; i <= N; ++i){
			cin >> a[i];
		}
		for(int i = 0; i <= N; ++i){
			for(int j = 0; j <= N; ++j){
				dp[i][j] = MOD;
			}
		}
		for(int i = 1; i <= N; ++i){
			dp[1][i] = 0;
		}
		for(int i = 2; i <= N; ++i){
			int cnt = 0;
			for(int j = i - 1; j >= 1; --j){
				if(j + a[j] >= i){
					dp[i][j + a[j]] = min(dp[i][j + a[j]], dp[j][i - 1] + cnt++);
				}
			}
			for(int j = i + 1; j <= N; ++j){
				dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			}
		}
		cout << dp[N][N] << '\n';
	}
	return 0;
}