#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 2e3 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll inf = 1ll<<60;
int n, k;
ll to[maxn][maxn], lo[maxn][maxn], can[maxn][maxn];
ll a[maxn], l[maxn], r[maxn];
ll dp[maxn];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> l[i] >> r[i] >> a[i];
    for(int i = 1; i <= n; i++) {
		ll cur = k, mag = 0, dead = 0;
		for(int j = i; j <= n; j++) {
			ll t = min(a[j], cur);
			a[j] -= t;
			cur -= t;
			ll rel = 0;
			if(!cur) {
				rel = (a[j]+k-1)/k;
				mag += rel;
				cur = (k - a[j]%k)%k;
			}
			a[j] += t;
			to[i][j] = mag;
			lo[i][j] = cur;
			//cout << i << " " << j << " " << lo[i][j] << endl;
			dead |= r[j]-l[j] < rel;
			can[i][j] = (j == n || r[j]!=l[j+1] || rel < r[j]-l[j]) && !dead;
		}
	}
	memset(dp, 0x0f, sizeof dp);
	dp[0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j <= n; j++) if(can[i+1][j]) {
			dp[j] = min(dp[j], dp[i] + to[i+1][j]*k + k - (j==n)*lo[i+1][j]);
			
		}
	}
	if(dp[n] == dp[n+1]) cout << -1;
	else cout << dp[n] << '\n';
}