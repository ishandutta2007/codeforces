#include <bits/stdc++.h>
using namespace std;

// KRAJ TEMPLATE KODA

int n, k;
int a[5005], f[505], h[15];
int karta[100005], fav[100005];

int dp[505][5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;
	for (int i=1; i<=n*k; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++)
		cin >> f[i];
	for (int i=1; i<=k; i++)
		cin >> h[i];

	for (int i=1; i<=n*k; i++)
		karta[a[i]]++;
	for (int i=1; i<=n; i++)
		fav[f[i]]++;

	int sol = 0;

	for (int x=1; x<=100000; x++) {
		if (karta[x] > 0 && fav[x] > 0) {
			// rasporedi karte ljudima
			int m = karta[x];
			int v = fav[x];
			int mee = 0;

			for (int i=1; i<=v; i++) {
				for (int j=0; j<=m; j++) {
					dp[i][j] = 0;
					for (int t=0; t<=k; t++) {
						if (j-t < 0)
							continue;
						dp[i][j] = max(dp[i][j], dp[i-1][j-t] + h[t]);
					}
					if (i == v)
						mee = max(mee, dp[i][j]);
				}
			}

			// cerr << x << ' ' << mee << '\n';

			sol += mee;
		}
	}

	cout << sol << '\n';

}