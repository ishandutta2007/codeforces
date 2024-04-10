#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[105], c[105];
int dp[2][10005][105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}

	dp[0][0][0] = 1;
	for (int i=1; i<=100; i++) {
		auto ol = dp[1-i%2];
		auto nu = dp[i%2];

		memset(nu, 0, sizeof(dp[0]));

		for (int j=0; j<=10000; j++) {
			for (int l=0; l<=n; l++) {
				if (!ol[j][l])
					continue;
				for (int k=0; k<=c[i]; k++) {
					int& t = nu[j + k*i][l + k];
					t += ol[j][l];
					if (t >= 1000)
						t = 1000;
				}
			}
		}
	}

	int sol = 0;

	for (int j=0; j<=10000; j++) {
		for (int l=1; l<=n; l++) {
			if (dp[0][j][l] != 1)
				continue;

			// da li je taj nacin pomocu sve istih?
			int ok = j / l;
			if (c[ok] < l || j % l)
				continue;

			// komplement da li valja?
			int me = 0;
			for (int k=1; k<=100; k++)
				if (k != ok)
					me = max(me, c[k]);
			if (c[ok] * ok == j && me == n - c[ok])
				sol = n;
			else
				sol = max(sol, l);
		}
	}

	cout << sol << '\n';
}