#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 1e5 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[maxn], p[maxn], x[maxn], y[maxn], t[maxn];
void solve() {
	int r, n;
	cin >> r >> n;
	x[0] = 1, y[0] = 1, t[0] = 0;
	for(int i = 1; i <= n; i++) cin >> t[i] >> x[i] >> y[i];
	dp[0] = 0;
	p[0] = 0;
	for(int i = 1; i <= n; i++) dp[i] = p[i] = -(1<<30);
	for(int i = 1; i <= n; i++) {
		dp[i] = -(1<<30);
		for(int j = i-1; j >= 0; j--) {
			if(t[i]-t[j] < 2*r) {
				if(abs(x[i]-x[j]) + abs(y[i]-y[j]) <= t[i]-t[j]) {
					dp[i] = max(dp[i], dp[j]+1);
				}
			} else {
				dp[i] = max(dp[i], p[j]+1);
				break;
			}
		}
		p[i] = max(p[i-1], dp[i]);
	}
	cout << p[n] << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
	solve();
}