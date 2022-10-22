#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 998244353;
const int mn = 1e5+10;
ll a[mn];
ll dp[mn][5];
int main() {
	int n,i,j;
	string s,h="hard ";
	scanf("%d", &n);
	cin >> s;
	s = " " + s;
	for (i = 1; i <= n; i++)scanf("%lld", a + i);
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 4; j++) {
			if (s[i] == h[j]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i]);
				dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j]);
			}
			else dp[i][j] = min(dp[i][j], dp[i - 1][j]);
		}
	}
	ll ans = 0x3f3f3f3f3f3f3f3f;
	for (i = 0; i < 4; i++)ans = min(ans, dp[n][i]);
	printf("%lld", ans);
}