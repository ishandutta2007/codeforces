#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
int a[300005];
int dp[300005][20]; // najblizi broj pocev od broja x
// koji ima setovan y-ti bit
int seen[20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	memset(dp, 63, sizeof(dp));

	for (int i=n; i>=1; i--) {
		for (int j=0; j<20; j++) {
			if (a[i] & (1 << j)) {
				dp[i][j] = i;
			} else {
				for (int k=0; k<20; k++) {
					if ((a[i] & (1 << k)) && seen[k]) {
						dp[i][j] = min(dp[i][j], dp[seen[k]][j]);
					}
				}
			}
		}

		for (int j=0; j<20; j++) {
			if (a[i] & (1 << j)) {
				seen[j] = i;
			}
		}
	}

	while (q--) {
		int u, v, ok = 0;
		cin >> u >> v;
		for (int i=0; i<20; i++) {
			if (a[v] & (1 << i)) {
				if (dp[u][i] <= v) {
					ok = 1;
				}
			}
		}
		if (ok) {
			cout << "Shi\n";
		} else {
			cout << "Fou\n";
		}
	}
}