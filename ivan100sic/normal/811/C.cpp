#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];
int dp[5005];

int u[5005], van[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		van[a[i]]++;
	}

	for (int i=1; i<=n; i++) {

		int losi = 0, xr = 0;

		for (int j=i; j>=0; j--) {
			if (losi == 0) {
				dp[i] = max(dp[i], dp[j] + xr);
			}

			if (j == 0) {
				break;
			}

			int x = a[j];

			if (van[x] && u[x]) {
				losi--;
			}

			van[x]--;
			u[x]++;

			if (u[x] == 1) {
				xr ^= x;
			}

			if (van[x] && u[x]) {
				losi++;
			}
		}

		for (int j=1; j<=i; j++) {
			van[a[j]]++;
			u[a[j]]--;
		}

		dp[i] = max(dp[i], dp[i-1]);

		// cerr << i << ' ' << dp[i] << '\n';
	}

	cout << dp[n];


}