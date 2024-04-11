#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 1000005;
const int mod = 1e9 + 7;

lint dp[MAXN][2];
int n;
lint A, B, C, D, a[MAXN];

int main(){
	cin >> n >> A >> B >> C >> D;
	for(int i=0; i<n; i++) scanf("%lld",&a[i]);
	int i = n - 1;
	dp[n - 1][1] = min(min(A * (a[i] + 1), B) + 2 * D + A, 1ll * A * a[i] + C);
	dp[n - 1][0] = min(min(A * (a[i] + 1), B) + 2 * D + 2 * A, 1ll * A * a[i] + C + D + A);
	for(int i=n-2; i>=0; i--){
		dp[i][0] = dp[i][1] = 1e18;
		dp[i][0] = min(dp[i][0], min(A * (a[i] + 1), B) + 3 * D + 2 * A + dp[i + 1][1]);
		dp[i][0] = min(dp[i][0], 1ll * A * a[i] + 3 * D + A + C + dp[i + 1][1]);
		dp[i][1] = min(dp[i][1], min(A * (a[i] + 1), B) + D + dp[i + 1][0]);
		dp[i][1] = min(dp[i][1], 1ll * A * a[i] + C + D + dp[i + 1][1]);
	}
	cout << dp[0][1] << endl;
}