// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, h, l, r;
int a[2005];
int dp[2005][2005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> h >> l >> r;
	for (int i=0; i<n; i++)
		cin >> a[i];

	memset(dp, 128, sizeof dp);
	dp[0][0] = 0;

	for (int i=0; i<n; i++) {
		for (int j=0; j<h; j++) {
			for (int t=a[i]-1; t<=a[i]; t++) {
				int u = (j+t) % h;
				dp[i+1][u] = max(dp[i+1][u], dp[i][j] + (l <= u && u <= r));
			}
		}
	}
	cout << *max_element(dp[n], dp[n]+h) << '\n';
}

// I will still practice daily...