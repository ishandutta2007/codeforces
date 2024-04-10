#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[16][10005];
int wmid[16][16], wcross[16][16]; // prvi, poslednji
int dp[65536][16];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> a[i][j];

	memset(wmid, 63, sizeof(wmid));
	memset(wcross, 63, sizeof(wcross));

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) 
			if (i != j) {
				for (int k=0; k<m; k++)
					wmid[i][j] = min(wmid[i][j], abs(a[i][k] - a[j][k]));
				for (int k=1; k<m; k++)
					wcross[i][j] = min(wcross[i][j], abs(a[i][k] - a[j][k-1]));
			}

	int sol = 0;

	if (n == 1) {
		sol = 1123123123;
		for (int i=1; i<m; i++)
			sol = min(sol, abs(a[0][i] - a[0][i-1]));
		cout << sol << '\n';
		return 0;
	}

	for (int b=0; b<n; b++) {
		memset(dp, 0, sizeof(dp));
		dp[1 << b][b] = 1123123123;
		for (int mask=0; mask<(1 << n); mask++) {
			for (int j=0; j<n; j++) {
				if (!(mask & (1 << j)))
					continue;
				for (int i=0; i<n; i++) {
					if (mask & (1 << i))
						continue;
					dp[mask + (1 << i)][i] = max(dp[mask + (1 << i)][i], 
						min(dp[mask][j], wmid[j][i]));
				}
			}
		}
		for (int e=0; e<n; e++) {
			if (e == b)
				continue;
			sol = max(sol, min(dp[(1 << n) - 1][e], wcross[b][e]));
		}
	}

	cout << sol << '\n';
}