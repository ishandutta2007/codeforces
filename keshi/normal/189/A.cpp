#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, dp[9000];

int main(){
	cin >> n >> a >> b >> c;
	dp[a] = 1;
	dp[b] = 1;
	dp[c] = 1;
	for(int i = 1; i <= n; i++){
		if(dp[i]){
			dp[a + i] = max(dp[a + i], dp[i] + 1);
			dp[b + i] = max(dp[b + i], dp[i] + 1);
			dp[c + i] = max(dp[c + i], dp[i] + 1);
		}
	}
	cout << dp[n];
	return 0;
}