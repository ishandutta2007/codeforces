#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rnd(n) fixed << setprecision(n)

const int mod = 998244353, mod2 = 1e+7;

ll n, m, k;
ll dp[2010][2010];

int main(){
    IOS;
	cin >> n >> m >> k;
	dp[1][0] = m;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!dp[i][j]) {
				continue;
			}
			dp[i + 1][j] += dp[i][j];
			dp[i + 1][j] %= mod;
			dp[i + 1][j + 1] += dp[i][j] * (m - 1);
			dp[i + 1][j + 1] %= mod;
		}
	}
	cout << dp[n][k] << endl;
    return 0;
}