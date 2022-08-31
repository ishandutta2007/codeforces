#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55;
using lint = long long;
using pi = pair<int, int>;

int n, k;
lint a[MAXN];
bool dp[MAXN][MAXN];

bool ok(lint x){
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i=1; i<=k; i++){
		for(int j=1; j<=n; j++){
			for(int k=0; k<j; k++){
				if(((a[j] - a[k]) & x) == x){
					dp[i][j] |= dp[i-1][k];
				}
			}
		}
	}
	return dp[k][n];
}

int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	lint ans = 0;
	for(int i=59; i>=0; i--){
		if(ok(ans | (1ll << i))) ans |= (1ll << i);
	}
	cout << ans << endl;
}