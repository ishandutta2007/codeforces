#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n;
lint dp[100005][5]; 
int a[3][100005];

int main(){
	cin >> n;
	for(int i=0; i<3; i++){
		for(int j=1; j<=n; j++) scanf("%d",&a[i][j]);
	}
	fill(dp[0] + 1, dp[0] + 5, -1e18);
	for(int i=1; i<=n; i++){
		fill(dp[i], dp[i] + 5, -1e18);
		dp[i][0] = max({dp[i-1][0] + a[0][i], 
				dp[i-1][1] + a[0][i] + a[1][i], 
				dp[i-1][2] + a[0][i] + a[1][i] + a[2][i],
				dp[i-1][4] + a[0][i] + a[1][i] + a[2][i]});
		dp[i][1] = max({dp[i-1][0] + a[0][i] + a[1][i],
				dp[i-1][1] + a[1][i],
				dp[i-1][2] + a[2][i] + a[1][i]});
		dp[i][2] = max({dp[i-1][0] + a[0][i] + a[1][i] + a[2][i],
				dp[i-1][1] + a[1][i] + a[2][i], 
				dp[i-1][2] + a[2][i],
				dp[i-1][3] + a[0][i] + a[1][i] + a[2][i]});
		dp[i][3] = max({dp[i-1][3] + a[0][i] + a[1][i] + a[2][i],
				dp[i-1][0] + a[0][i] + a[1][i] + a[2][i]});
		dp[i][4] = max({dp[i-1][4] + a[0][i] + a[1][i] + a[2][i],
				dp[i-1][2] + a[0][i] + a[1][i] + a[2][i]});
	}
	cout << dp[n][2];
}