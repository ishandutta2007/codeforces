#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	int dp[n + 1][10];
	for(int i = 0;i < n + 1;i++){
		for(int j = 0;j < 10;j++){
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		int a = -1,b = -1,c = -1, d = -1,e = -1;
		for(int i = 0;i < k;i++){
			int x, y;
			cin >> x >> y;
			if(x == 3){
				e = max(e, y);
			}
			if(x == 2){
				d = max(d, y);
			}
			if(x == 1){
				if(y >= a){
					c = b;
					b = a;
					a = y;
				}
				else if(y >= b){
					c = b;
					b = y;
				}
				else if(y >= c){
					c = y;
				}
			}
		}
		for(int j = 0;j < 10;j++){
			for(int g = 0;g < 10;g++){
				if(dp[i - 1][g] != -1){
				int z;
				if(j >= g){
					z = j - g;
				}
				else{
					z = 10 - g + j;
				}
				
				if(z == 0){
					dp[i][j] = max(dp[i][j], dp[i - 1][g]);
				}
				if(z == 1){
					if(a != -1){
						if(j == 0){
							dp[i][j] = max(dp[i][j], dp[i - 1][g] + a + a);
						}
						else{
							dp[i][j] = max(dp[i][j], dp[i - 1][g] + a);
						}
					}
					if(e != -1){
						if(j == 0){
							dp[i][j] = max(dp[i][j], dp[i - 1][g] + e + e);
						}
						else{
							dp[i][j] = max(dp[i][j], dp[i - 1][g] + e);
						}
					}
					if(d != -1){
						if(j == 0){
							dp[i][j] = max(dp[i][j], dp[i - 1][g] + d + d);
						}
						else{
							dp[i][j] = max(dp[i][j], dp[i - 1][g] + d);
						}
					}
				}
				if(z == 2){
					if(b != -1 && a != -1){
						if(j <= 1){
							dp[i][j] = max(dp[i][j], dp[i - 1][g] + max(a,b) + a + b);
						}
						else{
							dp[i][j] = max(dp[i][j], dp[i - 1][g] + a + b);
						}
					}
					if(d != -1 && a != -1){
						if(j <= 1){
							dp[i][j] = max(dp[i][j], dp[i - 1][g] + max(a,d) + a + d);
						}
						else{
							dp[i][j] = max(dp[i][j], dp[i - 1][g] + a + d);
						}
					}
				}
				if(z == 3){
					if(a != -1 && b != -1 && c != -1){
						if(j <= 2){
							dp[i][j] = max(dp[i][j], dp[i - 1][g] + a + a + b + c);
						}
						else{
							dp[i][j] = max(dp[i][j], dp[i - 1][g] + a + b + c);
						}
					}
					
					
				}
				}
			}
		}
		
	}
	int ans = 0;
	for(int i = 0;i < 10;i++){
		ans = max(ans, dp[n][i]);
	}
	cout << ans;
}