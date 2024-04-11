#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
int n, m, s, k, a[2004], b[2004], jump[2004], dp[1600][1600];
vi a_s;
bool can(int x) {
	memset(dp, 0, sizeof dp);
	for(int i = 1; i <= n; i++)
		b[i] = b[i-1] + (a[i]<=x);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
		    if(jump[i]!=n)
			dp[i][j] = max(dp[i-1][j], dp[jump[i]][j-1]+b[i]-b[jump[i]]);
			else
			dp[i][j] = dp[i-1][j];
// 			cout << i << " " << j << " " << jump[i] << "\n";
		}
// 		cout << jump[i] << " ";
		ans = max(ans, dp[i][m]);
	}
// 	cout << "\n";
// 	cout << x << " " << ans << "\n";
	return ans>=k;
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> s >> m >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i], a_s.pb(a[i]);
	sort(all(a_s));
	for(int i = 1; i <= n; i++) jump[i] = n+1;
	for(int t, l, r, i = 0; i < s; i++) {
		cin >> l >> r;
		t=l;
		for(;l<=r;l++) jump[l] = min(jump[l], t);
	}
	for(int i = 1; i <= n; i++) jump[i]--;
	int ans = 0;
	if(!can(a_s.back())) return cout << -1, 0;
	if(can(a_s[0])) return cout << a_s[0], 0;
	for(int x=1<<10;x;x>>=1)
		if(ans+x<n&&!can(a_s[ans+x])) ans += x;
    cout << a_s[ans+1];
}