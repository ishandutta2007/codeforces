#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")												
#pragma GCC optimize("rename-registers")									
#pragma GCC optimize("move-loop-invariants")								
#pragma GCC optimize("unswitch-loops")											
#pragma GCC optimize("function-sections")										
#pragma GCC optimize("data-sections")										
#pragma GCC optimize("branch-target-load-optimize")							
#pragma GCC optimize("branch-target-load-optimize2") 						
#pragma GCC optimize("btr-bb-exclusive")
#pragma comment(linker, "/stack:200000000")


#include <iostream>
#include <vector>	
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 998244353;
double eps = 1e-7;


int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(max(3, k + 1), vector<ll>(4)));
	dp[0][2][1] = dp[0][2][2] = dp[0][1][0] = dp[0][1][3] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j][0] += dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j - 1][3];
			dp[i][j][0] %= mod;
			dp[i][j][1] += dp[i - 1][j - 1][0] + dp[i - 1][j][1] + (j > 1 ? dp[i - 1][j - 2][2] : 0) + dp[i - 1][j - 1][3];
			dp[i][j][2] += dp[i - 1][j - 1][0] + (j > 1 ? dp[i - 1][j - 2][1] : 0) + dp[i - 1][j][2] + dp[i - 1][j - 1][3];
			dp[i][j][3] += dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j][3];
			dp[i][j][1] %= mod;
			dp[i][j][2] %= mod;
			dp[i][j][3] %= mod;
			//cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << " " << dp[i][j][2] << " " << dp[i][j][3] << endl;
		}
	}
	ll sum = (dp[n - 1][k][0] + dp[n - 1][k][1] + dp[n - 1][k][2] + dp[n - 1][k][3]) % mod;
	cout << sum << endl;
	//system("pause");
	return 0;
}