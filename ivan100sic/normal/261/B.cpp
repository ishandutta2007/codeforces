#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, p;
int a[55];
ld dp[51][51][51][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cin >> p;
	
	ld e = 0, f = 0;
	dp[0][0][0][0] = 1;

	for (int i=0; i<n; i++) {
		for (int j=0; j<=i; j++) {
			for (int k=0; k<=50; k++) {
				for (int l=0; l<=50; l++) {
					dp[i+1][j+1][k][l+a[i]] += dp[i][j][k][l] * j / (i+2);
					dp[i+1][j+1][a[i]][l+k] += dp[i][j][k][l] / (i+2);
					dp[i+1][j][k][l] += dp[i][j][k][l] * (i+1-j) / (i+2);
				}
			}
		}
	}

	for (int j=0; j<=n; j++) {
		for (int k=0; k<=50; k++) {
			for (int l=0; l<=50; l++) {
				if (l <= p && l+k > p) {
					e += dp[n][j][k][l] * j;
					f += dp[n][j][k][l];
				}
			}
		}
	}

	if (f == 0)
		cout << n << '\n';
	else
		cout << setprecision(20) << fixed << e/f-1 << '\n';
}