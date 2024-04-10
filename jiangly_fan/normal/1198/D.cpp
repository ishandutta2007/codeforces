//Author: HeXun
//Date: 07-30-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 51;
char s[maxn][maxn];
int sum[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> (s[i] + 1);
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= n; j += 1) sum[i][j] = sum[i][j - 1] + (s[i][j] == '#');
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= n; j += 1)
			sum[i][j] += sum[i - 1][j];
	for(int h = 1; h <= n; h += 1)
		for(int w = 1; w <= n; w += 1)
			for(int i = 1; i + h - 1 <= n; i += 1)
				for(int j = 1; j + w - 1 <= n; j += 1){
					if(sum[i + h - 1][j + w - 1] - sum[i + h - 1][j - 1] - sum[i - 1][j + w - 1]
						+ sum[i - 1][j - 1] == 0) dp[i][j][i + h - 1][j + w - 1] = 0;
					else{
						dp[i][j][i + h - 1][j + w - 1] = max(h, w);
						for(int k = 1; k < h; k += 1)
							dp[i][j][i + h - 1][j + w - 1]
								= min(dp[i][j][i + h - 1][j + w - 1], dp[i][j][i + k - 1][j + w - 1]
									+ dp[i + k][j][i + h - 1][j + w - 1]);
						for(int k = 1; k < w; k += 1)
							dp[i][j][i + h - 1][j + w - 1]
								= min(dp[i][j][i + h - 1][j + w - 1], dp[i][j][i + h - 1][j + k - 1]
									+ dp[i][j + k][i + h - 1][j + w - 1]);
						
					}
					//cout << i << " " << j << " " << i + h - 1 << " " << j + w - 1 << " " << dp[i][j][i + h - 1][j + w - 1] << "\n";
				}
	cout << dp[1][1][n][n];
	return 0;
}