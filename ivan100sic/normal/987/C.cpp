#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int s[3005], c[3005];

int dp[3005][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> s[i];
	for (int i=1; i<=n; i++)
		cin >> c[i];

	int sol = 1132123123;

	for (int i=1; i<=n; i++) {
		dp[i][1] = c[i];
		for (int j=2; j<=3; j++) {
			dp[i][j] = 1123123123;
			for (int k=1; k<i; k++) {
				if (s[k] < s[i])
					dp[i][j] = min(dp[i][j], dp[k][j-1] + c[i]);
			}
		}
		sol = min(sol, dp[i][3]);
	}

	if (sol == 1123123123)
		sol = -1;
	cout << sol << '\n';
}