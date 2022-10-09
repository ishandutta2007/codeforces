#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, l, k;
double p[205];
int a[205];

double dp[201][201][401]; // mrzi me

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> l >> k;
	for (int i=0; i<n; i++) {
		cin >> p[i];
		p[i] /= 100;
	}

	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	dp[0][0][k + 200] = 1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<=i; j++) {
			for (int b=0; b<=400; b++) {
				if (a[i] == -1) {
					if (b > 0)
						dp[i+1][j+1][b-1] += dp[i][j][b] * p[i];
				} else {
					int bb = min(400, b + a[i]);
					dp[i+1][j+1][bb] += dp[i][j][b] * p[i];
				}
				dp[i+1][j][b] += dp[i][j][b] * (1 - p[i]);	
			}
		}
	}

	double sol = 0;
	for (int j=l; j<=n; j++) {
		for (int b=200; b<=400; b++) {
			sol += dp[n][j][b];
		}
	}

	cout << setprecision(20) << fixed << sol << '\n';

}