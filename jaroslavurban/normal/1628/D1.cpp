#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
ll pm(ll a,ll b){return b?(b&1?a:1)*pm(a*a%mod,b/2)%mod:1;}
ll inv (ll x) {
    return pm(x, mod-2);
}

void ProGamerMove() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> dp(n + 3, vector<int>(n + 3, -1));
	dp[0][0] = 0;
	ll d2 = inv(2);
	function<int(int, int)> solvedp = [&] (int n, int m) {
		if (~dp[n][m]) return dp[n][m];
		if (!m) return dp[n][m] = 0;
		if (n == m) return dp[n][m] = m * ll(k) % mod;
		return dp[n][m] = (solvedp(n - 1, m) + solvedp(n - 1, m - 1)) * d2 % mod;
	};
	cout << solvedp(n, m) << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}