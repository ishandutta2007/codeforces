#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 111, mod = 1e9 + 7;
using state = array<array<int, 111>, 111>;
state dp, ans;
int n, t, a[maxn];
void upd(state &dp) {
	for(int i = maxn-1; i--;)
		for(int j = 0; j < maxn; j++)
			dp[i][j] = max(dp[i][j], dp[i+1][j]);
	for(int i = 0; i < maxn; i++)
		for(int j = 1; j < maxn; j++)
			dp[i][j] = max(dp[i][j], dp[i][j-1]);
}
state merge(state a, state b) {
	upd(b);
	state res;
	for(int x = 0; x < maxn; x++)
		for(int y = 0; y < maxn; y++)
			res[x][y] = max(a[x][y], b[x][y]);
	for(int x = 0; x < maxn; x++)
		for(int y = x; y < maxn; y++)
			for(int z = y; z < maxn; z++)
					res[x][z] = max(res[x][z], a[x][y]+b[y][z]);
	upd(res);
	return res;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> t;
	vector<int> b {0};
	for(int i = 0; i < n; i++) cin >> a[i], b.push_back(a[i]);
	sort(all(b));
	for(int i = 0; i < n; i++) a[i] = lower_bound(all(b), a[i])-b.begin();
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			dp[i][j] = 0;
	ans = dp;
	for(int I = 0; I < n; I++) {
		int i = a[I];
		state ndp = dp;
		for(int x = 0; x <= i; x++)
			for(int y = 0; y <= i; y++)
					ndp[x][i] = max(ndp[x][i], dp[x][y] + 1);
		dp = ndp;
		upd(ndp);
	}
	while(t) {
		if(t&1) ans = merge(ans, dp);
		dp = merge(dp, dp), t>>=1;
	}
	cout << ans[0][maxn-1];
}