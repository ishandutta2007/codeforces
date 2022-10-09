// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
string s;
int c[20][20];
ll dp[1 << 20], cross[1 << 20];

void mn(ll& x, ll y) {
	x = min(x, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> s;
	for (int i=0; i<n-1; i++) {
		c[s[i] - 'a'][s[i+1] - 'a']++;
	}

	for (int mask=0; mask<(1<<m); mask++) {
		if (mask >= (1 << m) / 2) {
			cross[mask] = cross[(1 << m) - 1 - mask];
			continue;
		}
		// screw it mm 2**m
		for (int i=0; i<m; i++) {
			if (mask & (1 << i)) {
				for (int j=0; j<m; j++) {
					if (!(mask & (1 << j))) {
						cross[mask] += c[i][j];
						cross[mask] += c[j][i];
					}
				}
			}
		}
	}

	memset(dp, 63, sizeof dp);

	dp[0] = 0;
	for (int mask=0; mask<(1<<m); mask++) {
		for (int j=0; j<m; j++) {
			if (mask & (1 << j))
				continue;
			mn(dp[mask | (1 << j)], dp[mask] + cross[mask]);
		}
	}

	cout << dp[(1<<m)-1] << '\n';
}