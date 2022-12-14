#include <bits/stdc++.h>

using namespace std;

int DP[2][404][404][9];

int main(){
	//int time = clock();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> c(26);
	for(int i = 0; i < 26; ++i){
		cin >> c[i];
	}
	const int mod = 998244353;
	vector<vector<int>> dp[2];
	dp[0] = dp[1] = vector<vector<int>>(n + 1, vector<int>(4));
	dp[0][0][0] = 1;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j <= n; ++j){
			for(int x = 0; x < 4; ++x){
				if(!(x & 1) && j + 1 <= n){
					dp[1][j + 1][(x >> 1) | 2] = (dp[1][j + 1][(x >> 1) | 2] + dp[0][j][x]) % mod;
				}
				if((x & 1) || i < 2){
					dp[1][j][x >> 1] = (dp[1][j][x >> 1] + (long long)dp[0][j][x] * 25) % mod;
				}
				else{
					dp[1][j][x >> 1] = (dp[1][j][x >> 1] + (long long)dp[0][j][x] * 24) % mod;
				}
				dp[0][j][x] = 0;
			}
		}
		swap(dp[0], dp[1]);
	}
	DP[0][0][0][0] = 1;
	int now = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j <= n; ++j){
			for(int k = 0; k <= n; ++k){
				for(int x = 0; x < 9; ++x){
					if(x % 3 != 1 && j + 1 <= n){
						DP[1 - now][j + 1][k][x / 3 + 3] = (DP[1 - now][j + 1][k][x / 3 + 3] + DP[now][j][k][x]) % mod;
					}
					if(x % 3 != 2 && k + 1 <= n){
						DP[1 - now][j][k + 1][x / 3 + 6] = (DP[1 - now][j][k + 1][x / 3 + 6] + DP[now][j][k][x]) % mod;
					}
					if(x % 3 || (i < 2)){
						DP[1 - now][j][k][x / 3] = (DP[1 - now][j][k][x / 3] + (long long)DP[now][j][k][x] * 24) % mod;
					}
					else{
						DP[1 - now][j][k][x / 3] = (DP[1 - now][j][k][x / 3] + (long long)DP[now][j][k][x] * 23) % mod;
					}
					DP[now][j][k][x] = 0;
				}
			}
		}
		now = 1 - now;
	}
	int ans = 26 * 26;
	for(int i = 2; i < n; ++i){
		ans = ((long long)ans * 25) % mod;
	}
	for(int i = 0; i < 26; ++i){
		for(int j = c[i] + 1; j <= n; ++j){
			for(int x = 0; x < 4; ++x){
				ans = (ans - dp[0][j][x] + mod) % mod;
			}
		}
	}
	vector<vector<int>> sum(n + 2, vector<int>(n + 2));
	for(int i = n; i >= 0; --i){
		for(int j = n; j >= 0; --j){
			for(int x = 0; x < 9; ++x){
				sum[i][j] += DP[now][i][j][x]; sum[i][j] %= mod;
			}
			sum[i][j] = (sum[i][j] + sum[i + 1][j]) % mod;
			sum[i][j] = (sum[i][j] + sum[i][j + 1]) % mod;
			sum[i][j] = (sum[i][j] - sum[i + 1][j + 1] + mod) % mod;
		}
	}
	for(int i = 0; i < 26; ++i){
		for(int j = i + 1; j < 26; ++j){
			ans = (ans + sum[c[i] + 1][c[j] + 1]) % mod;
		}
	}
	cout << ans << '\n';
	//cout << clock() - time;
	return 0;
}