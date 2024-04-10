// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n, k;
ll d[80][80], dp[11][80];
int c[80];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> d[i][j];
		}
	}

	int rep = 10000;
	ll sol = 1e18;
	while (rep--) {
		for (int i=0; i<n; i++) {
			c[i] = uniform_int_distribution<int>(0, 1)(eng);
		}

		memset(dp, 63, sizeof dp);
		dp[0][0] = 0;
		for (int t=0; t<k; t++) {
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					if (c[i] != c[j]) {
						dp[t+1][j] = min(dp[t+1][j], dp[t][i] + d[i][j]);
					}
				}
			}
		}
		sol = min(sol, dp[k][0]);
	}

	cout << sol << '\n';
}