#include<bits/stdc++.h>
#define pb push_back
using namespace std;using ll = long long;
const int maxn = 1010, mod = 998244353 ;
int dp[maxn][2*maxn][4], n, k;
void add(int &a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	dp[1][1][3] = dp[1][1][0] = 1;
	dp[1][2][2] = dp[1][2][1] = 1;
	cin >> n >> k;
	#define popc __builtin_popcount
	for(int i = 1; i < n; i++) {
		for(int k = 1; k <= 2*n; k++) {
			for(int m = 0; m < 4; m++) { 
				add(dp[i+1][k + (popc(m)>0)][m], dp[i][k][0]);
				add(dp[i+1][k + (popc(3^m)>0)][m], dp[i][k][3]);
				add(dp[i+1][k + 2*((m^2) == 3)][m], dp[i][k][2]);
				add(dp[i+1][k + 2*((m^1) == 3)][m], dp[i][k][1]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 4; i++) add(ans, dp[n][k][i]);
	cout << ans << '\n';
}