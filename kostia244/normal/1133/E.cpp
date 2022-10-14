//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 5010;
using ld = long double;
int n, k, dp[maxn][maxn], a[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int j = 1;
		while(a[i]-a[j]>5)j++;
		for(int c = 1; c <= k; c++) {
			dp[i][c] = max(dp[i-1][c], (i-j+1)+dp[j-1][c-1]);
//			cout << i << " " << c << " " << dp[i][c] << "\n";
			ans = max(ans, dp[i][c]);
		}
	}
	cout << ans;
}