#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[2][100005];
ll dp[2][100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<2; i++)
		for (int j=1; j<=n; j++)
			cin >> a[i][j];

	ll sol = 0;

	for (int j=1; j<=n; j++) {
		for (int i=0; i<2; i++) {
			for (int k=1; k<6 && j-k>=1; k++) {
				dp[i][j] = max(dp[i][j], dp[i^1][j-k]);
			}
			sol = max(sol, dp[i][j] += a[i][j]);
		}
	}
	cout << sol << '\n';
}