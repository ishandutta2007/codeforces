#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 5005;
const int mod = 1e9 + 7;

int dp[MAXN][MAXN];
int n, a[MAXN];

int main(){
	cin >> n;
	if(n == 1){
		puts("0");
		return 0;
	}
	for(int i=1; i<=n; i++) cin >> a[i];
	a[0] = a[n+1] = -1e6;
	memset(dp, 0x3f, sizeof(dp));
	for(int i=1; i<=n; i++){
		dp[1][i] = max(a[i-1] - a[i] + 1, 0);
	}
	for(int i=2; i<=(n+1)/2; i++){
		int minv = 2e9;
		for(int j=1; j<=n; j++){
			if(j - 3 >= 1){
				minv = min(minv, dp[i-1][j-3] + max(a[j-2] - a[j-3] + 1, 0));
			}
			dp[i][j] = minv;
			dp[i][j] += max(a[j-1] - a[j] + 1, 0);
			if(j - 2 >= 1){
				dp[i][j] = min(dp[i][j], dp[i-1][j-2] + max(a[j-1] - min(a[j-2], a[j]) + 1, 0));
			}
		}
	}
	for(int i=1; i<=(n+1)/2; i++){
		int ans = 2e9;
		for(int j=1; j<=n; j++){
			ans = min(ans, dp[i][j] + max(a[j+1] - a[j] + 1, 0));
		}
		printf("%d ", ans);
	}
}