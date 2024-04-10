#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];
int dp[200005][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int kk[4];
	cin >> kk[1] >> kk[2] >> kk[3];
	for (int i=1; i<=3; i++) {
		while (kk[i]--) {
			int x;
			cin >> x;
			a[x-1] = i;
			n++;
		}
	}

	memset(dp, 63, sizeof dp);

	dp[0][1] = 0;
	for (int i=0; i<n; i++) {
		for (int j=1; j<=3; j++) {
			for (int k=j; k<=3; k++) {
				dp[i+1][k] = min(dp[i+1][k], dp[i][j] + (a[i] != k));
			}
		}
	}

	cout << *min_element(dp[n]+1, dp[n]+4) << '\n';
}