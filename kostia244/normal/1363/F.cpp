#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 2018, rt = 1<<10;
int dp[maxn][maxn];
int ca[maxn][26], cb[maxn][26];
void solve() {
	string a, b;
	string ta, tb;
	int n;
	cin >> n >> a >> b;
	ta = a, sort(all(ta));
	tb = b, sort(all(tb));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 26; j++)
			ca[i][j] = (i?ca[i-1][j]:0) + ((a[i]-'a') == j);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 26; j++)
			cb[i][j] = (i?cb[i-1][j]:0) + ((b[i]-'a') == j);
	if(ta != tb) { cout << "-1\n"; return; }
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++) dp[i][j] = 1<<30;
	dp[0][0] = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; i+j <= n; j++) {
			if(dp[i][j] == 1<<30) continue;
			int pos = i + j;
			if(j && pos && (i?ca[i-1][a[i]-'a']:0) < cb[pos-1][a[i]-'a']) dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j]);
			if(a[i] == b[pos]) dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
		}
	cout << dp[n][0] << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}