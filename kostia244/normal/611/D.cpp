#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 5050, mod = 1e9 + 7;
using ll = long long;
int dp[maxn][maxn], fi[maxn][maxn];
string s;
void add(int &a, int b) {
	a = a+b>=mod?a+b-mod:a+b;
}
bool lesss(int x, int y, int l) {
	int f = fi[x][y];
	if(f >= l) return 0;
	return s[x+f] < s[y+f];
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n >> s;
	dp[0][0] = 1;
	for(int i = n; i--;)
		for(int j = n; j-- > i;) {
			if(s[i] == s[j]) fi[i][j] = 1+fi[i+1][j+1];
			else fi[i][j] = 0;
			fi[j][i] = fi[i][j];
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			add(dp[i+1][j+1], dp[i][j]);
			if(j && i-j >= 0 && i+j <= n) {
			if(lesss(i-j, i, j))
				add(dp[i+j][j], dp[i][j]*(s[i]!='0' && s[i-j]!='0'));
			else
				add(dp[i+j+1][j+1], dp[i][j]*(s[i]!='0' && s[i-j]!='0'));
			}
			//cout << i << " " << j << " " << dp[i][j] << endl;
		}
	int ans = 0;
	for(int i = 1; i <= n; i++) add(ans, dp[n][i]);
	cout << ans << '\n';
}