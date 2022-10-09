#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s;
ll dp[100005][5];
ll a[100005];

ll& mx(ll& x, ll y) {
	x = min(x, y);
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	memset(dp, 63, sizeof(dp));
	cin >> n >> s;
	for (int i=0; i<n; i++)
		cin >> a[i];
	dp[0][0] = 0;
	for (int i=0; i<n; i++) {
		if (s[i] == 'h') {
			// brisem
			mx(dp[i+1][0], dp[i][0] + a[i]);
			// ne brisem
			mx(dp[i+1][1], dp[i][0]);
			mx(dp[i+1][1], dp[i][1]);
			mx(dp[i+1][2], dp[i][2]);
			mx(dp[i+1][3], dp[i][3]);
			mx(dp[i+1][4], dp[i][4]);
		} else if (s[i] == 'a') {
			mx(dp[i+1][1], dp[i][1] + a[i]);
			// ne brisem
			mx(dp[i+1][2], dp[i][1]);
			mx(dp[i+1][0], dp[i][0]);
			mx(dp[i+1][2], dp[i][2]);
			mx(dp[i+1][3], dp[i][3]);
			mx(dp[i+1][4], dp[i][4]);
		} else if (s[i] == 'r') {
			mx(dp[i+1][2], dp[i][2] + a[i]);

			mx(dp[i+1][3], dp[i][2]);
			mx(dp[i+1][0], dp[i][0]);
			mx(dp[i+1][1], dp[i][1]);
			mx(dp[i+1][3], dp[i][3]);
			mx(dp[i+1][4], dp[i][4]);
		} else if (s[i] == 'd') {
			mx(dp[i+1][3], dp[i][3] + a[i]);

			mx(dp[i+1][4], dp[i][3]);
			mx(dp[i+1][0], dp[i][0]);
			mx(dp[i+1][1], dp[i][1]);
			mx(dp[i+1][2], dp[i][2]);
			mx(dp[i+1][4], dp[i][4]);
		} else {
			mx(dp[i+1][0], dp[i][0]);
			mx(dp[i+1][1], dp[i][1]);
			mx(dp[i+1][2], dp[i][2]);
			mx(dp[i+1][3], dp[i][3]);
			mx(dp[i+1][4], dp[i][4]);
		}
	}

	ll sol = 1123123123123123123ll;
	for (int i=0; i<4; i++)
		sol = min(sol, dp[n][i]);
	cout << sol << '\n';
}