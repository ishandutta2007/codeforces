#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 123123123;

int n, k, m, s;
int a[1505], x[1505];
int z[1505];

int minL[1505];

//     broj     R
int dp[1505][1505];
int pm[1505][1505];

int b[4096];
const int H = 2048;

void sett(int x, int v) {
	x += H;
	b[x] = v;
	while (x > 1) {
		x >>= 1;
		b[x] = max(b[2*x], b[2*x+1]);
	}
}

int gett(int l, int r, int x=1, int xl=0, int xr=H-1) {
	if (r < xl || xr < l) return -INF;
	if (l <= xl && xr <= r) return b[x];
	int xm = (xl+xr) >> 1;
	return max(gett(l, r, 2*x, xl, xm), gett(l, r, 2*x+1, xm+1, xr));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s >> m >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		minL[i] = INF;
	}

	for (int i=0; i<s; i++) {
		int l, r;
		cin >> l >> r;
		minL[r] = min(minL[r], l);
	}

	copy(a+1, a+n+1, x);
	sort(x, x+n);

	int l = 0, r = n-1, o = -1;
	while (l <= r) {
		int mid = (l+r) >> 1;
		for (int i=1; i<=n; i++)
			z[i] = z[i-1] + (a[i] <= x[mid]);

		memset(dp, 0, sizeof(dp));
		for (int i=1; i<=n; i++)
			sett(i, -INF);

		for (int i=1; i<=m; i++) {
			for (int r=1; r<=n; r++) {
				dp[i][r] = dp[i][r-1];
				int e = 0;
				if (minL[r] != INF) {
					e = max(e, pm[i-1][minL[r]-1] + z[r] - z[minL[r] - 1]);
					e = max(e, gett(minL[r], r-1) + z[r]);
				}
				dp[i][r] = max(dp[i][r], e);
			}

			for (int r=1; r<=n; r++) {
				pm[i][r] = max(pm[i][r-1], dp[i][r]);
				sett(r, dp[i][r] - z[r]);
			}
		}

		/*
		cerr << "dp dump\n";
		cerr << x[mid] << '\n';
		for (int i=1; i<=m; i++) {
			for (int r=1; r<=n; r++)
				cerr << dp[i][r] << " ";
			cerr << '\n';
		}
		cerr << "end dp dump\n";
		*/
		

		int best = 0;
		for (int i=0; i<=m; i++)
			best = max(best, dp[i][n]);

		int ok = best >= k;

		// cerr << mid << ' ' << best << ' ' << ok << '\n';

		if (ok) {
			o = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	if (o == -1) {
		cout << "-1\n";
	} else {
		cout << x[o] << '\n';
	}


}