#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 105;
const int mod = 1e9+7;
ll n, m, k;

ll pow_mod(ll x, ll k) {
	ll ans = 1;
	while (k) {
		if (k&1) ans = ans * x % mod;
		x = x * x % mod;
		k >>= 1;
	}
	return ans;
}

void pp(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int c[N][N];

int dp[N][N * N];
int cnt[N][N];

int main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++) 
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++)
			cnt[i][j] = pow_mod(c[n][j], (m - i) / n + 1);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k && j <= i * n; j++) {
			if (dp[i][j] == 0) continue;
			for (int x = 0; x <= n; x++) {
				if (j + x > k) break;
				pp(dp[i + 1][j + x], 1ll * dp[i][j] * cnt[i + 1][x] % mod);
			}
		}
	}
	printf("%d\n", dp[n][k]);
	return 0;
}