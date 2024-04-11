#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, s, e;
lint x[5005], a[5005], b[5005], c[5005], d[5005];
lint dp[5005][5005];

int main(){
	cin >> n >> s >> e;
	for(int i=1; i<=n; i++) cin >> x[i];
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) cin >> b[i];
	for(int i=1; i<=n; i++) cin >> c[i];
	for(int i=1; i<=n; i++) cin >> d[i];
	for(int i=0; i<=n; i++){
		fill(dp[i], dp[i] + 5001, 1e18);
	}
	int pass = 0;
	if(s == 1) dp[1][1] = d[1], pass++;
	else if(e == 1) dp[1][1] = b[1], pass++;
	else dp[1][1] = d[1] + b[1];
	for(int i=2; i<n; i++){
		if(i == s){
			for(int j=0; j<=n; j++){
				if(j >= 1) dp[i][j] = min(dp[i][j], 
					dp[i-1][j] + c[i] + (x[i] - x[i-1]) * (2 * j - pass));

				if(j >= 2) dp[i][j] = min(dp[i][j], 
					dp[i-1][j-1] + d[i] + (x[i] - x[i-1]) * (2 * j - 2 - pass));

				if(2 * j - pass - 1 <= 0) dp[i][j] = 1e18;
			}
			pass++;
			continue;
		}
		else if(i == e){
			for(int j=0; j<=n; j++){
				if(j >= 1) dp[i][j] = min(dp[i][j],
					dp[i-1][j] + a[i] + (x[i] - x[i-1]) * (2 * j - pass));

				if(j >= 2) dp[i][j] = min(dp[i][j], 
					dp[i-1][j-1] + b[i] + (x[i] - x[i-1]) * (2 * j - 2 - pass));

				if(2 * j - pass - 1 <= 0) dp[i][j] = 1e18;
			}
			pass++;
			continue;
		}
		for(int j=0; j<=n; j++){
			if(j >= 2){
				lint cst = dp[i-1][j-1] + (x[i] - x[i-1]) * (2 * j - 2 - pass) + b[i] + d[i];
				dp[i][j] = min(dp[i][j], cst);
			}
			if(j >= 1 + (e < i)){
				lint cst1 = dp[i-1][j] + (x[i] - x[i-1]) * (2 * j - pass) + a[i] + d[i];
				dp[i][j] = min(dp[i][j], cst1);
			}
			if(j >= 1 + (s < i)){
				lint cst1 = dp[i-1][j] + (x[i] - x[i-1]) * (2 * j - pass) + b[i] + c[i];
				dp[i][j] = min(dp[i][j], cst1);
			}
			if(j >= 1){
				lint cst2 = dp[i-1][j+1] + (x[i] - x[i-1]) * (2 * j + 2 - pass) + c[i] + a[i];
				dp[i][j] = min(dp[i][j], cst2);
			}
			if(2 * j - pass <= 0) dp[i][j] = 1e18;
		}
	}
	if(s == n){
		cout << dp[n-1][1] + (x[n] - x[n-1]) + c[n];
	}
	else if(e == n){
		cout << dp[n-1][1] + (x[n] - x[n-1]) + a[n];
	}
	else{
		cout << dp[n-1][2] + (x[n] - x[n-1]) * 2 + a[n] + c[n];
	}
}